#include <iostream>
using namespace std;

class Base
{
public:
    Base() : _x(0)
    {

    }
    int GetBaseX() const 
    { 
        return _x; 
    }
    int x_;
    void Show()
    {
        cout<<"Base::show..."<<endl;
    }
};


class Derived : public Base
{
public:
    Derived() : _x(0)
    {

    }
    int GetDerivedX() const 
    { 
        return _x; 
    }
    int x_;

    void Show(int n)
    {
        cout<<"Derived::show"<<endl;
    }
    void Show()
    {
        cout<<"Derived::show..."<<endl;
    }

};

class Test
{
public:
    Base b_;
    int x_;
};

int main(void)
{

    Derived d;
    d.x_ = 10;
    d.Base::x_ = 20;
    cout<<d.GetBaseX()<<endl;
    cout<<d.GetDerivedX()<<endl;

    //���õ��ǣ�������Ĳ���������show����
    d.show();
    //���ʻ����show����
    d.Base::show();

    //Derived�̳���Base���൱�ڰ�base�������Ӷ���һ����
    //Derived������2�����ݳ�Ա�������_x,�������_x
    cout<<sizeof(Derived)<<endl;
    cout<<sizeof(Test)<<endl;
    return 0;
}