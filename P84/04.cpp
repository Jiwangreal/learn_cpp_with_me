#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using  namespace std;

int main( void)
{
    vector< int> v;

    //把标准输入的数据拷贝到vector
     // copy from cin to vector
     //istream_iterator< int>()表示逻辑上的end()
    copy(istream_iterator< int>(cin), istream_iterator< int>(), back_inserter(v));

    //把vector的数据拷贝到标准输出
     // copy from vector to cout
     //" "表示输出的时候，分隔符用空格
     //向量v从begin到end输出到输出流迭代器ostream_iterator
     //输出流迭代器与cout相关联
     //关键在于重载了*，=号运算符
    copy(v.begin(), v.end(), ostream_iterator< int>(cout,  " "));
    cout << endl;

     return  0;
}
