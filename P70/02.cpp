#include <iostream>
using  namespace std;


template < typename T>
class MyClass
{
private:
    T value;
public:
     void Assign( const MyClass<T> &x)
    {
        value = x.value;
    }
};

int main( void)
{
    MyClass< double> d;
    MyClass< int> i;

    d.Assign(d);         // OK
    d.Assign(i);         // Error
        					//因为i 和 d 的类型不同，故会编译出错。可以用成员模板（成员函数定义成模板）的方法解决
    					//虽然是同一个类模板实例化出来的模板类，但是还是不一样
                        //一个T是double，一个T是int
     return  0;
}
