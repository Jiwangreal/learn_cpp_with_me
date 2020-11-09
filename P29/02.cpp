#include <iostream>
using namespace std;

class Base
{
public:
    Base() : _x(0)
    {

    }
    int GetBaseX() const 
    { 
        return _x; 
    }
    int x_;
    void Show()
    {
        cout<<"Base::show..."<<endl;
    }
};


class Derived : public Base
{
public:
    Derived() : _x(0)
    {

    }
    int GetDerivedX() const 
    { 
        return _x; 
    }
    int x_;

    void Show(int n)
    {
        cout<<"Derived::show"<<endl;
    }
    void Show()
    {
        cout<<"Derived::show..."<<endl;
    }

};

class Test
{
public:
    Base b_;
    int x_;
};

int main(void)
{

    Derived d;
    d.x_ = 10;
    d.Base::x_ = 20;
    cout<<d.GetBaseX()<<endl;
    cout<<d.GetDerivedX()<<endl;

    //调用的是，派生类的不带参数的show方法
    d.show();
    //访问基类的show方法
    d.Base::show();

    //Derived继承了Base，相当于把base当成了子对象一样的
    //Derived包含了2个数据成员：基类的_x,派生类的_x
    cout<<sizeof(Derived)<<endl;
    cout<<sizeof(Test)<<endl;
    return 0;
}