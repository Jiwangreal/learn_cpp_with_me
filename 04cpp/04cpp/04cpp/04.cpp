#include <iostream>
using namespace std;

// 引用作为函数返回值

int a[] = {0,1,2,3,4};

int& index(int i)
{
	return a[i];
}

int main(void)
{
	index(3) = 100;		//引用作为函数返回值，使得函数可以放在赋值运算符左边
						// 函数返回引用，引用在函数返回的时候初始化
						//即：index(3)在函数返回的时候被初始化为a[3]
	
	cout<<"a[3]="<<a[3]<<endl;//输出为100
	return 0;
}