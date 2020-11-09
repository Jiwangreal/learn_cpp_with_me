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

    int data1_;
};

//派生类有3个虚函数
class Derived : public Base
{
    //会覆盖基类的虚函数Fun2()
    void Fun2()
    {
        cout<<"Derived::Fun2 ..."<<endl;
    }
    virtual void Fun3()
    {
        cout<<"Derived::Fun3 ..."<<endl;
    }
    int data2_;
};

//使用typedef来定义一个类型
typedef void (*FUNC)();
int main(void)
{
    cout<<sizeof(Base)<<endl;
    cout<<sizeof(Derived)<<endl;
    Base b;
    long** p = (long**)&b;//p[0][0]指向基类的虚函数Base::Func1
    FUNC fun = (FUNC)p[0][0];//将p[0][0]指针强制转换为func，强制转换为函数指针类型
    fun();//会调用到基类的虚函数

    Derived d;
    p = long(**)&d;
    fun = (FUNC)p[0][0];
    fun();
    fun = (FUNC)p[0][1];
    fun();
    fun = (FUNC)p[0][2];
    fun();

    //只有通过基类指针或者基类引用，才有动态绑定
    //基类指针pp指向派生类对象，会取出对象d的头4个字节，指向虚表，然后从虚表中找到对应的Func2，实施动态绑定
    //调用Func2进行偏移，偏移到Derived::Fun2,而不是Base::Fun2,结合派生类内存图去看
    //pp虽然是基类指针类型，但是调用的是派生类的虚函数
    Base* pp = &d;
    pp->Fun2();//Func2是虚函数，运行时期才会去确定Func2的入口地址

    //虚函数可以直接使用，但不是动态绑定，入口地址在编译期就决定了
    //直接调用是静态绑定
    d.fun2();

    return 0;
}