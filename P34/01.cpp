//��ʾ��̬�󶨵��﷨��eg
#include <iostream>
using namespace std;

class Base
{
public:
    virtual void Fun1()
    {
        cout<<"Base::Fun1 ..."<<endl;
    }

    virtual void Fun2()
    {
        cout<<"Base::Fun2 ..."<<endl;
    }
    void Fun3()
    {
        cout<<"Base::Fun3 ..."<<endl;
    }
};

class Derived : public Base
{
public:
    //void Fun1()û��virtual�ؼ��֣�Fun1Ҳ���麯����Fun2����
    virtual void Fun1()
    {
        cout<<"Derived::Fun1 ..."<<endl;
    }
    virtual void Fun2()
    {
        cout<<"Derived::Fun2 ..."<<endl;
    }
    void Fun3()
    {
        cout<<"Derived::Fun3 ..."<<endl;
    }
};

int main(void)
{
    //����ָ��ָ�����������
    Base* p;
    Derived d;

    p = &d;
    //���õ��ǻ����Fun1�����������Fun1����������ʱ������
    p->Fun1();//Fun1���麯���������ָ��ָ����������󣬵��õ��������������麯��
    p->Fun2();
    p->Fun3();//Fun3�Ƿ��麯��������pָ��ʵ��������������Ӧ��ĳ�Ա����

    return 0;
}