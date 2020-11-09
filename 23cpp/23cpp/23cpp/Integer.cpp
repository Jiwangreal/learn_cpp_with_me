#include "Integer.h"
#include <iostream>
using namespace std;

Integer::Integer(int n) : n_(n)
{
}

Integer::~Integer()
{
}

//前置运算符
//以成员函数的方式重载
//返回的是引用，不会调用拷贝构造函数
Integer& Integer::operator ++()
{
	//cout<<"Integer& Integer::operator ++()"<<endl;
	++n_;
	return *this;
}

//以友元的方式来重载
//Integer& operator++(Integer& i)
//{
//	//cout<<"Integer& operator++(Integer& i)"<<endl;
//	++i.n_;
//	return i;
//}


//后置运算符
Integer Integer::operator++(int n)
{
	//cout<<"Integer& Integer::operator ++()"<<endl;
	//n_++;
	//返回的对象没有++，自身的对象已经++
	Integer tmp(n_);//返回一个临时对象，该临时对象的生存期就是该函数括号内，返回后就消失了
	n_++;
	return tmp;
}

//Integer operator++(Integer& i, int n)
//{
//	Integer tmp(i.n_);
//	i.n_++;
//	return tmp;
//}

void Integer::Display() const
{
	cout<<n_<<endl;
}