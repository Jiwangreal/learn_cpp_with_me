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
    //��Ϊ�Ǽ̳У��������Ϊ����������
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
         //throw &e;//�׳�һ��ָ��
         /*
         ����MyExeptionD �������ڶ��Ϸ���ģ�������catch ��ʱ��û�ͷţ������Է��ʵ�
         e->what(); ����Ҫ�Լ���catch ĩβdelete e;
         */
         throw  new MyExceptionD( "test exception");
    }
     /*catch (void* e)//�׳����κ�ָ�룬���ܱ�void*���͵�ָ��������
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