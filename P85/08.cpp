#include <iostream>
#include <functional>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>

using  namespace std;

int main( void)
{
    int a[]={3, 1, 2, 3, 4};
    vector<int> v(a, a+5);
    
    //��ֵ=3��Ԫ��ɾ��
    //error,it�Ѿ�ɾ��������++it�أ����лᱨ��
    //��һ��������Ԫ����3��itָ��ָ������ɾ����������it��Ϊ����ָ�룬�ڶ���++�������Ϊ
    //��ָ���Ԫ�ض�������
    // for(vector<int>::iterator it =v.begin(); it !=v.end();++it)
    // {
    //     if(*it == 3)
    //         v.erase(it);//
    //     else
    //         cout<<*it<<' ';
    // }
    // cout<<endl;

    //�Ľ����£�
    for(vector<int>::iterator it =v.begin(); it !=v.end();)
    {
        if(*it == 3)
            it = v.erase(it);//���ص�it��3��ָ����һ��Ԫ�أ���һ��itָ��1
        else
        {
            cout<<*it<<' ';
            ++it;
        }
            
    }
    cout<<endl; 

    return 0;
}