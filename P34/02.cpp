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

    Base()
    {
        cout<<"Base ..."<<endl;
    }

    //ʲôʱ���õ�������������
    //���һ����Ҫ��Ϊ��̬���࣬Ҫ��������������Ϊ�麯������ֹ�ڴ�й©
    virtual ~Base()
    {
        cout<<"~Base ..."<<endl;
    }
};

class Derived : public Base
{
public:
    //void Fun1()û��virtual�ؼ��֣�Fun1Ҳ���麯����Fun2����
    /*virtual*/ void Fun1()
    {
        cout<<"Derived::Fun1 ..."<<endl;
    }
    /*virtual*/ void Fun2()
    {
        cout<<"Derived::Fun2 ..."<<endl;
    }
    void Fun3()
    {
        cout<<"Derived::Fun3 ..."<<endl;
    }
    Derived()
    {
        cout<<"Derived ..."<<endl;
    }
    //����������������麯�������������ȻҲ������
    ~Derived()
    {
        cout<<"~Derived ..."<<endl;
    }
};

int main(void)
{
    //����ָ��ָ�����������
    Base* p;
    p = new Derived;//�ȹ�����࣬�ٹ���������

    p->Fun1();
    delete p;

    return 0;
}