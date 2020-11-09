#include <iostream>
using namespace std;

class Base
{
public:
    int x_;
protected:
    int y_;
private:
    int z_;
};

//公有继承的访问权限是不变的
//公有的成员在派生类中还是公有的，保护的成员在派生类中还是保护的
class PublicInherit : public Base
{
public:
    void Test()
    {
        x_  = 10;//在派生类中可以访问基类的public成员
        y_ = 20;//在派生类中可以访问基类的protected成员
        // z_ = 30;//在派生类中不能访问基类的private成员，虽然基类的private成员是派生类的一部分
    }
private:
};

//私有继承：基本的公有成员和保护成员在派生类中都是私有的，派生类的成员函数还是可以访问的
class PrivateInherit : private Base
{
public:
    void Test()
    {
        x_ = 10;
        y_ = 20;
        // z_ = 30;//私有继承还是无法访问基类的私有成员
    }
};

//基类保护成员在继承之后是否还是保护的？若是保护的，
//则在其派生类应该是可以访问的
class PublicPublicInherit : public PublicInherit
{
public:
    void test()
    {
        y_ = 20;//还是可以访问，说明他是保护的
    }
};



int main(void)
{
    Base b;
    b.x_ = 20;//类外部可以访问public成员
    b.z_ = 30;//类外部不能访问protected成员
    
    //公有继承的访问权限不变，公有的在派生类中还是公有的，保护成员在派生类中还是保护的
    PublicInherit pub;
    pub.x_ = 20;

    //私有继承不能访问私有成员
    // PrivateInherit pi;
    // pi.x_ = 10;

    return 0;
}
