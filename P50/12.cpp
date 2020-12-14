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
        obj_ = new Obj;
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
        delete obj_;
        cout<<"~Test2 ..."<<endl;
    }
private:
    Obj* obj_;//Test2对象持有一个Obj对象
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
       Test2 t2;//由于Test2是部分被构造，所以在栈展开时，Test2的析构函数是不会被调用的，所以delete obj_;不会被执行，没办法销毁，出现了内存泄漏
    }                    
    catch (MyExceptions& e)
    {
        cout<<e.what()<<endl;
    }


    return 0;
}