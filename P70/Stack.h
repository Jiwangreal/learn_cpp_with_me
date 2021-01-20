#ifndef _STACK_H
#define _STACK_H

#include <exception>
#include <deque>
using namespace std;

//deque��������һ��������
//deque<T>��ʾ�����ڲ���������T��deque<T>��һ��ģ����
template <typename T, typename CONT = deque<T> >
class Stack
{
public:
    //����һ��T���͵������ڴ�ռ�
    Stack();
    ~Stack();
    void Push(const T& elem)
    {
        c_.push_back(elem);
    }
    void Pop()
    {
        c_.pop();
    }
    T& Top()
    {
        return c_.top();
    }
    const T& Top() const;
    bool Empty() const;/
private:
    CONT c_;//���ݽṹ�������ݽ���������
    int top_;//��ǰ��ջ��λ��
};

#endif //_STACK_H