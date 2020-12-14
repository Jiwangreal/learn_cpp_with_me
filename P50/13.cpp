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

class Test3
{
public:
    Test3()
    {
        cout<<"Test3 ..."<<endl;
    }
    Test3(const Test3& other)
    {
        cout<<"Copy Test3 ..."<<endl;
    }
    ~Test3()
    {
        cout<<"~Test3 ..."<<endl;
        throw 4;
    }
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
       Test3 t3;
       throw MyExceptions("test exception");//�׳��쳣��ʱ����ջչ���ڼ䣬�����Test3���������������׳���int���͵��쳣
                                            //��ǰ�׳����쳣û�б����������׳����µ��쳣
                                            //throw 4;�ᵼ��terminate�����ĵ��ã�����������ֹ��ʹ���쳣��ֹû����
                                            //���Բ�Ӧ���������������׳��쳣�������ڹ��캯�����׳��쳣
    }                    
    catch (MyExceptions& e)
    {
        cout<<e.what()<<endl;
    }
    catch (int)
    {
        cout<<"catch a int exception"<<endl;
    }


    return 0;
}