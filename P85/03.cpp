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
     //greater�Ǻ������󣬴�С����ֵԽС�����ȼ�Խ��
    // priority_queue< int, vector< int>, greater< int> > q(a, a +  5);

    while (!q.empty())
    {
        //Ĭ���ǰ��մӴ�С�����ģ�ֵԽ�����ȼ�Խ��
        cout << q.top() <<  ' ';//�Ȱѵ�һ��Ԫ�����
        q.pop();//�ٵ���
    }

    cout << endl;

     return  0;
}
