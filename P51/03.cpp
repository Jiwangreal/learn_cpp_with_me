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
         //MyExceptionD e("test exception");
         //throw &e;//抛出一个指针
         /*
         现在MyExeptionD 对象是在堆上分配的，所以在catch 的时候还没释放，还可以访问到
         e->what(); 但需要自己在catch 末尾delete e;
         */
         throw  new MyExceptionD( "test exception");
    }
     /*catch (void* e)//抛出的任何指针，都能被void*类型的指针所捕获
    {
        cout<<"catch void* ..."<<endl;
        cout<<((MyExceptionD*)e)->what()<<endl;
        delete (MyExceptionD*)e;
    }*/
     catch (MyExceptionD *e)
    {
        cout <<  "catch MyExceptionD ..." << endl;
        cout << e->what() << endl;
        delete e;
    }
     catch (MyException &e)
    {
        cout <<  "catch MyException ..." << endl;
        cout << e.what() << endl;
    }

     return  0;
}