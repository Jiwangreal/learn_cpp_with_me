#include "Node.h"
#include <cmath.h>
#include <iostream>

//数字节点的计算方法就等于数字节点本身
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
    //AddNode节点的值等于左计算节点得到的值+右计算节点得到的值
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
    //孩子节点前面加一个负号,对照改进类继承体系的图看更好理解
    return - child_->Calc();
}
