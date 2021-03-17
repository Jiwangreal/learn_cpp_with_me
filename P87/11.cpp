
//假设下面是动态库
//file y.h
#include "x.h"
class Y
{
    void Func();X x;
};

//file y.cpp
#include "y.h"
void Y::Fun()
{
    return x_.Fun();
}
//end假设下面是动态库

//假设下面是客户程序
//file main.cpp
#include "y.h"
int main(void)
{
    Y y;
    y.Fun();
}