#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

void print_element(int n)
{
    cout <<n<<' ';
}

void add_3(int& n)
{
    n += 3;
}

int fun(int n)
{
    return 2 * a;
}

int fun2(int a, int b)
{
    return a + b;
}

int main(void)
{
    //�����ڹ����ʱ����Բ����ݲ�����Ҳ���Դ���2�������������е����䶼����һ���տ�����[)
    //����STL���䶼�Ǳտ�����
    //endӦ��ָ��5�����λ�ã���ôbegin��ָ��1
    //a��a+5������������������ʵ�ֵķ�ʽ���࣬���ڲ�������int*�����Ա�����������int*
    int a[] = {1, 2, 3, 4, 5};
    vector<int> v(a, a+5);
    list<int> l(5);
    list<int> l2(2);

    //ԭ���䲻�䣬Ŀ��������
    transform(v.begin(), v.end(), l.begin(), fun);
    for_each(l.begin(), l.end(), print_element);
    cout<<endl;

    //��һ������Ԫ�أ�1��2
    //�ڶ�������Ԫ�أ�4��5
    transform(v.begin(), v.begin()+2 v.begin() + 3, l2.begin(), fun2);
    for_each(l.begin(), l.end(), print_element);
    cout<<endl;

    return 0;

}
