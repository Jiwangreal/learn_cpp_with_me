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


int main(void)
{
    try 
    {
        try
        {
            cout<<"Inner ..."<<endl;
            throw MyExceptions("test exception");
        }
        catch (int)//这里catch捕获的是int类型异常，无法捕获throw，逐个异常将被传播到外层catch语句块中
        {
            cout<<"catch a int exception"<<endl;
        }
        catch (MyExceptions& e)//这里的异常对象e由throw MyExceptions("test exception");这里抛出的异常对象，它的生命周期结束了，调用了析构函数
        {
            cout<<"Inner ..."<<endl;
            cout<<e.what()<<endl;
            throw e;//重新抛出异常会调用拷贝构造函数，传递到外层
        }
    }
    catch (MyExceptions& e)//处理完毕后，这里的异常对象e也就跟着销毁了，调用析构函数
    {
        cout<<"Outer ..."<<endl;
        cout<<e.what()<<endl;
    }

    return 0;
}