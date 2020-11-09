#include <iostream>
using namespace std;

class ObjectB()
{
public:
    ObjectB(int objb) : objb_(objb)
    {
        cout<<"ObjectB..."<<endl;
    }
    ~ObjectB()
    {
        cout<<"~ObjectB..."<<endl;
    }
    int objd_;
};



class ObjectD()
{
public:
    ObjectD(int objd) : objd_(obj)
    {
        cout<<"ObjectD..."<<endl;
    }
    ~ObjectD()
    {
        cout<<"~ObjectD..."<<endl;
    }
    int objd_;
};


class Base
{
public:
    Base(int b) : b_(b), objb_(111)
    {
        cout<<"Base..."<<endl;
    }

    //Base�Ŀ������캯��
    //objb_(other.objb_)�����ObjectB�Ŀ������캯������û�У������Ĭ�ϵĿ������캯��
    Base(const Base& other) : objb_(other.objb_), b_(other.b_)
    {

    }
    ~Base()
    {
        cout<<"~Base..."<<endl;
    }
    int b_;
    ObjectB objb_;//���ж�������Ա������˳����������˳����й���
};

class Derived : public Base
{
public:
    //û����ȷָ�����û����ʲô���캯����Ĭ�ϵ��û����Ĭ�Ϲ��캯��
    Derived(int b, int d) : d_(d), Base(b), objd_(222)
    {
        cout<<"Derived.."<<endl;
    }
    //������Ŀ������캯��
    //Base(other)����û���Ŀ������캯��
    //�ڹ��캯����Ҫ���3�����飺d_(d), Base(b), objd_(222)��ͬ���ڿ������캯��ҲҪ�������������
    //�������캯��Ҳ��һ�ֹ��캯��������д���������빹�캯����д����һ����
    Derived(const Derived& other) : d_(other.d_), objd_(other.objd), Base(other)
    {

    }


    ~Derived()
    {
        cout<<"~Derived.."<<endl;
    }
    int d_;
    ObjectD objd_;

};

int main(void)
{
    Derived d(100,200);
    cout<<d.b_<<" "<<d.d_<<endl;

    Base b1(100);
    Base b2(b1);//����ÿ������캯��
    cout<<b2.b_<<endl;

    Derived d2(d);
    return 0;
}