#include <iostream>
#include <vector>
#include <list>
#include <stack>

using  namespace std;

int main( void)
{
    // stack<int> s;
    //栈是后进先出,使用向量来实现
    // stack< int, vector< int> > s;
    //可以用list链表来实现
    //只要这些容器有push_back，pop_back就行
    stack< int, list< int> > s;
    
    for ( int i =  0; i <  5; i++)
    {
        s.push(i);
    }

    //s.size()是无符号的
     //for (size_t i=0; i<s.size(); i++)
     //{
     //  cout<<s.top()<<' ';   Error:size()一直在变化，每当pop一个元素，size()的值就变小了
     //  s.pop();
     //}

    while (!s.empty())
    {
        cout << s.top() <<  ' ';
        s.pop();
    }
    cout << endl;
     return  0;
}