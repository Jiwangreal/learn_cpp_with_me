#include <iostream>
using namespace std;

int main(void)
{
	//const int a;			Error，常量必须初始化
	const int a = 100;		
	//a = 200;				Error,常量不能重新被赋值

	int b = 22;
	const int * p;			//const在*左边，表示*p为常量，经由*p不能更改指针所指向的内容
	p = &b;
	//*p = 200;				Error,常量不能重新被赋值
	//int * const p2;		Error,p2为常量，常量必须初始化
	int * const p2 = &b;	//const在*右边，表示p2为常量
	//int c =100;
	//p2 = &c;				Error,常量不能重新被赋值
	*p2 = 200;

	cout<<b<<endl;

	return 0;
}