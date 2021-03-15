#ifndef _NODE_H
#define _NODE_H

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

// //BinaryNode节点有2个子节点
// //BinaryNode类没有实现Calc方法，BinaryNode类仍然是抽象类，只有它的派生类，加、减、乘、除节点才知道该如何计算
// class BinaryNode : public Node
// {
// public:
//     BinaryNode(Node* left, Node* right)
//         : left_(left), right_(right) {}
//     ~BinaryNode();//记得要释放left_和right_节点
// protected:
//     Node* const left_;//const的作用：指针不能改变（即指针不能指向其它的节点），而不是指针所指向的内容不能改变
//     Node* const right_;
// };

//传递一个函数对象。表示+-*/
template <typename T>
class BinaryNode : public Node
{
public:
    BinaryNode(Node* left, Node* right)
        : left_(left), right_(right) {}
    ~BinaryNode();//记得要释放left_和right_节点
    {
        delete left_;
        delete right_;
    }

    //实例化一个模板类的时候是一个具体类，要是先Calc方法
    double Calc() const
    {
        T op;
        return op(left_->Calc(), right_->Calc());
    }
protected:
    Node* const left_;//const的作用：指针不能改变（即指针不能指向其它的节点），而不是指针所指向的内容不能改变
    Node* const right_;
};


//与BinaryNode相比，它只有1个孩子
//UnaryNod也是抽象类，因为它没有实现Calc方法
class UnaryNode : public Node
{
public:
    UnaryNode(Node* child)
        : child_(child) {}
    ~UnaryNode();
protected:
    Node* child_;
}
/*
//加法运算节点AddNode
class AddNode : public BinaryNode
{
public:
//构造函数初始化，要调用基类部分的构造函数
    AddNode(Node* left, Node* right)
        : BinaryNode(left, right) {}
    //要实现Calc方法，AddNode类是具体类
    double Calc() const;
};

class SubNode : public BinaryNode
{
public:
    SubNode(Node* left, Node* right)
        : BinaryNode(left, right) {}
    double Calc() const;
};

class MultiplyNode : public BinaryNode
{
public:
    MultiplyNode(Node* left, Node* right)
        : BinaryNode(left, right) {}
    double Calc() const;
};

class DivideNode : public BinaryNode
{
public:
    DivideNode(Node* left, Node* right)
        : BinaryNode(left, right) {}
    double Calc() const;
};
*/

class UminusNode : public UnaryNode
{
public:
    UminusNode(Node* child)
        : UnaryNode(child) {}
    double Calc() const;
};



#endif/* _NODE_H */