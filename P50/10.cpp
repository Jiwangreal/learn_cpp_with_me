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

class Test
{
public:
    Test()
    {
        cout<<"Test ..."<<endl;
    }
    Test(const Test& other)
    {
        cout<<"Copy Test ..."<<endl;
    }
    ~Test()
    {
        cout<<"~Test ..."<<endl;
    }
};


int main(void)
{
    try 
    {   
        Test t;
        throw MyExceptions("test exception");//����쳣������ʺ�Ҫ����ջչ������Ѱ�Һ��ʵ�catch����������
    }                                       //��ʱ���ֲ�����t������������������Զ�����
    catch (MyExceptions& e)
    {
        cout<<e.what()<<endl;
    }


    return 0;
}