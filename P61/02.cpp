#include <iostream>
#include <sstream>

using namespace std;

//将double数据转换为字符串
string doubletostr( double val)
{
    ostringstream oss;
    oss << val;//输出到字符串流中，字符串流中的缓冲区就是分配空间，将val塞到这块空间了

    //str()返回内部的空间里的字符串
    return oss.str(); // return string copy of character array
}

//字符串转double，C语言是strtod
double strtodouble( const string &str)
{
    istringstream iss(str);
     double val;
    iss >> val;//从字符串流iss提取数据到val，而字符串str与字符串流iss相对应，实际上是从字符串str提取数据到val
     return val;
}

int main( void)
{
     double val =  55. 55;

    string str = doubletostr(val);
    cout << str << endl;

    str =  "123.123";
    val = strtodouble(str);
    cout << val << endl;
     return  0;

}