#include <iostream>
using  namespace std;

template < typename T>
class MyClass
{
private:
    /*
    typename T::SubType *ptr_; 如果前面没有typename 修饰，则SubType会被认为是T类型内部的静态数据成员，推导下去，* 就不再认 为是指针，而被
    认为是乘号，编译的时候就出错了。加上修饰，就知道SubType 是T 内部的自定义类型，ptr是指向这种类型的指 针，编译通过。
    */
    typename T::SubType *ptr_;//typename代表SubType是一个类型
};

class Test
{
public:
     typedef  int SubType;
};
int main( void)
{
    MyClass<Test> mc;
     return  0;
}
