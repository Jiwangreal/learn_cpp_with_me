
#include <cstring>
#include <cassert>
#include <iostream>
#include <sstream>
#include "Parser.h"
#include "Scanner.h"//��Ϊ��ʹ�õ�Scanner��һЩ�ӿڽ���ɨ��
#include "Node.h"
#include "Calc.h"
#include "Exception.h"
#include "DebugNew.h"

//���õĳ�ʼ��ֻ�ܲų�ʼ���б��н��г�ʼ��
Parser::Parser(Scanner& scanner, Calc& calc)
    : scanner_(scanner), tree_(0), calc_(calc), status_(STATUS_OK)
{

}

/*
Ϊʲô����������д�����
��Ϊ�����ʱ����һ�����棺ɾ��ָ������Node���͵�ָ�룬û�е�����������
��Ϊtree_��Node���ͣ�delete�����Node����������������Node��������ǰ���������������������������������Ա���Ĺ������о���
����취��
��1����Parser.h�а���Node.h
��2��������������ʵ�ַŵ�cpp�ļ���
*/
//�澯�Ľ���취
Parser::~Parser()
{
    // delete tree_;//���tree_�ǿ�ָ�룬�򲻻����void operator delete(void*p)
}

STATUS Parser::Parse()
{
    tree_ = Expr();//������󣬽���������ʽ��ֵ��tree_

    //���1+1=2��bug������һ��IsDone�����ж��Ƿ���ȫ����
    if (!scanner_.IsDone())
    {
        status_ = STATUS_ERROR;
    }

    return status_;
}

//��������ʽ:
std::auto_ptr<Node> Parser::Expr()
{
    //Term()����һ������ָ�룬��ֵ��node������Ȩ��ת�Ƶ���node��Term()����һ������ָ�������е���Դ�ͽ���node����������
    //����Ȩת�Ƶ�node
    std::auto_ptr<Node> node = Term();//���1+1=2��bug����������1
    EToken token = scanner_.Token();
    // if (token == TOKEN_PLUS)//ɨ�赽+
    // {
    //     scanner_.Accept();//accept+�ţ�ɨ����һ���ַ��������ǲ���һ��Expression
    //     Node* nodeRight = Expr();
    //     node = new AddNode(node, nodeRight);//���ص��Ǽӷ��ڵ㣬����ڵ㣬�ҽڵ㣩��Expression is Term + Expression
    // }
    // else if (token == TOKEN_MINUS)
    // {
    //     scanner_.Accept();
    //     Node* nodeRight = Expr();
    //     node = new SubNode(node, nodeRight);//Expression is Term - Expression
    // }
    if (token == TOKEN_PLUS || token == TOKEN_MINUS)
    {
        //�ڴ�й©��multipleNode��һ���ֲ�������SumNode�����ǲ����ͷŵģ��������ڴ�й©
        //��ʱ�ı���ʽ��Expr ��= Term{ ( '+'| '-' ) Term}
        //ʹ������ָ�����ѧ���ǣ�һ������ԭ��ָ�룬��������ָ�����������������Ҫʹ��ԭ��ָ�룬ԭ��ָ����ͷŲ����Զ���
        //��ջչ���Ĺ����У��ڶ�ɽ������ڴ�multipleNode�ǲ����Զ��ͷŵģ�������ָ�����������
        //����ָ�뱾����һ���������ջչ���Ĺ����л�������������������������ͷ�����е���Դ
        // MultipleNode* multipleNode = New SumNode(node);//���1+1=2��bug�����Ű�1���ӵ�multipleNode����
        std::auto_ptr<multipleNode> multipleNode(new SumNode(node));
        //�ӽڵ��ж����������ѭ��
        do
        {
            scanner_.Accept();
            std::auto_ptr<Node> nextNode = Term();//���1+1=2��bug�����Ž�����һ��1
            multipleNode->AppendChild(nextNode, (token == TOKEN_PLUS));//���1+1=2��bug���ְ������ӽ���
            token = scanner_.Token();//���µ�ǰɨ���״̬����������һ���ַ��Ǽӷ����Ǽ�����ֱ�������������ţ��Ͳ���SumNode���Ӵ���
                                    //���1+1=2��bug��Ȼ�������Ⱥţ�����ѭ���ˣ�����2û����ȫ����

        }while(token == TOKEN_PLUS || token == TOKEN_MINUS)
        node = multipleNode;
    }
  

    return node;//Expression is Term
}

