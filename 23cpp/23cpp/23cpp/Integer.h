#ifndef _INTEGER_H_
#define _INTEGER_H_

class Integer
{
public:
	Integer(int n);
	~Integer();

	//友元函数的重载都比成员函数的重载多一个参数，因为成员函数隐含了一个自身的参数对象
	//++运算符推荐使用成员函数的方式重载，因为友元函数的重载相当于多了一些全局的函数，在很有必要的情况下，才去用

	//前置运算符重载，在VC6.0中，这俩不能共存，所以需要注释掉一个
	Integer& operator++();
	//friend Integer& operator++(Integer& i);

	//后置运算符重载，int n参数仅仅为了区分前置，这样才能构成重载
	Integer operator++(int n);
	//friend Integer operator++(Integer& i, int n);

	void Display() const;
private:
	int n_;
};

#endif // _INTEGER_H_