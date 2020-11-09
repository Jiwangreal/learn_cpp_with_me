#include <string>
#include <iostream>
using namespace std;

void fun(char *str)
{
    cout<<str<<endl;
}

int main(void)
{
    string s1 = "abc";

    s1[1] = 'B';//重载[]运算符，返回指向字符的引用

    cout<<s1<<endl;

    //error, 不能给常量赋值
    const string s2 = "xyz";
    //s2[1] = 'Y';//error s2[1]返回的是const char&

    //字符串加法运算：前2个至少有一个是string对象
    string s3 = "111" + s1 + "222";
    cout<<s3<<endl;

    s3.c_str();//可以将字符串string转化为const char *

    //const_cast<char*>可以去掉s3.c_str()的常量性const，最终转化为char *
    fun(const_cast<char*>(s3.c_str()));
    return 0;

}
