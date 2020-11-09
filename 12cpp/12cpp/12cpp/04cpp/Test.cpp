#include "Test.h"
#include <iostream>
using namespace std;

// 不带参数的构造函数称为默认构造函数
Test::Test()
{
	num_ = 0;
	cout<<"Initializing Default"<<endl;
}

Test::Test(int num)
{
	num_ = num;
	cout<<"Initializing "<<num_<<endl;
}

Test::~Test()
{
	cout<<"Destroy "<<num_<<endl;
}

void Test::Display()
{
	cout<<"num="<<num_<<endl;
}

Test& Test::operator=(const Test& other)
{
	cout<<"Test::operator="<<endl;
	//可以防止t=t，同一个对象防止赋值
	if (this == &other)
		return *this;
	//不同的对象。内容相同，也不做赋值，则需要用if (*this == other)，
	//但是前提是==号运算符需要重载
	

	//将other对象中每一个成员，赋值给当前对象的每一个成员，逐成员赋值
	num_ = other.num_;
	return *this;//返回对象自身
}