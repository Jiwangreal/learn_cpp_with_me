#include <iostream>
using namespace std;

class ObjectB()
{
public:
    ObjectB(int objb) : objb_(objb)
    {
        cout<<"ObjectB..."<<endl;
    }
    ~ObjectB()
    {
        cout<<"~ObjectB..."<<endl;
    }
    int objd_;
};



class ObjectD()
{
public:
    ObjectD(int objd) : objd_(obj)
    {
        cout<<"ObjectD..."<<endl;
    }
    ~ObjectD()
    {
        cout<<"~ObjectD..."<<endl;
    }
    int objd_;
};


class Base
{
public:
    Base(int b) : b_(b), objb_(111)
    {
        cout<<"Base..."<<endl;
    }

    //Base的拷贝构造函数
    //objb_(other.objb_)会调用ObjectB的拷贝构造函数，若没有，则调用默认的拷贝构造函数
    Base(const Base& other) : objb_(other.objb_), b_(other.b_)
    {

    }
    ~Base()
    {
        cout<<"~Base..."<<endl;
    }
    int b_;
    ObjectB objb_;//若有多个对象成员，构造顺序按照声明的顺序进行构造
};

class Derived : public Base
{
public:
    //没有明确指定调用基类的什么构造函数，默认调用基类的默认构造函数
    Derived(int b, int d) : d_(d), Base(b), objd_(222)
    {
        cout<<"Derived.."<<endl;
    }
    //派生类的拷贝构造函数
    //Base(other)会调用基类的拷贝构造函数
    //在构造函数中要完成3件事情：d_(d), Base(b), objd_(222)，同样在拷贝构造函数也要完成这三件事情
    //拷贝构造函数也是一种构造函数，它的写法基本上与构造函数的写法是一样的
    Derived(const Derived& other) : d_(other.d_), objd_(other.objd), Base(other)
    {

    }


    ~Derived()
    {
        cout<<"~Derived.."<<endl;
    }
    int d_;
    ObjectD objd_;

};

int main(void)
{
    Derived d(100,200);
    cout<<d.b_<<" "<<d.d_<<endl;

    Base b1(100);
    Base b2(b1);//会调用拷贝构造函数
    cout<<b2.b_<<endl;

    Derived d2(d);
    return 0;
}