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
    int a[] = {1, 10��10, 14, 15, 16};
    vector<int> v(a, a+6);
    for_each(v.begin(), v.end(), print_element);
    cout<<endl;    

    //������һ��>=10��Ԫ��
    vector<int>::iterator it;
    it = lower_bound(v.begin(), v.end(), 10);
    if (it != v.end())
    {
        cout<<it- v.begin()<<endl;
    }


    it = upper_bound(v.begin(), v.end(), 10);
    if (it != v.end())
    {
        cout<<it- v.begin()<<endl;
    }
    return 0;

}
