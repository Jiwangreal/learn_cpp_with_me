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

    Base()
    {
        cout<<"Base ..."<<endl;
    }

    //什么时候用到虚析构函数？
    //如果一个类要做为多态基类，要将析构函数定义为虚函数，防止内存泄漏
    virtual ~Base()
    {
        cout<<"~Base ..."<<endl;
    }
};

class Derived : public Base
{
public:
    //void Fun1()没有virtual关键字，Fun1也是虚函数，Fun2类似
    /*virtual*/ void Fun1()
    {
        cout<<"Derived::Fun1 ..."<<endl;
    }
    /*virtual*/ void Fun2()
    {
        cout<<"Derived::Fun2 ..."<<endl;
    }
    void Fun3()
    {
        cout<<"Derived::Fun3 ..."<<endl;
    }
    Derived()
    {
        cout<<"Derived ..."<<endl;
    }
    //基类的析构函数四虚函数，派生类的自然也变成虚的
    ~Derived()
    {
        cout<<"~Derived ..."<<endl;
    }
};

int main(void)
{
    //基类指针指向派生类对象
    Base* p;
    p = new Derived;//先构造基类，再构造派生类

    p->Fun1();
    delete p;

    return 0;
}