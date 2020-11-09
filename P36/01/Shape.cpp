#include "Shape.h"
#include "DynBase.h"
#include <iostream>
using namespace std;

void Circle::Draw()
{
    cout<<"Circle::Draw() ..."<<endl;
}
Circle::~Circle()
{
    cout <<"~Circle ..."<<endl;
}


void Square::Draw()
{
    cout<<"Square::Draw() ..."<<endl;
}
Square::~Square()
{
    cout <<"~Square ..."<<endl;
}


void Rectangle::Rectangle()
{
    cout<<"Rectangle::Draw() ..."<<endl;
}
Rectangle::~Rectangle()
{
    cout <<"~Rectangle ..."<<endl;
}

//这里添加了三个宏,仅仅是做为展开操作
REGISTER_CLASS(Circle);
REGISTER_CLASS(Square);
REGISTER_CLASS(Rectangle);

/*

#define REGISTER_CLASS(class_name) \
class class_name##Register { \
public: \
    static void* NewInstance() \
    { \
        return new class_name; \
    } \
private: \
    static Register reg_; \
}; \
Register class_name##Register::reg_(#class_name, class_name##Register::NewInstance);


eg:宏展开的结果
//注册了一个Circle类,支持动态创建技术
#define REGISTER_CLASS(Circle)
class CircleRegister {
public:
    static void* NewInstance()
    {
        return new Circle;
    }
private:
    static Register reg_;//类对象,仅仅只是声明,需要在类体外进行定义
};
Register CircleRegister::reg_("Circle", CircleRegister::NewInstance);
//定义reg_对象会引发构造函数的调用

*/