#include <string>
#include <iostream>
using namespace std;


int main(void)
{
    //当作普通的类即可，实际上基于basic_string模板类来重新定义的string类型
    string s1;
    string s2("abcdefghijkl");
    cout<<s2<<endl;

    basic_string<char> s3("xxx");//等价于string s3("xxx");
    cout<<s3<<endl;

    string s4("abcdefg", 4);//传递进去的是四个字符
    cout<<s4<<endl;

    //将对象s2以2的位置开始构造，构造3个
    string s5(s2, 2, 3);
    cout<<s5<<endl;

    //iterator迭代器，直接看成char*就可以了
    string::iterator first = s2.begin() + 1; //从b开始
    // string::iterator first = s2.begin() + 3; //输出bc

    string::iterator last = s2.end();//到l的下一个
    string s6(first, last);//区间实际是：[first, last)
    cout<<s6<<endl;

    return 0;
}
