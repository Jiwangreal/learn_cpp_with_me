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
        /*
        ���׳��ֲ������ָ�룬������catch ʱMyExeptionD �����Ѿ��������ˣ����Է��ʲ���e->what(); ��e�ǿ���ָ�롣
        ����һ���ǣ��κ����͵�ָ�붼�ܱ�void* ָ�������������catch (void* e);ע�ʹ򿪣���ô��������ǰ�棬�쳣���Ƚ�����������
        */
         MyExceptionD e("test exception");
         throw &e;//�׳�һ��ָ�룬��ʱ�׳�����ָ�뱾������ȥ����ָ����ָ������ݣ�ͨ����Ҫ
                    //�׳�ָ�룬��Ϊ�׳�ָ�뻹��Ҫ�Լ�ȥ�ͷ�ָ����󣬸ö�������ջ�ϵĶ���
                    //�����ջ�ϵĶ�����ô��ջչ����ʱ������ֲ�����ᱻ���٣��ᵼ��eָ����һ������ָ�룬��Ϊ�׳�һ��ָ��
                    //����һ��������
    }
    catch (void* e)//�׳����κ�ָ���쳣�����ܱ�void*���͵�ָ��������
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