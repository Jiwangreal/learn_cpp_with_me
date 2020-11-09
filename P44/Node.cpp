#include "Node.h"
#include <cmath.h>
#include <cassert>
#include <iostream>

//数字节点的计算方法就等于数字节点本身
double NumberNode::Calc() const
{
    return number_;
}
BinaryNode::~BinaryNode()
{
    delete left_;
    delete right_;
}

UnaryNode::~UnaryNode();
{
    delete child_;
}

// double AddNode::Calc() const
// {
//     //AddNode节点的值等于左计算节点得到的值+右计算节点得到的值
//     return left_->Calc() + right_->Calc();
// }

// double SubNode::Calc() const
// {
//     return left_->Calc() - right_->Calc();
// }

// double MultiplyNode::Calc() const
// {
//     return left_->Calc() * right_->Calc();
// }


// double AddNode::Calc() const
// {
//     double divisor = right_->Calc();
//     if (divisor != 0.0)
//         return left_->Calc() / divisor;
//     else
//     {
//         std::cout << "Error: Divisor by zero" <<std::endl;
//         return HUGE_VAL;
//     }
// }


double UnaryNode::Calc() const 
{
    //孩子节点前面加一个负号,对照改进类继承体系的图看更好理解
    return - child_->Calc();
}


MultipleNode::~MultipleNode()
{
    std::vector<Node*>::const_iterator it;
    for (it = children_.begin(); it != children_.end(); ++it)
    {
        //it实际上是Node*的指针的指针，它存放的类型是Node*，*it取出它里面存放的元素Node*
        delete *it;
    }
}

//把它的子节点计算一下，然后把它+起来
double SumNode::Calc() const
{
    double result = 0.0;
    std::vector<Node*>::const_iterator childIt = childs_.begin();
    std::vector<bool>::const_iterator positiveIt = positives_.begin();

    for (; childIt != childs_.end(); ++childIt, ++positive)
    {
        //实际上childs_和positives_的元素个数是一样的，childs_没有遍历到结尾，那么positives_也没有遍历到结尾
        assert(positiveIt != positives_.begin();
        double val = (*childIt)->Calc();//*childIt的类型是Node*
        if (*positiveIt)
            result + =val;
        else
            result -= val;
    }
    //childs_遍历到结尾，那么positives_也遍历到结尾
    assert(positiveIt == positives_.end());
    return result;
}

//把它的子节点计算一下，然后把它*起来
double ProductNode::Calc() const
{
    double result = 1.0;
    std::vector<Node*>::const_iterator childIt = childs_.begin();
    std::vector<bool>::const_iterator positiveIt = positives_.begin();

    for (; childIt != childs_.end(); ++childIt, ++positive)
    {
        //实际上childs_和positives_的元素个数是一样的，childs_没有遍历到结尾，那么positives_也没有遍历到结尾
        assert(positiveIt != positives_.begin();
        double val = (*childIt)->Calc();//*childIt的类型是Node*
        if (*positiveIt)
            result * =val;
        else if (val != 0.0)
            result /= val;
        else
        {
            std::cout<<"Division by zero"<<std::endl;
            return HUGE_VAL;
        }
    }
    //childs_遍历到结尾，那么positives_也遍历到结尾
    assert(positiveIt == positives_.end());
    return result;
}
