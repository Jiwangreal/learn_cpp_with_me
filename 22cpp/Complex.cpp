#include "Complex.h"
#include <iostream>
using namespace std;
Complex::Complex(int real, int imag) : real_(real), imag_(imag)
{

}

Complex::Complex()
{

}

Complex::~Complex()
{

}
//返回的是自身的引用，所以不会调用拷贝构造函数
Complex& Complex::Add(const Complex& other)
{
    real_+=other.real_;
    imag_+=other.imag_;
    return *this;
}

//运算符重载本质上是函数重载
//Complex c3=c1+2;因为要将返回的对象赋值给c3，返回了一个新的对象，这里c1和c2对象是不发生改变的
//而上面的那个Add会将c1对象发生改变，所以不能返回*this
Complex Complex::operator+(const Complex& other)
{
    int r = real_ + other.real_;
    int i = imag_ + other.imag_;

    return Complex(r, i); 
}

Complex operator+(const Complex& c1, const Complex& c2);
{
    int r = c1.real_ + c2.real_;
    int i = c1.imag_ + c2.imag_;

    return Complex(r, i); 
}


void Complex::Display() const
{
    cout<<real_<<"+"<<imag_<<"i"<<endl;
}
