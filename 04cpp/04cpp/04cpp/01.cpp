#include <iostream>
using namespace std;

/*
引用与变量的区别：
变量：名称+空间；
引用不是变量；
引用仅仅是变量的别名；
引用没有独立的空间；
引用要与他所引用的变量共享空间；
对引用所做的改变实际上是对它所引用的变量的改变；
*/

//引用在定义的时候要进行初始化
//引用一经初始化，不能重新指向其它变量

int main(void)
{
	int val = 100;
	//int& refval;			Error,引用必须进行初始化
	int& refval = val;
	refval = 200;			// 将200赋值给refval
							// 实际上改变的是val这个变量

	cout<<"val="<<val<<endl;

	int val2 = 500;
	refval = val2;			// 不代表将refval引用至val2这个变量
							// 仅仅只是代表将val2赋值给refval

	cout<<"val="<<val<<endl;

	return 0;
}