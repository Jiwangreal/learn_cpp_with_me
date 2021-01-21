#ifndef _STACK_H
#define _STACK_H

#include <exception>
#include <deque>
using namespace std;

//deque是与向量一样的容器
//deque<T>表示容器内部的类型是T，deque<T>是一个模板类
template <typename T, typename CONT = deque<T> >//注意这里必要要有一个空格
class Stack
{
public:
    //分配一个T类型的连续内存空间
    Stack() :c_()
    {

    }
    ~Stack()
    {
    
    }
    void Push(const T& elem)
    {
        c_.push_back(elem);
    }
    void Pop()
    {
        //取出容器最后一个元素
        c_.pop_back();
    }
    T& Top()
    {
        return c_.top();
    }
    bool Empty() const
    {
        return c_.empty();
    }
private:
    CONT c_;//数据结构是所传递进来的容器
    int top_;//当前的栈顶位置
};

#endif //_STACK_H