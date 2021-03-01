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
    int a[] = {1, 3�� 2, 3, 4, 5};
    vector<int> v(a, a+6);
    
    for_each(v.begin(), v.end(), print_element);
    cout<<endl;

    //�Ƴ�ֵ=3��Ԫ��
    //remove��û�н�Ԫ�ش�����������ɾ��,���߼�ɾ��
    //����ɾ����Ҫ���erase
    //remove(v.begin(),v.end(), 3)���ص����߼��ص�
    v.erase(remove(v.begin(),v.end(), 3), v.end());
    for_each(v.begin(), v.end(), print_element);
    cout<<endl;



    return 0;

}
