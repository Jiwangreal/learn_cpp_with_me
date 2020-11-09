#include "Test.h"
#include <iostream>
using namespace std;

// 不带参数的构造函数称为默认构造函数
Test::Test() : num_(0)
{
	//num_ = 0;
	cout<<"Initializing Default"<<endl;
}

Test::Test(int num) : num_(num)
{
	//num_ = num;
	cout<<"Initializing "<<num_<<endl;
}

Test::Test(const Test& other) : num_(other.num_)
{
	//num_ = other.num_;//函数体中初始化本质是赋值，不是初始化
	cout<<"Initializing with other "<<num_<<endl;
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
	if (this == &other)
		return *this;

	num_ = other.num_;
	return *this;
}