#ifndef _STACK_H
#define _STACK_H

#include <exception>
#include <deque>
using namespace std;

//deque��������һ��������
//deque<T>��ʾ�����ڲ���������T��deque<T>��һ��ģ����
template <typename T, typename CONT = deque<T> >//ע�������ҪҪ��һ���ո�
class Stack
{
public:
    //����һ��T���͵������ڴ�ռ�
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
        //ȡ���������һ��Ԫ��
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
    CONT c_;//���ݽṹ�������ݽ���������
    int top_;//��ǰ��ջ��λ��
};

#endif //_STACK_H