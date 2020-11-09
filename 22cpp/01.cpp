#include "Complex.h"

int main(void)
{
    Complex c1(3, 5);
    Complex c2(4, 6);

    // c1.Add(c2);
    // c1.Display();

    //若成员函数或者友元函数都有，VS2008会先运行成员函数重载的函数，但是在VC6中，这俩不能共存
    //如果以成员函数的方式重载，等价于c1.operator+(c2)
    //如果以友元函数的方式重载，等价于operator+(c1+c2),该operator+的作用域是全局的，不是类作用域
    Complex c3 = c1 + c2;   
    c1.Display();
    c2.Display();
    c3.Display(); 


}