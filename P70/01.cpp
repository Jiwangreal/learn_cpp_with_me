#include "Stack.h"
#include <iostream>
#include <vector>
using  namespace std;

int main(void)
{

    //Stack内部所采用的数据结构是双端队列
    //默认参数(缺省值)是deque<T>
    Stack<int> s;

    //传递一个vector容器（只要有push_back等接口就行），vector<int>本质是一个模板类
    //我们没必要去继承vector<int>来使用它的接口，把它当作类型参数来传递。从而使用它的接口c_.push_back(elem)，从而适配出新接口Push(const T& elem)
    //此时class Stack就是一个适配器，这是STL6大组件之一
    //这种代码复用，不通过继承，而是通过适配，当现有的类当作参数来传递，使得构造出的适配器Stack（新类）也具有现有类的功能，能使用其接口
    Stack< int, vector<int> > s;//将模板类vector<int>当作参数传递给一个类模板Stack

    s.Push(1);
    s.Push(2);
    s.Push(3);

    while (!s.Empty())
    {
        cout<<s.Top()<<endl;
        s.Pop();
    }

    return 0;
}