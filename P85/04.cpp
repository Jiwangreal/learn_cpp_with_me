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
    //Ĭ�Ϲ�������һ������
    //�������һ����ȫ�������������������棬��������һ�����Ƕ����������Ƕ�����Ӧ�����
    //���ѣ����ױ��������⺢�Ӷ�Ҫ��
    //��С�ѣ����ױ��������⺢�Ӷ�ҪС
    make_heap(a, a +  5);//Ĭ���Ǵ��

    // make_heap(a, a +  5, less< int>());���
    // make_heap(a, a +  5, greater< int>());С��

    //����������������������
    copy(a, a +  5, ostream_iterator< int>(cout,  " "));
    cout << endl;

     return  0;
}
