#include <iostream>
using namespace std;

//构造函数不能是虚函数
//析构函数可以是虚函数，若一个类有多态中的基类，应该将析构函数声明为虚析构函数

// class Base
// {
// public:
//     void Test() = 0;//这是纯虚函数void Test() = 0;，Base类是抽象类
// };

//对于一个没有任何接口的类,如果想要将它定义成抽象类,只能将虚析构函数声明为纯虚的
//通常情况下,在基类中纯虚函数需要实现
//例外是纯虚析构函数要给出实现(给出一个空的实现即可)
class Base
{
public:
    virtual ~Test() = 0;//拥有纯虚析构函数的类就是抽象类
    {

    }
};

class Derived : public Base
{

};


int main(void)
{
    Derived d;
    return 0;
}
