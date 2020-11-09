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

    //��Ԫ�������أ��ȳ�Ա�������ض�һ����������Ϊ��Ԫ����������ĳ�Ա����û������һ��������󣨵�һ��������
    friend Complex operator+(const Complex& c1, const Complex& c2);

private:
    int real_;
    int imag_;
};




#endif /* _CONPLEX_H_ */