#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>

using  namespace std;

int main( void)
{
     char *a[] = { "",  "BBB",  "CCC"};
    vector< char *> v(a, a +  2);
    vector< char *>::iterator it;
    //ptr_funת���ɶ�Ԫ�ĺ�������a��b�������strcmp(value, "")������ǿ��ַ������ȽϷ���0��Ϊ��
    //find_if���б�ʽΪ��0��ʱ�򣬲���������Ҫ��
    // bind2ndת����һԪ��������
    it = find_if(v.begin(), v.end(), bind2nd(ptr_fun(strcmp),  ""));//���ҵ�һ�����ǿմ����ַ���
     if (it != v.end())
        cout << *it << endl;

     return  0;
}