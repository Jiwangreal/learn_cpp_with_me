#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>

using  namespace std;

int main( void)
{
     //int a[] = {1, 2, 3, 4, 5};
     //vector<int> v(a, a+5);//��ʼ��5��Ԫ�أ�listҲ������ô��
    //queue<int> v(a, a+5);//error��queue�Ĺ��캯��Ҫôһ��������Ҫô0��������û��2��������stackһ��

    //�������Ƚ��ȳ�
     queue< int> q;//Ĭ�ϲ���deque���ӿ���pop_front()�����������ܹ���ͷ������
    // queue< int, list< int> > q;//good���ӿ���pop_front()�����������ܹ���ͷ������
    // queue< int, vector< int> > q;//error��û��pop_front()����
     
    for ( int i =  0; i <  5; i++)
    {
        q.push(i);
    }

     while (!q.empty())
    {
        //��ӡ��ͷԪ��
        cout << q.front() <<  ' ';
        q.pop();
    }

    cout << endl;

     return  0;
}
