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

class Test3
{
public:
    Test3()
    {
        cout<<"Test3 ..."<<endl;
    }
    Test3(const Test3& other)
    {
        cout<<"Copy Test3 ..."<<endl;
    }
    ~Test3()
    {
        cout<<"~Test3 ..."<<endl;
        throw 4;
    }
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
       Test3 t3;
       throw MyExceptions("test exception");//抛出异常的时候，在栈展开期间，会调用Test3的析构函数，又抛出了int类型的异常
                                            //先前抛出的异常没有被捕获处理，又抛出了新的异常
                                            //throw 4;会导致terminate函数的调用，整个程序被终止，使得异常终止没意义
                                            //所以不应该在析构函数中抛出异常，可以在构造函数中抛出异常
    }                    
    catch (MyExceptions& e)
    {
        cout<<e.what()<<endl;
    }
    catch (int)
    {
        cout<<"catch a int exception"<<endl;
    }


    return 0;
}