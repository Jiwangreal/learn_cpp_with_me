#ifndef _STACK_H
#define _STACK_H

#include <exception>

template <typename T>
class Stack
{
public:
    //����һ��T���͵������ڴ�ռ�
    Stack(int maxsize);
    ~Stack();
    void Push(const T& elem);
    void Pop();
    T& Top();//����ջ��Ԫ�أ�����const˵�����Ըı�ջ�ڲ�������
    const T& Top() const;//����ջ��Ԫ�أ���const˵�����ܸı�ջ�ڲ�������
    bool Empty() const;//˵��ջ�Ƿ��ǿյ�
private:
    T* elems_;
    int maxSize_;
    int top_;//��ǰ��ջ��λ��
};

//���ʵ�ֿ��Է�����˵�����ⲿ
//ÿ����Ա����������һ������ģ��
//Stack<T>��ʾģ�壬Stack�ǳ�Ա����
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
    //top+1������Ԫ�صĸ���
    if (top +1 >= maxSize_)
        throw out_of_range(��Stack<>::Push() stack full��);//out_of_range�Ǳ�׼����쳣
}


template <typename T>
void Stack<T>::Pop(const T& elem)
{
    //top+1������Ԫ�صĸ���
    if (top +1 == 0)
        throw out_of_range(��Stack<>::Pop() stack empty��);//out_of_range�Ǳ�׼����쳣

    --top_;
}

template <typename T>
T& Stack<T>::Top()
{
    //top+1������Ԫ�صĸ���
    if (top +1 == 0)
        throw out_of_range(��Stack<>::Top() stack empty��);//out_of_range�Ǳ�׼����쳣

    return elems_[top_];
}

template <typename T>
const T& Stack<T>::Top() const
{
    //top+1������Ԫ�صĸ���
    if (top +1 == 0)
        throw out_of_range(��Stack<>::Top() const stack empty��);//out_of_range�Ǳ�׼����쳣

    return elems_[top_];
}

template <typename T>
bool Stack<T>::Empty() const
{
    return top_ + 1 == 0;
}

#endif //_STACK_H