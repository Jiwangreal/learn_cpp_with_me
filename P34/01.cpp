//演示动态绑定的语法的eg
#include <iostream>
using namespace std;

class Base
{
public:
    virtual void Fun1()
    {
        cout<<"Base::Fun1 ..."<<endl;
    }

    virtual void Fun2()
    {
        cout<<"Base::Fun2 ..."<<endl;
    }
    void Fun3()
    {
        cout<<"Base::Fun3 ..."<<endl;
    }
};

class Derived : public Base
{
public:
    //void Fun1()没有virtual关键字，Fun1也是虚函数，Fun2类似
    virtual void Fun1()
    {
        cout<<"Derived::Fun1 ..."<<endl;
    }
    virtual void Fun2()
    {
        cout<<"Derived::Fun2 ..."<<endl;
    }
    void Fun3()
    {
        cout<<"Derived::Fun3 ..."<<endl;
    }
};

int main(void)
{
    //基类指针指向派生类对象
    Base* p;
    Derived d;

    p = &d;
    //调用的是基类的Fun1还是派生类的Fun1是在运行期时决定的
    p->Fun1();//Fun1是虚函数，基类的指针指向派生类对象，调用的是派生类对象的虚函数
    p->Fun2();
    p->Fun3();//Fun3是非虚函数，根据p指针实际类型来调用相应类的成员函数

    return 0;
}