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