#include <iostream>
#include <string>
using namespace std;

//�׳��쳣��
class MyExceptions
{
public:
    MyExceptions(const char* message)
        : message_(message)
    {
        cout<<"MyExceptions ..."<<endl;
    }
    //�������캯��
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
        return message_.c_str();//�����쳣��Ϣ
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
        catch (int)//����catch�������int�����쳣���޷�����throw������쳣�������������catch������
        {
            cout<<"catch a int exception"<<endl;
        }
    }
    catch (MyExceptions& e)
    {
        cout<<"Outer ..."<<endl;
        cout<<e.what()<<endl;
    }

    return 0;
}