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
        MyExceptionD t;
        MyExceptionD e( "test exception");//�׳�һ���������쳣���ǿ��Ա��������Ͳ���ģ���Ϊ������Ҳ��һ�ֻ������
         throw e;//�ȵ��������๹�캯��������MyExceptionD����
    }
    catch (MyExceptionD &e)//��ý���������쳣����������ǰ�棬Ϊ�˼��ٶ��󿽱����������Ϊ���ã���������һ�ζ���Ŀ���
    {                       //�����������ǲ�����ÿ������캯�����൱����һ�ֲ������ݣ����ݵ�catch������
                            ////����쳣������ʺ�Ҫ����ջչ������Ѱ�Һ��ʵ�catch����������,��ʱ���ֲ�����t������������������Զ�����
        cout <<  "catch MyExceptionD ..." << endl;
        cout << e.what() << endl;
    }
    /*
    ��������쳣�ܹ���������������ǰ����쳣��������ܹ�ƥ��Ļ�����catch��
    ����ѻ���ķ�����ǰ�棬���Ҳ������õ���ʽ���� catch (MyException e); ��ô���ᱻ�����catch ���������ڹ���e �Ĺ��̻���object slicing �����⡣
    */
    catch (MyException &e)//������쳣���������ں��棬������ﲻ�����ô��ݣ�����ᱻ�и�ɻ���������ô���
    {                       //�ǲ��ṹ��һ���µĶ�������ģ�������ý���������쳣����������ǰ�棬�Ա�������ȫƥ��
        cout <<  "catch MyException ..." << endl;
        cout << e.what() << endl;
    }

     return  0;
}