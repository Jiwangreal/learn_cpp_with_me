#include <iostream>
#include <vector>
#include <list>
#include <stack>

using  namespace std;

int main( void)
{
    // stack<int> s;
    //ջ�Ǻ���ȳ�,ʹ��������ʵ��
    // stack< int, vector< int> > s;
    //������list������ʵ��
    //ֻҪ��Щ������push_back��pop_back����
    stack< int, list< int> > s;
    
    for ( int i =  0; i <  5; i++)
    {
        s.push(i);
    }

    //s.size()���޷��ŵ�
     //for (size_t i=0; i<s.size(); i++)
     //{
     //  cout<<s.top()<<' ';   Error:size()һֱ�ڱ仯��ÿ��popһ��Ԫ�أ�size()��ֵ�ͱ�С��
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