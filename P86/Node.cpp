#include "Node.h"
#include <cmath.h>
#include <iostream>

//���ֽڵ�ļ��㷽���͵������ֽڵ㱾��
double NumberNode::Calc() const
{
    return number_;
}
// BinaryNode::~BinaryNode()
// {
//     delete left_;
//     delete right_;
// }

UnaryNode::~UnaryNode();
{
    delete child_;
}

/*
double AddNode::Calc() const
{
    //AddNode�ڵ��ֵ���������ڵ�õ���ֵ+�Ҽ���ڵ�õ���ֵ
    return left_->Calc() + right_->Calc();
}

double SubNode::Calc() const
{
    return left_->Calc() - right_->Calc();
}

double MultiplyNode::Calc() const
{
    return left_->Calc() * right_->Calc();
}


double AddNode::Calc() const
{
    double divisor = right_->Calc();
    if (divisor != 0.0)
        return left_->Calc() / divisor;
    else
    {
        std::cout << "Error: Divisor by zero" <<std::endl;
        return HUGE_VAL;
    }
}
*/

double UnaryNode::Calc() const 
{
    //���ӽڵ�ǰ���һ������,���ոĽ���̳���ϵ��ͼ���������
    return - child_->Calc();
}
