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
        Test t;
        throw MyExceptions("test exception");//输出异常对象的适合要进行栈展开，会寻找合适的catch语句块来处理
    }                                       //此时，局部对象t会调用析构函数进行自动销毁
    catch (MyExceptions& e)
    {
        cout<<e.what()<<endl;
    }


    return 0;
}