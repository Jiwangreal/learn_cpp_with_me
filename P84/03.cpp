#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using  namespace std;

int main( void)
{
    int a[] = {1,2,3,4,5};
    vector< int> v(a, a+5);

     // copy from vector to cout
     //" "��ʾ�����ʱ�򣬷ָ����ÿո�
     //����v��begin��end����������������ostream_iterator
     //�������������cout�����
     //�ؼ�����������*��=�������
    copy(v.begin(), v.end(), ostream_iterator< int>(cout,  " "));
    cout << endl;

     return  0;
}
