#include "Integer.h"
#include <iostream>
using namespace std;

int add(int a, int b)
{
	return a + b;
}

int main(void)
{
	Integer n(100);
	n = 200;//通过转换构造函数Integer(int n);也叫构造函数，可以将200转换为类类型，赋值给n
	n.Display();

	int sum = add(n, 100);

	cout<<sum<<endl;

	int x = n;//隐式转换：调用类型转换运算符operator int();
	int y = static_cast<int>(n);//显示转换，调用类型转换运算符operator int();

	return 0;
}