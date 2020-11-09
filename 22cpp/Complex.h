#ifndef _CONPLEX_H_
#define _CONPLEX_H_

class Complex
{
public:
    Complex(int real, int imag);
    Complex();
    ~Complex();

    Complex& Add(const Complex& other);
    void Display() const;

    Complex operator+(const Complex& other);

    //友元函数重载，比成员函数重载多一个参数，因为友元函数不是类的成员，它没有隐含一个自身对象（第一个参数）
    friend Complex operator+(const Complex& c1, const Complex& c2);

private:
    int real_;
    int imag_;
};




#endif /* _CONPLEX_H_ */