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

    MyClass< double> d2(i);//这里不能转换构造，除非提供一个构造函数的成员模板

    //d2 = i;若支持这种操作，等号运算符也应该是一个成员模板

     return  0;
}

/*
auto_ptr<X> x;

auto_ptr<Y> y;

x = y;//说明等号运算符是一个成员模板，因为x和y时不同的类

auto_ptr<x> a(y);//说明拷贝构造是一个成员模板
*/