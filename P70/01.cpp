#include "Stack.h"
#include <iostream>
#include <vector>
using  namespace std;

int main(void)
{

    //Stack�ڲ������õ����ݽṹ��˫�˶���
    //Ĭ�ϲ���(ȱʡֵ)��deque<T>
    Stack<int> s;

    //����һ��vector������ֻҪ��push_back�Ƚӿھ��У���vector<int>������һ��ģ����
    //����û��Ҫȥ�̳�vector<int>��ʹ�����Ľӿڣ������������Ͳ��������ݡ��Ӷ�ʹ�����Ľӿ�c_.push_back(elem)���Ӷ�������½ӿ�Push(const T& elem)
    //��ʱclass Stack����һ��������������STL6�����֮һ
    //���ִ��븴�ã���ͨ���̳У�����ͨ�����䣬�����е��൱�����������ݣ�ʹ�ù������������Stack�����ࣩҲ����������Ĺ��ܣ���ʹ����ӿ�
    Stack< int, vector<int> > s;//��ģ����vector<int>�����������ݸ�һ����ģ��Stack

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