#include "Parser.h"
#include "Scanner.h"//��Ϊ��ʹ�õ�Scanner��һЩ�ӿڽ���ɨ��
#include "Node.h"

#include <cassert>
#include <iostream>
#include <functional>

//���õĳ�ʼ��ֻ�ܲų�ʼ���б��н��г�ʼ��
Parser::Parser(Scanner& scanner) : scanner_(scanner), tree_(0)
{

}

void Parser::Parse()
{
    tree_ = Expr();//������󣬽���������ʽ��ֵ��tree_
}

//��������ʽ:
Node* Parser::Expr()
{
    Node* node = Term();
    EToken token = scanner_.Token();
    if (token == TOKEN_PLUS)//ɨ�赽+
    {
        scanner_.Accept();//accept+�ţ�ɨ����һ���ַ��������ǲ���һ��Expression
        Node* nodeRight = Expr();
        // node = new AddNode(node, nodeRight);//���ص��Ǽӷ��ڵ㣬����ڵ㣬�ҽڵ㣩��Expression is Term + Expression
        node = new BinaryNode<std::plus<double> >(node, nodeRight);//std::plus<double>��һ��ģ����
    }
    else if (token == TOKEN_MINUS)
    {
        scanner_.Accept();
        Node* nodeRight = Expr();
        // node = new SubNode(node, nodeRight);//Expression is Term - Expression
        node = new BinaryNode<std::minus<double> >(node, nodeRight);
    }

    return node;//Expression is Term
}

//������
Node* Parser::Term()
{
    Node* node = Factor();
    EToken token = scanner_.Token();
    if (token == TOKEN_MULTIPLY)
    {
        scanner_.Accept();
        Node* nodeRight = Term();
        // node = new MultiplyNode(node, nodeRight);//Term is Factory * Term
        node = new BinaryNode<std::multiplies<double> >(node, nodeRight);
    }
    else if (token == TOKEN_DIVIDE)
    {
        scanner_.Accept();
        Node* nodeRight = Term();
        // node = new DivideNode(node, nodeRight);//Term is Factory / Term
        node = new BinaryNode<std::divides<double> >(node, nodeRight);
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
        node = Expr();//�Ƚ�������ʽ���ұ�Ӧ���и�������
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
    //�����ʽ��ֵ��ʵ���Ͼ���������ڵ��ֵ
    return tree_->Calc();
}