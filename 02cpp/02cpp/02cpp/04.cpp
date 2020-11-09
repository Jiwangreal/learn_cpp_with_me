#include <iostream>
using namespace std;
#include <stdio.h>

#pragma pack(2)//可以修改vs2010以及linux g++的内存对齐数
struct Test
{
	char a;
	double b;
	char c;
};
#pragma pack()//取消内存对齐

//第一个成员与结构体变量的偏移量为0
//其它成员要对齐打某个数字(对齐数)的整数倍的地址
//对齐数取编译器预设的一个对齐整数与该成员大小的较小值
//结构体总大小为最大对齐数的整数倍，若走vs2010默认对齐数的话，sizeof(Test)=24
//vs2010的对齐数可以取1，2，4，8，16，linux g++的话只能取1，2，4

int main(void)
{
	Test test;
	//&test = &test.a;
	char *p= (char*)&test;
	//cout<<p<<endl;
	printf("p=%p\n", p);//地址值一样
	p = &test.a;
	printf("p=%p\n", p);//地址值一样

	cout<<sizeof(Test)<<endl;
	return 0;
}