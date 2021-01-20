#ifndef _STACK2_H
#define _STACK2_H

#include <exception>

//Stack2是一个模板，并不是一个类
//typename T:将类型作为参数来传递，typename T是类型参数,int MAX_SIZE是非类型参数

template <typename T, int MAX_SIZE>
class Stack2
{
public:
    //分配一个T类型的连续内存空间
    Stack2();
    ~Stack2();
    void Push(const T& elem);
    void Pop();
    T& Top();//返回栈顶元素，不带const说明可以改变栈内部的数据
    const T& Top() const;//返回栈顶元素，带const说明不能改变栈内部的数据
    bool Empty() const;//说明栈是否是空的
private:
    T* elems_;
    // int maxSize_;
    int top_;//当前的栈顶位置
};

//类的实现可以放在类说明的外部
//每个成员函数看成是一个函数模板
//Stack2<T, int MAX_SIZE>表示模板，Stack2是成员函数
template <typename T, int MAX_SIZE>
Stack2<T, int MAX_SIZE>::Stack2() : top_(-1)
{
    elems_ = new T[MAX_SIZE];
}

template <typename T, int MAX_SIZE>
Stack2<T, int MAX_SIZE>::~Stack2()
{
    delete[] elems_;
}

template <typename T, int MAX_SIZE>
void Stack2<T, int MAX_SIZE>::Push(const T& elem)
{
    //top+1才是是元素的个数
    if (top +1 >= MAX_SIZE)
        throw out_of_range(“Stack2<>::Push() stack full”);//out_of_range是标准库的异常
}


template <typename T, int MAX_SIZE>
void Stack2<T, int MAX_SIZE>::Pop(const T& elem)
{
    //top+1才是是元素的个数
    if (top +1 == 0)
        throw out_of_range(“Stack2<>::Pop() stack empty”);//out_of_range是标准库的异常

    --top_;
}

template <typename T, int MAX_SIZE>
T& Stack2<T, int MAX_SIZE>::Top()
{
    //top+1才是是元素的个数
    if (top +1 == 0)
        throw out_of_range(“Stack2<>::Top() stack empty”);//out_of_range是标准库的异常

    return elems_[top_];
}

template <typename T, int MAX_SIZE>
const T& Stack2<T, int MAX_SIZE>::Top() const
{
    //top+1才是是元素的个数
    if (top +1 == 0)
        throw out_of_range(“Stack2<>::Top() const stack empty”);//out_of_range是标准库的异常

    return elems_[top_];
}

template <typename T, int MAX_SIZE>
bool Stack2<T, int MAX_SIZE>::Empty() const
{
    return top_ + 1 == 0;
}

#endif //_STACK2_H