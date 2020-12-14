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

//如果没有任何一个异常能够捕获的话，会抛出到我们注册的终止函数中，最后再终止进程，再调用一次abort函数，abort程序会
//弹出那个对话框
void MyTerminate()
{
    cout<<"MyTerminate ..."<<endl;
}

int main(void)
{
    // abort();
    set_terminate(MyTerminate);
    try 
    {
        try
        {
            cout<<"Inner ..."<<endl;
            throw MyExceptions("test exception");//抛出MyException异常，没有合适的异常处理器，向外传播也没有，它就会调用terminte函数终止
                                                //terminte函数默认调用的是abort函数，异常终止进程
        }
        catch (int)//这里catch捕获的是int类型异常，无法捕获throw，逐个异常将被传播到外层catch语句块中
        {
            cout<<"Inner ..."<<endl;
            cout<<"catch a int exception"<<endl;
        }
        // catch (MyExceptions& e)//这里的异常对象e由throw MyExceptions("test exception");这里抛出的异常对象，它的生命周期结束了，调用了析构函数
        // {
        //     cout<<"Inner ..."<<endl;
        //     cout<<e.what()<<endl;
        //     throw e;//重新抛出异常会调用拷贝构造函数，传递到外层
        // }
    }
    catch (int)//这里catch捕获的是int类型异常，无法捕获throw，逐个异常将被传播到外层catch语句块中
    {
        cout<<"Outer ..."<<endl;
        cout<<"catch a int exception"<<endl;
    }
    // catch (MyExceptions& e)//处理完毕后，这里的异常对象e也就跟着销毁了，调用析构函数
    // {
    //     cout<<"Outer ..."<<endl;
    //     cout<<e.what()<<endl;
    // }

    return 0;
}