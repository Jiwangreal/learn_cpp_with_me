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
    return 0;
}