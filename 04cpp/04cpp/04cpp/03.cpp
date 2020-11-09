#include <iostream>
using namespace std;


void swap(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}

int main(void)
{
	int a = 5;
	int b = 6;

	swap(a, b);		//在函数调用时，进行初始化x = a, y = b;对引用x所做的改变，可以改变x所指向a的值的改变

	cout<<"a="<<a<<" b="<<b<<endl;
	return 0;
}