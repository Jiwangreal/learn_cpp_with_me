#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>

using  namespace std;

int main( void)
{
     //int a[] = {1, 2, 3, 4, 5};
     //vector<int> v(a, a+5);//初始化5个元素，list也可以这么用
    //queue<int> v(a, a+5);//error，queue的构造函数要么一个参数，要么0个参数，没有2个参数，stack一样

    //队列是先进先出
     queue< int> q;//默认采用deque，接口有pop_front()方法，容器能够从头部弹出
    // queue< int, list< int> > q;//good，接口有pop_front()方法，容器能够从头部弹出
    // queue< int, vector< int> > q;//error，没有pop_front()方法
     
    for ( int i =  0; i <  5; i++)
    {
        q.push(i);
    }

     while (!q.empty())
    {
        //打印队头元素
        cout << q.front() <<  ' ';
        q.pop();
    }

    cout << endl;

     return  0;
}
