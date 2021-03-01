#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

void print_element(int n)
{
    cout <<n<<' ';
}

int mult(int a, int b)
{
    return a * b;
}

int main(void)
{
    //�����ڹ����ʱ����Բ����ݲ�����Ҳ���Դ���2�������������е����䶼����һ���տ�����[)
    //����STL���䶼�Ǳտ�����
    //endӦ��ָ��5�����λ�ã���ôbegin��ָ��1
    //a��a+5������������������ʵ�ֵķ�ʽ���࣬���ڲ�������int*�����Ա�����������int*
    int a[] = {1, 2��3, 4, 5};
    vector<int> v(a, a+5);
    for_each(v.begin(), v.end(), print_element);
    cout<<endl;    

    //Ĭ�����ۼӲ���
    cout<<accumulate(v.begin(), v.end(), 0)<<endl;

    //�۳�,1�ǳ�ʼֵ
    cout<<accumulate(v.begin(), v.end(), 1, mult)<<endl;

    return 0;

}
