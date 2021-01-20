#ifndef _STACK2_H
#define _STACK2_H

#include <exception>

//Stack2��һ��ģ�壬������һ����
//typename T:��������Ϊ���������ݣ�typename T�����Ͳ���,int MAX_SIZE�Ƿ����Ͳ���

template <typename T, int MAX_SIZE>
class Stack2
{
public:
    //����һ��T���͵������ڴ�ռ�
    Stack2();
    ~Stack2();
    void Push(const T& elem);
    void Pop();
    T& Top();//����ջ��Ԫ�أ�����const˵�����Ըı�ջ�ڲ�������
    const T& Top() const;//����ջ��Ԫ�أ���const˵�����ܸı�ջ�ڲ�������
    bool Empty() const;//˵��ջ�Ƿ��ǿյ�
private:
    T* elems_;
    // int maxSize_;
    int top_;//��ǰ��ջ��λ��
};

//���ʵ�ֿ��Է�����˵�����ⲿ
//ÿ����Ա����������һ������ģ��
//Stack2<T, int MAX_SIZE>��ʾģ�壬Stack2�ǳ�Ա����
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
    //top+1������Ԫ�صĸ���
    if (top +1 >= MAX_SIZE)
        throw out_of_range(��Stack2<>::Push() stack full��);//out_of_range�Ǳ�׼����쳣
}


template <typename T, int MAX_SIZE>
void Stack2<T, int MAX_SIZE>::Pop(const T& elem)
{
    //top+1������Ԫ�صĸ���
    if (top +1 == 0)
        throw out_of_range(��Stack2<>::Pop() stack empty��);//out_of_range�Ǳ�׼����쳣

    --top_;
}

template <typename T, int MAX_SIZE>
T& Stack2<T, int MAX_SIZE>::Top()
{
    //top+1������Ԫ�صĸ���
    if (top +1 == 0)
        throw out_of_range(��Stack2<>::Top() stack empty��);//out_of_range�Ǳ�׼����쳣

    return elems_[top_];
}

template <typename T, int MAX_SIZE>
const T& Stack2<T, int MAX_SIZE>::Top() const
{
    //top+1������Ԫ�صĸ���
    if (top +1 == 0)
        throw out_of_range(��Stack2<>::Top() const stack empty��);//out_of_range�Ǳ�׼����쳣

    return elems_[top_];
}

template <typename T, int MAX_SIZE>
bool Stack2<T, int MAX_SIZE>::Empty() const
{
    return top_ + 1 == 0;
}

#endif //_STACK2_H