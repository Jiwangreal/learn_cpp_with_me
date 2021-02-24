#include <iostream>
#include <vector>
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

    //ʹ���㷨
    for_each(v.begin(), v.end(), print_element);
    cout<<endl;

    //for_each�Ǳ䶯�Ի��ǷǱ䶯���㷨��ȡ���ڵ�3���������Ƿ���������е�Ԫ��
    for_each(v.begin(), v.end(), add_3);

    for_each(v.begin(), v.end(), print_element);
    cout<<endl;

    return 0;

}
