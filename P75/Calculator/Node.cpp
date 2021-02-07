
#include <cmath.h>
#include <cassert>
#include <iostream>
#include "Node.h"
#include "Storage.h"
#include "DebugNew.h"

//���ֽڵ�ļ��㷽���͵������ֽڵ㱾��
double NumberNode::Calc() const
{
    return number_;
}
BinaryNode::~BinaryNode()
{
    // delete left_;
    // delete right_;
}

UnaryNode::~UnaryNode();
{
    // delete child_;//ָ�������Ȩ�Ѿ�������ָ������ˣ�����Ͳ���Ҫdelete
}

// double AddNode::Calc() const
// {
//     //AddNode�ڵ��ֵ���������ڵ�õ���ֵ+�Ҽ���ڵ�õ���ֵ
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
double FunctionNode::Calc() const 
{
    //sqrt(4+5)�Ǻ����ڵ㣬4+5�������ӽڵ㡣�ӽڵ�����꣬Ҫ��һ������������
    //*pFun_�ǵ��õĺ�����ͨ������ָ����ָ��ĺ���������child_->Calc()
    return (*pFun_)(child_->Calc());
}


double UnaryNode::Calc() const 
{
    //���ӽڵ�ǰ���һ������,���ոĽ���̳���ϵ��ͼ���������
    return - child_->Calc();
}


MultipleNode::~MultipleNode()
{
    // std::vector<Node*>::const_iterator it;
    // for (it = children_.begin(); it != children_.end(); ++it)
    // {
    //     //itʵ������Node*��ָ���ָ�룬����ŵ�������Node*��*itȡ���������ŵ�Ԫ��Node*
    //     delete *it;
    // }
}

//�������ӽڵ����һ�£�Ȼ�����+����
double SumNode::Calc() const
{
    double result = 0.0;
    std::vector<Node*>::const_iterator childIt = childs_.begin();
    std::vector<bool>::const_iterator positiveIt = positives_.begin();

    for (; childIt != childs_.end(); ++childIt, ++positive)
    {
        //ʵ����childs_��positives_��Ԫ�ظ�����һ���ģ�childs_û�б�������β����ôpositives_Ҳû�б�������β
        assert(positiveIt != positives_.begin();
        double val = (*childIt)->Calc();//*childIt��������Node*
        if (*positiveIt)
            result + =val;
        else
            result -= val;
    }
    //childs_��������β����ôpositives_Ҳ��������β
    assert(positiveIt == positives_.end());
    return result;
}

//�������ӽڵ����һ�£�Ȼ�����*����
double ProductNode::Calc() const
{
    double result = 1.0;
    std::vector<Node*>::const_iterator childIt = childs_.begin();
    std::vector<bool>::const_iterator positiveIt = positives_.begin();

    for (; childIt != childs_.end(); ++childIt, ++positive)
    {
        //ʵ����childs_��positives_��Ԫ�ظ�����һ���ģ�childs_û�б�������β����ôpositives_Ҳû�б�������β
        assert(positiveIt != positives_.begin();
        double val = (*childIt)->Calc();//*childIt��������Node*
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
    //childs_��������β����ôpositives_Ҳ��������β
    assert(positiveIt == positives_.end());
    return result;
}


double VariableNode::Calc() const
{
    double x = 0.0;
    if (storage_.IsInit(id_))
    {
        x = storage_.GetValue(id_);
    }
    else
    {
        std::cout<<"Use of uninitialized variable"<<std::endl;
    }
    
    return x;
}

bool VariableNode::IsLvalue() const
{
    return true;
}

void VariableNode::Assign(double val)
{
    storage_.SetValue(id_, val)
}

double AssignNode::Calc() const
{
    //����ȡ���ҽڵ��ֵ
    double x = 0.0;
    x = right->Calc();
    left_->Assign(x);
}
