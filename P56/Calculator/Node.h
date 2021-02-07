#ifndef _NODE_H
#define _NODE_H

#include <cassert>
#include <memory>
#include <vector>
#include "FunctionTable.h"

class Storage;

//（1）【采用】禁止对象拷贝的eg演示
//Noncopyable不能构造对象，因为构造对象没意义，仅仅用来继承
class Noncopyable
{
protected:
    Noncopyable() {};
    ~Noncopyable() {};
private:
    Noncopyable(const Noncopyable&);
    const Noncopyable& operator=(const Noncopyable&);
};

//用private继承的原因是：并没有继承Noncopyable类的接口，即：这不是接口继承，而是实现继承
//实现继承：仅仅利用基类的内部函数，仅仅能在派生类的内部使用，并不能成为派生类额接口
//Node变成了对象语义，因为：要构造Node，要先构造Noncopyable，而Noncopyable既不能拷贝构造，也不能赋值了
class Node : private Noncopyable
{
public:
    //每个节点都有一个计算的纯虚函数
    //类Node用于多态，派生类都要实现Calc
    //Calc声明为const的，因为Calc不会改变类的成员
    virtual double Calc() const = 0;
    //类Node是多态类，析构函数也要声明为虚析构函数，否则基类指针指向派生类对象，
    //通过基类指针释放对象的时候，是不会调用派生类的析构函数

    //默认节点都不是左值,只有变量节点是左值
    virtual bool IsLvalue() const
    {
        return false;
    }
    
    //只有变量节点有赋值的方法，其他节点都没有
    virtual void Assign(double)
    {
        assert(!"Assign called incorrectlly");//“XX”字符串是真的，取一个！为假的，默认情况下断言为假的
    }
    
    virtual ~Node() {};
};

//NumerNode要实现这个纯虚函数Calc，为具体类；若没实现，还是抽象类
class NumberNode : public Node
{
public:
    NumberNode(double number) : number_(number) {}
    double Calc() const;
private:
    const double number_;//加const的原因：因为number_初始化后就不会改变
};

//BinaryNode节点有2个子节点
//BinaryNode类没有实现Calc方法，BinaryNode类仍然是抽象类，只有它的派生类，加、减、乘、除节点才知道该如何计算
//当前内存泄漏的本质原因不是没有~BinaryNode析构函数，而是BinaryNode本身没办法释放，导致析构函数没办法释放，导致其所持有的指针没法释放
class BinaryNode : public Node
{
public:
    BinaryNode(std::auto_ptr<Node>& left, std::auto_ptr<Node> right)//参数传递最好用引用，这样就少一次智能指针本身的拷贝构造
        : left_(left), right_(right) {}
    ~BinaryNode();//记得要释放left_和right_节点
protected:
    // Node* const left_;//const的作用：指针不能改变（即指针不能指向其它的节点），而不是指针所指向的内容不能改变
    // Node* const right_;
    //原生指针支持的所有语法，智能指针都支持：什么->,*运算符，=等算符等
    std::auto_ptr<Node> left_;//所有权转移到了智能指针，所以不需要析构函数去delete
    std::auto_ptr<Node> right_;
    
};

//与BinaryNode相比，它只有1个孩子
//UnaryNod也是抽象类，因为它没有实现Calc方法
class UnaryNode : public Node
{
public:
    UnaryNode(std::auto_ptr<Node>& child)
        : child_(child) {}
    ~UnaryNode();
protected:
    // Node* const child_;
    std::auto_ptr<Node> child_;
}


class FunctionNode : public UnaryNode
{
public://有一个子节点，还有一个函数节点
    FunctionNode(std::auto_ptr<Node>&  child, PtrFun pFun) : UnaryNode(child), pFun_(pFun) {}
    double Calc() const;
private:
    PtrFun pFun_;//函数指针
};
//函数节点的计算方法

// //加法运算节点AddNode
// class AddNode : public BinaryNode
// {
// public:
// //构造函数初始化，要调用基类部分的构造函数
//     AddNode(Node* left, Node* right)
//         : BinaryNode(left, right) {}
//     //要实现Calc方法，AddNode类是具体类
//     double Calc() const;
// };

// class SubNode : public BinaryNode
// {
// public:
//     SubNode(Node* left, Node* right)
//         : BinaryNode(left, right) {}
//     double Calc() const;
// };

// class MultiplyNode : public BinaryNode
// {
// public:
//     MultiplyNode(Node* left, Node* right)
//         : BinaryNode(left, right) {}
//     double Calc() const;
// };

// class DivideNode : public BinaryNode
// {
// public:
//     DivideNode(Node* left, Node* right)
//         : BinaryNode(left, right) {}
//     double Calc() const;
// };

class UminusNode : public UnaryNode
{
public:
    UminusNode(std::auto_ptr<Node> & child)
        : UnaryNode(child) {}
    double Calc() const;
};

//MultiplyNode没有实现Calc方法，还是一个抽象类
class MultipleNode : public Node
{
public:
    MultipleNode(std::auto_ptr<Node>& node)
    {
        //添加第一个节点。第一个节点总是正的，比如-7-5+1，该-7就是第一个节点，在解析的时候它已经不是NumberNode
        //它应该是UminusNode，它里面已经能够处理负号了，应该把它当成是正的（+）-7
        AppendChild(node, true);
    }
    void AppendChild(std::auto_ptr<Node>& node, bool positive)
    {
        childs_.push_back(node.release());//元素类型是Node*,不能放入智能指针，而应该放入原生指针:释放所有权后传进容器中
        positive_.push_back(positive);
    }
    ~MultipleNode();
private:
    //有很多子代，将其放入向量中
    std::vector<Node*> childs_;//vector里面存放的是Node*
    std::vector<bool> positive_;//节点的正负性
};

class SumNode : public : MultipleNode
{
public:
    SumNode(std::auto_ptr<Node>& node)
        : MultipleNode(node) {}
    double Calc() const;
};

//乘积节点
class ProductNode : public : MultipleNode
{
public:
    SumNode(std::auto_ptr<Node>& node)
        : MultipleNode(node) {}
    double Calc() const;
};


class VariableNode: public Node
{
public:
    VariableNode(unsigned int id, Storage& storage)
        : id_(id), storage_(storage) {}
    double Calc() const;
    bool IsLvalue() const;
    void Assign(double val);
private:
    const unsigned int id_;
    Storage& storage_;//变量节点的值从Storage类中获取，Storage类中存储了某个变量的值，所以需要Storage类的一个引用
};

class AssignNode : public BinaryNode
{
public:
//构造函数初始化，要调用基类部分的构造函数
    AssignNode(std::auto_ptr<Node>& left, std::auto_ptr<Node>& right)
        : BinaryNode(left, right) 
        {
           assert(left->IsLvalue());//断言是一个左值节点，能够被赋值的 
        }
    //要实现Calc方法
    double Calc() const;
};


#endif/* _NODE_H */