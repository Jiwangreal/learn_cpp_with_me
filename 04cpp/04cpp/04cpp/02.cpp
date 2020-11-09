#include <iostream>
using namespace std;

//const引用是指向const对象的引用

int main(void)
{
	const int val = 1024;
	const int& refval = val;

	//int& ref2 = val;	// Error,nonconst reference to const object，非const引用指向const对象是不允许的

	//refval = 200;		Error,refval是一个常量

	int val2 = 1024;
	const int& ref3 = val2;	//const reference to nonconst object，const引用可以指向非const对象

	double val3 = 3.14;			//等价于下面的语句
	const int& ref4 = val3;		// int temp = val3;
								// const int& ref4 = temp;
								//这里会产生临时变量，这里ref4实际指向的是temp

	//int& ref5 = val3;		Error，不会等价于上面的语句

	cout<<"ref4="<<ref4<<endl;//输出3
	cout<<"val3="<<val3<<endl;//输出3.14

	

	return 0;
}