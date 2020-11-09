#include "Test.h"
#include <iostream>
using namespace std;

void TestFun(const Test t)//对象t的作用域在块作用域以内，当生存期结束，就会销毁
{

}

void TestFun2(const Test& t)
{

}

Test TestFun3(const Test& t)
{
	return t;
}

const Test& TestFun4(const Test& t)
{
	//return const_cast<Test&>(t);
	return t;
}

int main(void)
{
	Test t(10);
	TestFun(t);//会调用拷贝构造函数
	TestFun2(t);//不会调用拷贝构造函数，因为传递的是引用，这里形参不会构造一个对象，分配内存，形参和实参共享同一块内存


	return 0;
}