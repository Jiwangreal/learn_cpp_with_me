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

//抛出自定义类型的异常
 double Divide(double a, double b)
 {
     //栈展开：
     //在调用链之上，Divide可能还可能调用其他函数。这里面所创建的所有局部对象都要被释放，这一过程称之为栈展开
     //现在只有一个：MyExceptions e("division by zero");，若这里面又调用了函数，函数里面又创建了局部对象，那么这些局部对象会被
     //逐个释放掉
     if (b == 0.0)
     {
        //  MyExceptions e("division by zero");
        //  throw e;//这里抛出自定义类型的异常,throw e会调用拷贝构造函数，拷贝构造一个对象
        //         //接着局部对象MyException e("division by zero");被销毁了，抛出了一个异常，程序被catch到了
        throw 1.5;
     }
     else
     {
         return a / b;
     }
     
 }

 int main(void)
 {
     try
     {
         cout<<Divide(5.0, 0.0)<<endl;
     }
     catch (MyExceptions& e)//将异常对象传递过来，接着所抛出的异常对象的生命周期也结束了（析构函数）
     {
         //输出异常信息
         cout<<e.what()<<endl;
     }
     catch (int)
     {
            cout<<"int exception ..."<<endl;
     }
     catch (...)//...表示可以捕获任何异常
     {
            cout<<"catch a exception ..."<<endl;
     }
 }