#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

void print_element(int n)
{
    cout <<n<<' ';
}

int main(void)
{
    //�����ڹ����ʱ����Բ����ݲ�����Ҳ���Դ���2�������������е����䶼����һ���տ�����[)
    //����STL���䶼�Ǳտ�����
    //endӦ��ָ��5�����λ�ã���ôbegin��ָ��1
    //a��a+5������������������ʵ�ֵķ�ʽ���࣬���ڲ�������int*�����Ա�����������int*
    int a[] = {1, 2, 3, 4, 3};
    vector<int> v(a, a+5);
    list<int> l(5);

    //��Ԫ��Ϊ3���滻��13
    replace(v.begin(), v.end(), 3, 13);

    for_each(v.begin(), v.end(), print_element);
    cout<<endl;

    //replace_copyԭ���䲻�ģ�Ŀ����������
    replace_copy(v.begin(), v.end(), l.begin(), 13, 3);
    for_each(v.begin(), v.end(), print_element);
    cout<<endl;
    
    for_each(l.begin(), l.end(), print_element);
    cout<<endl;

    return 0;

}
