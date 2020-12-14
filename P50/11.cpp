#include <iostream>
#include <string>
using namespace std;

//抛出异常类
class MyExceptions
{
public:
    MyExceptions(const char* message)
        : message_(message)
    {
        cout<<"MyExceptions ..."<<endl;
    }
    //拷贝构造函数
    MyExceptions(const MyExceptions& other) : message_(other.message)
    {
        cout<<"Copy MyExceptions ..."<<endl;
    }
    ~MyExceptions()
    {
        cout<<"~MyExceptions"<<endl;
    }

    const char* what() const
    {
        return message_.c_str();//返回异常信息
    }

private:
    string message_;
};


class Obj
{
public:
    Obj()
    {
        cout<<"Obj ..."<<endl;
    }
    Obj(const Obj& other)
    {
        cout<<"Copy Obj ..."<<endl;
    }
    ~Obj()
    {
        cout<<"~Obj ..."<<endl;
    }
};

class Test2
{
public:
    Test2()
    {
        cout<<"Test2 ..."<<endl;
       
        //在构造Test2对象时，抛出了一个异常
         throw MyExceptions("test exception2");
    }
    Test2(const Test2& other)
    {
        cout<<"Copy Test2 ..."<<endl;
    }
    ~Test2()
    {
        cout<<"~Test2 ..."<<endl;
    }
private:
    Obj obj;//Test2对象持有一个Obj对象
};


class Test
{
public:
    Test()
    {
        cout<<"Test ..."<<endl;
    }
    Test(const Test& other)
    {
        cout<<"Copy Test ..."<<endl;
    }
    ~Test()
    {
        cout<<"~Test ..."<<endl;
    }
};



int main(void)
{
    try 
    {   
       Test2 t2;//构造t2时（在抛出异常之前），先调用obj的构造函数，但是Test2对象并未完全构造，此时进行栈展开时，obj对象会被自动销毁
                //但是Test2对象是不会被销毁的，因为它还没有构造成功就抛出了异常
    }                    
    catch (MyExceptions& e)
    {
        cout<<e.what()<<endl;
    }


    return 0;
}