#include <iostream>
using  namespace std;

template < typename T>
class MyClass
{
private:
    T value;
public:
    MyClass() {}
    template <class X>
    MyClass( const MyClass<X> &x) : value(x.GetValue())
    {

    }
     template < class X>
     void Assign( const MyClass<X> &x)
    {
        value = x.GetValue();
    }
    T GetValue()  const
    {
         return value;
    }
};

int main( void)
{
    MyClass< double> d;
    MyClass< int> i;
    d.Assign(d);         // OK
    d.Assign(i);         // OK

    MyClass< double> d2(i);//���ﲻ��ת�����죬�����ṩһ�����캯���ĳ�Աģ��

    //d2 = i;��֧�����ֲ������Ⱥ������ҲӦ����һ����Աģ��

     return  0;
}

/*
auto_ptr<X> x;

auto_ptr<Y> y;

x = y;//˵���Ⱥ��������һ����Աģ�壬��Ϊx��yʱ��ͬ����

auto_ptr<x> a(y);//˵������������һ����Աģ��
*/