//������
std::auto_ptr<Node> Parser::Term()
{
    std::auto_ptr<Node> node = Factor();
    EToken token = scanner_.Token();
    // if (token == TOKEN_MULTIPLY)
    // {
    //     scanner_.Accept();
    //     Node* nodeRight = Term();
    //     node = new MultiplyNode(node, nodeRight);//Term is Factory * Term
    // }
    // else if (token == TOKEN_DIVIDE)
    // {
    //     scanner_.Accept();
    //     Node* nodeRight = Term();
    //     node = new DivideNode(node, nodeRight);//Term is Factory / Term
    // }

    if (token == TOKEN_MULTIPLY || token == TOKEN_DIVIDE)
    {
        //��ʱ�ı���ʽ��Expr ��= Factor{ ( '*'| '/' ) Factor}
        // MultipleNode* multipleNode = New ProductNode(node);
        std::auto_ptr<multipleNode> multipleNode(new ProductNode(node));
        //�ӽڵ��ж����������ѭ��
        do
        {
            scanner_.Accept();
            std::auto_ptr<multipleNode> nextNode = Factor();
            multipleNode->AppendChild(nextNode, (token == TOKEN_MULTIPLY));
            token = scanner_.Token();//���µ�ǰɨ���״̬����������һ���ַ��Ǽӷ����Ǽ�����ֱ�������������ţ��Ͳ���SumNode���Ӵ���

        }while(token == TOKEN_MULTIPLY || token == TOKEN_DIVIDE)
        node = multipleNode;
    }
    else if (token == TOKEN_ASSIGN) //��ܹ������Ⱥţ�����x=5,x���5�Ǳ���ʽ��x=y=5��x���y=5�Ǳ���ʽ
    {
        //Expr:=Term=Expr, :=����һ��BNFʽ�ı��﷨
        scanner_.Accept();
        std::auto_ptr<Node> nodeRight = Expr();
        if (node->IsLvalue())
        {
            //new AssignNode(node, nodeRight)��ԭ��ָ�룬����Ȩת�Ƶ���std::auto_ptr<Node>����ָ�����
            //����ָ���ڸ�ֵ��ʱ�򣬿���Ȩ��ת�Ƹ���node
            node = std::auto_ptr<Node>(new AssignNode(node, nodeRight));//�����ǶԴ����ı����ڵ㣬���еĸ�ֵ����
        }
        else
        {
            status_ = STATUS_ERROR;
            // std::cout<<"The left-hand side of an assignment must be a variable"<<std::endl;//��������ֵ�ڵ�
            //Todo �׳��쳣
            throw SyntaxError("The left-hand side of an assignment must be a variable");
        }
        
    }
    return node;//Expression is Factory
}

