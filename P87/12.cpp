
//假设下面是动态库
//y.h不需要包含x.h，只需要前向声明，因为指针的原因X*
//file y.h
class Y
{
    Y();
    ~Y();
    void Fun();
    X* px_;//即使类X发生变化，Y类不需要编译，指针所指向的类到底是怎么实现的，分离了
            //因为指针总是4个字节或者8个字节
            //在运行期，还可以应用多态，因为这是指针
            //也可以用智能指针，因为智能指针所持有的对象类型发生了改变，但智能指针的大小是不会改变的
            //智能指针还能自动管理px_的生存期
};

//file y.cpp
#include "x.h"
Y::Y() : px_(new X) {}
Y::~Y() {delete px_; px_ = 0;}
void Y::Fun() {return px_->Fun();}
//end假设下面是动态库

//假设下面是客户程序
//file main.cpp
#include "y.h"//这里y.h没有包含x.h
int main(void) 
{
    Y y;
    y.Fun();
}