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

int main(void)
{
    //�����ڹ����ʱ����Բ����ݲ�����Ҳ���Դ���2�������������е����䶼����һ���տ�����[)
    //����STL���䶼�Ǳտ�����
    //endӦ��ָ��5�����λ�ã���ôbegin��ָ��1
    //a��a+5������������������ʵ�ֵķ�ʽ���࣬���ڲ�������int*�����Ա�����������int*
    int a[] = {1, 2, 3, 4, 5};
    vector<int> v(a, a+5);
    list<int> l(10);//list<int> l;����copyҪ��Ŀ��Ŀռ��Ѿ�����

    //ʹ���㷨
    for_each(v.begin(), v.end(), print_element);
    cout<<endl;

    //for_each�Ǳ䶯�Ի��ǷǱ䶯���㷨��ȡ���ڵ�3���������Ƿ���������е�Ԫ��
    for_each(v.begin(), v.end(), add_3);

    for_each(v.begin(), v.end(), print_element);
    cout<<endl;

    for_each(l.begin(), l.end(), print_element);
    cout<<endl;

    //copyҪ��Ŀ��Ŀռ��Ѿ�����
    copy(v.begin(),v.end(), l.begin());
    for_each(l.begin(), l.end(), print_element);
    cout<<endl;

    copy_backward(v.begin(),v.end(), l.end());
    for_each(l.begin(), l.end(), print_element);
    cout<<endl;

    return 0;

}
