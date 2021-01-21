#include <iostream>
using  namespace std;

template < typename T>
class MyClass
{
private:
    T value;
public:
    MyClass() {}
     template < class X>
    MyClass( const MyClass<X> &x) : value(x.GetValue())
    {

    }
    //成员模板，X是一种类型
    template <class X>
    void Assign( const MyClass<X> &x)
    {
        value = x.GetValue();//不能直接访问：value = x.value;
        //因为对象d和对象i的类型不一样，这样就不能访问不同类型的私有成员，所以需要定义一个Assign接口出来
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

    MyClass< double> d2(i);

     return  0;
}