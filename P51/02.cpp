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
        /*
        即抛出局部对象的指针，由于在catch 时MyExeptionD 对象已经被析构了，所以访问不到e->what(); 即e是空悬指针。
        还有一点是，任何类型的指针都能被void* 指针所捕获，如果将catch (void* e);注释打开，那么由于排在前面，异常首先将被它所捕获。
        */
         MyExceptionD e("test exception");
         throw &e;//抛出一个指针，此时抛出的是指针本身，不会去复制指针所指向的内容，通常不要
                    //抛出指针，因为抛出指针还需要自己去释放指针对象，该对象不能是栈上的对象
                    //如果是栈上的对象，那么在栈展开的时候这个局部对象会被销毁，会导致e指针是一个空悬指针，因为抛出一个指针
                    //不是一个好主意
    }
    catch (void* e)//抛出的任何指针异常，都能被void*类型的指针所捕获
    {
        cout<<"catch void* ..."<<endl;
        cout<<((MyExceptionD*)e)->what()<<endl;
        delete (MyExceptionD*)e;
    }
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