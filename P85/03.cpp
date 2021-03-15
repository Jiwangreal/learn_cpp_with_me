#include <iostream>
#include <functional>
#include <vector>
#include <list>
#include <stack>
#include <queue>

using  namespace std;

int main( void)
{
     int a[] = { 5,  1,  2,  4,  3};
     priority_queue<int> a(a, a+5);
     //greater是函数对象，从小到大，值越小，优先级越大
    // priority_queue< int, vector< int>, greater< int> > q(a, a +  5);

    while (!q.empty())
    {
        //默认是按照从大到小弹出的，值越大，优先级越大
        cout << q.top() <<  ' ';//先把第一个元素输出
        q.pop();//再弹出
    }

    cout << endl;

     return  0;
}
