#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using  namespace std;

int main( void)
{
    vector< int> v;

    //�ѱ�׼��������ݿ�����vector
     // copy from cin to vector
     //istream_iterator< int>()��ʾ�߼��ϵ�end()
    copy(istream_iterator< int>(cin), istream_iterator< int>(), back_inserter(v));

    //��vector�����ݿ�������׼���
     // copy from vector to cout
     //" "��ʾ�����ʱ�򣬷ָ����ÿո�
     //����v��begin��end����������������ostream_iterator
     //�������������cout�����
     //�ؼ�����������*��=�������
    copy(v.begin(), v.end(), ostream_iterator< int>(cout,  " "));
    cout << endl;

     return  0;
}
