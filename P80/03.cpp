#include <iostream>
#include <vector>
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
    int a[] = {1, 2�� 3, 4, 5, 6};
    vector<int> v(a, a+6);
    
    for_each(v.begin(), v.end(), print_element);
    cout<<endl;

    //��1��2Ԫ�ط�ת��ĩβ
    rotate(v.begin(), v.begin()+2, v.end());
    // rotate(v.begin(), v.begin()+2, v.end() - 1);֧�֣�vector�ڲ��ĵ����������������
    for_each(v.begin(), v.end(), print_element);
    cout<<endl;

    /*
    list<int> l;
    l.end() - 1;������ô����ԭ���ǣ�list������ʵ�֣���֧��������ʣ�list�ĵ�����
    �����������������һ��˫�����������֧��+��- += -=���㣬����֧��++��--����
    */

    return 0;

}
