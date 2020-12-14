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
        obj_ = new Obj;
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
        delete obj_;
        cout<<"~Test2 ..."<<endl;
    }
private:
    Obj* obj_;//Test2�������һ��Obj����
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
       Test2 t2;//����Test2�ǲ��ֱ����죬������ջչ��ʱ��Test2�����������ǲ��ᱻ���õģ�����delete obj_;���ᱻִ�У�û�취���٣��������ڴ�й©
    }                    
    catch (MyExceptions& e)
    {
        cout<<e.what()<<endl;
    }


    return 0;
}