#include <iostream>

using namespace std;

//实际上是2个类对象
// cout;
// cin;


int main(void)
{
    int n;
    cout << n <<endl;//在ostream类中重载了<<运算符，以成员函数方式重载

    MyString str;
    cout<<str;//不能以成员函数的方式重载的原因是：不能去更改ostream类的代码，如果每增加一个类，就去更改类重载
                //的代码，这样不好。
                //所以要输出自定义的类，要重载<<插入运算符，要用友元的方式重载
    return 0;
}