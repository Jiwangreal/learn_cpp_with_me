#include "Parser.h"
#include "Scanner.h"//��Ϊ��ʹ�õ�Scanner��һЩ�ӿڽ���ɨ��
#include "Node.h"
#include "Calc.h"

#include <cassert>
#include <iostream>

//���õĳ�ʼ��ֻ�ܲų�ʼ���б��н��г�ʼ��
Parser::Parser(Scanner& scanner, Calc& calc)
    : scanner_(scanner), tree_(0), calc_(calc), status_(STATUS_OK)
{

}

STATUS Parser::Parse()
{
    tree_ = Expr();//������󣬽��������ʽ��ֵ��tree_

    //���1+1=2��bug������һ��IsDone�����ж��Ƿ���ȫ����
    if (!scanner_.IsDone())
    {
        status_ = STATUS_ERROR;
    }

    return status_;
}

//�������ʽ:
Node* Parser::Expr()
{
    Node* node = Term();//���1+1=2��bug����������1
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
        //��ʱ�ı��ʽ��Expr ��= Term{ ( '+'| '-' ) Term}
        MultipleNode* multipleNode = New SumNode(node);//���1+1=2��bug�����Ű�1��ӵ�multipleNode����
        //�ӽڵ��ж����������ѭ��
        do
        {
            scanner_.Accept();
            Node* nextNode = Term();//���1+1=2��bug�����Ž�����һ��1
            multipleNode->AppendChild(nextNode, (token == TOKEN_PLUS));//���1+1=2��bug���ְ�����ӽ���
            token = scanner_.Token();//���µ�ǰɨ���״̬����������һ���ַ��Ǽӷ����Ǽ�����ֱ�������������ţ��Ͳ���SumNode���Ӵ���
                                    //���1+1=2��bug��Ȼ�������Ⱥţ�����ѭ���ˣ�����2û����ȫ����

        }while(token == TOKEN_PLUS || token == TOKEN_MINUS)
        node = multipleNode;
    }
  

    return node;//Expression is Term
}

//������
Node* Parser::Term()
{
    Node* node = Factor();
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
        //��ʱ�ı��ʽ��Expr ��= Factor{ ( '*'| '/' ) Factor}
        MultipleNode* multipleNode = New SumNode(node);
        //�ӽڵ��ж����������ѭ��
        do
        {
            scanner_.Accept();
            Node* nextNode = Factor();
            multipleNode->AppendChild(nextNode, (token == TOKEN_MULTIPLY));
            token = scanner_.Token();//���µ�ǰɨ���״̬����������һ���ַ��Ǽӷ����Ǽ�����ֱ�������������ţ��Ͳ���SumNode���Ӵ���

        }while(token == TOKEN_MULTIPLY || token == TOKEN_DIVIDE)
        node = multipleNode;
    }
    else if (token == TOKEN_ASSIGN) //��ܹ������Ⱥţ�����x=5,x���5�Ǳ��ʽ��x=y=5��x���y=5�Ǳ��ʽ
    {
        //Expr:=Term=Expr, :=����һ��BNFʽ�ı�﷨
        scanner_.Accept();
        Node* nodeRight = Expr();
        if (node->IsLvalue())
        {
            node = new AssignNode(node, nodeRight);//�����ǶԴ����ı����ڵ㣬���еĸ�ֵ����
        }
        else
        {
            status_ = STATUS_ERROR;
            std::cout<<"The left-hand side of an assignment must be a variable"<<std::endl;//��������ֵ�ڵ�
            //Todo �׳��쳣
        }
        
    }
    return node;//Expression is Factory
}

//������ʽ
Node* Parser::Factor()
{
    //or (Expression)
    Node* node = 0;
    EToken token = scanner_.Token();
    if (token == TOKEN_LPARENTHESIS) 
    {
        scanner_.Accept(); //accept '('
        node = Expr();//�Ƚ������ʽ���ұ�Ӧ���и�������
        if (scanner_ == TOKEN_RPARENTHESIS)
        {
            scanner_.Accept(); //accept ')'
        }
        else
        {
            status = STATUS_ERROR;
            //to do:�׳��쳣
            std::cout<<"missing parenthesis"<<std::endl;
            node = 0;
        }
    }
    else if (token == TOKEN_NUMBER)
    {
        node = new NumberNode(scanner_.Number());//�½�һ�����ֽڵ�
        scanner_.Accept();
    }
    else if(token == TOKEN_MINUS)
    {
        scanner_.Accept();//����һ�����ţ�Ŀ����ָ��ƫ�Ƶ���һ���ַ�������һ�εĽ�����׼��
        node = new UminusNode(Factor());//����һ���ӽڵ��ȥ������ӽڵ������ʽ
    }
    else if (token == TOKEN_IDENTIFIER)//������һ����ʶ��
    {
        std::string symbol = scanner_.GetSymbol();
        unsigned int id = calc_.FindSymbol(symbol);
        scanner_.Accept();

        //��ʶ�������Ǳ�����Ҳ�����Ǻ���
        //log10(),��ɨ��һ��log����һ����ʶ��������ɨ�赽һ�������ţ���ô������һ��������
        if (scanner_.Token() == TOKEN_LPARENTHESIS)
        {
            scanner_.Accept(); //accpet '(',//����һ��������
            node = Expr();//�����Ƿ���һ�����ʽ��eg��sqrt(4+5)
            if (scanner_.Token() == TOKEN_RPARENTHESIS)//accept ')'
            {
                scanner_.Accept(); //�Ƿ���һ�������ţ������������
                //�ҵ�һ�����ţ��ж����Ƿ���һ���Ϸ��ĺ���
                if (id != SymbolTable::IDNOTFOUND && calc_.isFunction(id))//������һ������symbol������һ�����������Һ����ں�������
                {
                    //��4+5��Ϊ���ĺ���
                    //GetFunction��ȡ����ָ�룬��������һ������
                    node = new FunctionNode(node, calc_.GetFunction(id));
                }
                else
                {
                    //�������ʶ�ĺ���
                    status_ = STATUS_ERROR;
                    std::cout<<"Unknown function"<<"\""<<symbol<<"\""<<std::endl;
                }
                
            }
            else
            {
                status_ = STATUS_ERROR;
                std::cout<<"Missing paraenthesis in a function call."<<std::endl;
            }
            
        }
        else
        {
            if (id == SymbolTable::IDNOTFOUND)
            {
                id = calc_.AddSymbol(symbol);
            }
            node = new VariableNode(id, calc_.GetStorage());//����һ�������ڵ�
        }
    }
    else
    {   
        status = STATUS_ERROR;
        //to do:�׳��쳣
        std::cout<<"Not a valid expression"<<std::endl;
        node = 0;
    }
    
    return node;
}


//ע�⣺��const�ĳ�Ա�����벻��const�ĳ�Ա�������Թ�������
double Parser::Calculate() const
{
    assert(tree_ != 0);//0,NULL����
    //����ʽ��ֵ��ʵ���Ͼ���������ڵ��ֵ
    return tree_->Calc();
}