//������ʽ
std::auto_ptr<Node> Parser::Factor()
{
    //or (Expression)
    std::auto_ptr<Node> node;//����ָ�벻��д=0
    EToken token = scanner_.Token();
    if (token == TOKEN_LPARENTHESIS) //���������ţ�˵����һ����ʽ
    {
        scanner_.Accept(); //accept '('
        node = Expr();//�Ƚ�������ʽ���ж����Ƿ���һ����ұ�Ӧ���и�������
        if (scanner_ == TOKEN_RPARENTHESIS)
        {
            scanner_.Accept(); //accept ')'
        }
        else
        {
            status = STATUS_ERROR;
            //to do:�׳��쳣
            // std::cout<<"missing parenthesis"<<std::endl;
            throw SyntaxError("Missing parenthesis");
            // node = 0;//����ָ�벻��д=0
        }
    }
    else if (token == TOKEN_NUMBER)
    {
        //�ڴ�й©���ֵ�λ�ã�new��һ��NumberNode������û��ȥdelete���node
        //��Ϊnode�Ǿֲ�������ָ�룬������������ص�ʱ���޷��õ�nodeָ�룬û�а취ȥdelete����û�취ȥ�ͷ����������������ڴ�й©
        node = std::auto_ptr<Node>(new NumberNode(scanner_.Number()));//�½�һ�����ֽڵ�
        scanner_.Accept();
    }
    else if(token == TOKEN_MINUS)
    {
        scanner_.Accept();//����һ�����ţ�Ŀ����ָ��ƫ�Ƶ���һ���ַ�������һ�εĽ�����׼��

        //�ڴ�й©��new�ĵط�û�е���delete
        node = std::auto_ptr<Node>(new UminusNode(Factor()));//����һ���ӽڵ��ȥ������ӽڵ������ʽ
    }
    else if (token == TOKEN_IDENTIFIER)//������һ����ʶ��
    {
        std::string symbol = scanner_.GetSymbol();
        unsigned int id = calc_.FindSymbol(symbol);
        scanner_.Accept();

        //��ʶ�������Ǳ�����Ҳ�����Ǻ���
        //log10(),��ɨ��һ��log����һ����ʶ��������ɨ�赽һ�������ţ���ô������һ��������
        if (scanner_.Token() == TOKEN_LPARENTHESIS)//function call
        {
            scanner_.Accept(); //accpet '(',//����һ��������
            node = Expr();//�����Ƿ���һ������ʽ��eg��sqrt(4+5)
            if (scanner_.Token() == TOKEN_RPARENTHESIS)//accept ')'
            {
                scanner_.Accept(); //�Ƿ���һ�������ţ������������
                //�ҵ�һ�����ţ��ж����Ƿ���һ���Ϸ��ĺ���
                if (id != SymbolTable::INNOTFOUND && calc_.isFunction(id))//������һ������symbol������һ�����������Һ����ں�������
                {
                    //��4+5��Ϊ���ĺ���
                    //GetFunction��ȡ����ָ�룬��������һ������
                    node = std::auto_ptr<Node>(new FunctionNode(node, calc_.GetFunction(id)));
                }
                else
                {
                    //�������ʶ�ĺ���
                    status_ = STATUS_ERROR;
                    // std::cout<<"Unknown function"<<"\""<<symbol<<"\""<<std::endl;
                    char buf[256] = {0};
                    // sprintf(buf, "Unknow function \" %s \".", symbol.c_str());//symbol��string���ͣ�symbol.c_str()��char*����
                    // throw SyntaxError(buf);
                   
                    ostringstream oss;
                    std::oss<<"Unknow function \"<<symbol<<"\"."; //�Ѿ���ʽ�����ַ���������Ļ���������
                    throw SyntaxError(oss.str());//oss.str()���ص�������string����
                }
                
            }
            else
            {
                status_ = STATUS_ERROR;
                // std::cout<<"Missing paraenthesis in a function call."<<std::endl;
                throw SyntaxError("Missing paraenthesis in a function call.");
            }
            
        }
        else
        {
            if (id == SymbolTable::INNOTFOUND)
            {
                id = calc_.AddSymbol(symbol);
            }
            node = std::auto_ptr<Node>(new VariableNode(id, calc_.GetStorage()));//����һ�������ڵ�
        }
    }
    else
    {   
        status = STATUS_ERROR;
        //to do:�׳��쳣
        // std::cout<<"Not a valid expression"<<std::endl;
        throw SyntaxError("Not a valid expression");
        // node = 0;
    }
        
    return node;
}


//ע�⣺��const�ĳ�Ա�����벻��const�ĳ�Ա�������Թ�������
double Parser::Calculate() const
{
    //����ָ�벻����0�Ƚϣ�get������ȡ��ԭ��ָ����0���ԱȽ�
    assert(tree_.get() != 0);//0,NULL����
    //�����ʽ��ֵ��ʵ���Ͼ���������ڵ��ֵ
    return tree_->Calc();
}