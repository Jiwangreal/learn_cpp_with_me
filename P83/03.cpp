
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
bool is_odd(int n)
{
    return n % 2 == 1;
}

int main(void)
{
    int a[] = {1,2,3,4,5};
    vector<int> v(a, a+5);

    //�㷨����������������
    //ͳ�������������ĸ���
    count<<count_if(v.begin(), v.end, is_odd)<<endl;


    //��������Ԫ�صĸ���
    //�����bind2nd����Ԫ��������modulusת��ΪһԪ��������
    //modulus�����Ĳ�������2��������m%n��
    //bind2ndֻ��Ҫ����һ�������ˣ���Ϊ�����˵�2��������m%2����ʱһԪ����������״̬�ˣ��������2��״̬
    //��m�Ĳ�����v.begin(),v.end()����
    //bind2nd(op,value)(param)�൱��op(param,value)
    //bind2nd(��Ԫ����������Ҫ�󶨵�ֵ)������һԪ�������󣬷���һ������param
    //param��v.begin(),v.end(),���������У���ֵ���ݵ�param�����

    //bind2nd��һ������ģ��
    cout<<count_if(v.begin(),v.end(),
    bind2nd(modulus< int>(), 2))<<endl;


    //�����bind1st����Ԫ��������modulusת��ΪһԪ��������
    //��Ԫ��������less<int>()��ʾm < n,
    //bind1st��ʾ�󶨵��ǵ�һ��������������2<n��n��ֵ�Ǳ�����ʱ�򴫽���
        //bind1st(op,  value)(param)�൱��op(value,  param);
        cout  <<  count_if(v.begin(),  v.end(),
                bind1st(less< int>(),   4))  <<  endl;//>4��Ԫ�ظ����м���

    return 0;
}





