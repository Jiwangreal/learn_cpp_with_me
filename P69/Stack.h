#ifndef _STACK_H
#define _STACK_H

#include <exception>

template <typename T>
class Stack
{
public:
    //分配一个T类型的连续内存空间
    Stack(int maxsize);
    ~Stack();
    void Push(const T& elem);
    void Pop();
    T& Top();//返回栈顶元素，不带const说明可以改变栈内部的数据
    const T& Top() const;//返回栈顶元素，带const说明不能改变栈内部的数据
    bool Empty() const;//说明栈是否是空的
private:
    T* elems_;
    int maxSize_;
    int top_;//当前的栈顶位置
};

//类的实现可以放在类说明的外部
//每个成员函数看成是一个函数模板
//Stack<T>表示模板，Stack是成员函数
template <typename T>
Stack<T>::Stack(int maxsize) : maxSize_(maxsize), top_(-1)
{
    elems_ = new T[maxsize];
}

template <typename T>
Stack<T>::~Stack()
{
    delete[] elems_;
}

template <typename T>
void Stack<T>::Push(const T& elem)
{
    //top+1才是是元素的个数
    if (top +1 >= maxSize_)
        throw out_of_range(“Stack<>::Push() stack full”);//out_of_range是标准库的异常
}


template <typename T>
void Stack<T>::Pop(const T& elem)
{
    //top+1才是是元素的个数
    if (top +1 == 0)
        throw out_of_range(“Stack<>::Pop() stack empty”);//out_of_range是标准库的异常

    --top_;
}

template <typename T>
T& Stack<T>::Top()
{
    //top+1才是是元素的个数
    if (top +1 == 0)
        throw out_of_range(“Stack<>::Top() stack empty”);//out_of_range是标准库的异常

    return elems_[top_];
}

template <typename T>
const T& Stack<T>::Top() const
{
    //top+1才是是元素的个数
    if (top +1 == 0)
        throw out_of_range(“Stack<>::Top() const stack empty”);//out_of_range是标准库的异常

    return elems_[top_];
}

template <typename T>
bool Stack<T>::Empty() const
{
    return top_ + 1 == 0;
}

#endif //_STACK_H