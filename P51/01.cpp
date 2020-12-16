#include <iostream>
#include <string>

using  namespace std;

class MyException
{
public:
    MyException( const  char *message)
        : message_(message)
    {
        cout <<  "MyException ..." << endl;
    }
    MyException( const MyException &other) : message_(other.message_)
    {
        cout <<  "Copy MyException ..." << endl;
    }
    //因为是继承，最好声明为虚析构函数
    virtual ~MyException()
    {
        cout <<  "~MyException ..." << endl;
    }

    const  char *what()  const
    {
         return message_.c_str();
    }
private:
    string message_;
};

class MyExceptionD :  public MyException
{
public:
    MyExceptionD( const  char *message)
        : MyException(message)
    {
        cout <<  "MyExceptionD ..." << endl;
    }
    MyExceptionD( const MyExceptionD &other)
        : MyException(other)
    {
        cout <<  "Copy MyExceptionD ..." << endl;
    }
    ~MyExceptionD()
    {
        cout <<  "~MyExceptionD ..." << endl;
    }
};

int main( void)
{
    try
    {
        MyExceptionD t;
        MyExceptionD e( "test exception");//抛出一个派生类异常，是可以被基类类型捕获的，因为派生类也是一种基类对象
         throw e;//先调用派生类构造函数，构造MyExceptionD对象
    }
    catch (MyExceptionD &e)//最好将派生类的异常处理程序放在前面，为了减少对象拷贝，最好声明为引用，这样就少一次对象的拷贝
    {                       //这里是引用是不会调用拷贝构造函数，相当于是一种参数传递，传递到catch语句块中
                            ////输出异常对象的适合要进行栈展开，会寻找合适的catch语句块来处理,此时，局部对象t会调用析构函数进行自动销毁
        cout <<  "catch MyExceptionD ..." << endl;
        cout << e.what() << endl;
    }
    /*
    派生类的异常能够被基类所捕获，且前面的异常处理程序能够匹配的话首先catch，
    如果把基类的放在最前面，而且不是引用的形式，如 catch (MyException e); 那么将会被这个所catch 到，而且在构造e 的过程会有object slicing 的问题。
    */
    catch (MyException &e)//基类的异常处理程序放在后面，如果这里不是引用传递，这里会被切割成基类对象，引用传递
    {                       //是不会构造一个新的对象出来的，所以最好将派生类的异常处理程序放在前面，以便类型完全匹配
        cout <<  "catch MyException ..." << endl;
        cout << e.what() << endl;
    }

     return  0;
}