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
     //" "表示输出的时候，分隔符用空格
     //向量v从begin到end输出到输出流迭代器ostream_iterator
     //输出流迭代器与cout相关联
     //关键在于重载了*，=号运算符
    copy(v.begin(), v.end(), ostream_iterator< int>(cout,  " "));
    cout << endl;

     return  0;
}
