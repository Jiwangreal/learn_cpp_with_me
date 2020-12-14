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


class Obj
{
public:
    Obj()
    {
        cout<<"Obj ..."<<endl;
    }
    Obj(const Obj& other)
    {
        cout<<"Copy Obj ..."<<endl;
    }
    ~Obj()
    {
        cout<<"~Obj ..."<<endl;
    }
};

class Test2
{
public:
    Test2()
    {
        cout<<"Test2 ..."<<endl;
       
        //�ڹ���Test2����ʱ���׳���һ���쳣
         throw MyExceptions("test exception2");
    }
    Test2(const Test2& other)
    {
        cout<<"Copy Test2 ..."<<endl;
    }
    ~Test2()
    {
        cout<<"~Test2 ..."<<endl;
    }
private:
    Obj obj;//Test2�������һ��Obj����
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
       Test2 t2;//����t2ʱ�����׳��쳣֮ǰ�����ȵ���obj�Ĺ��캯��������Test2����δ��ȫ���죬��ʱ����ջչ��ʱ��obj����ᱻ�Զ�����
                //����Test2�����ǲ��ᱻ���ٵģ���Ϊ����û�й���ɹ����׳����쳣
    }                    
    catch (MyExceptions& e)
    {
        cout<<e.what()<<endl;
    }


    return 0;
}