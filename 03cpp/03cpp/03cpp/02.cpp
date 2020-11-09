#include <iostream>
using namespace std;

int main(void)
{
	int* p = new int;			//分配一个整数空间
	cout<<*p<<endl;//输出为任意值

	int* p1 = new int(33);			//分配一个整数空间4字节，初始值为33， ()表示只分配一个空间，对该空间进行初始化
	cout<<*p1<<endl;//输出为33

	int* p2 = new int[10];		//分配连续的10个整数空间 ，共40字节，[]表示分配连续的n个数据类型的空间

	delete p;
	delete[] p2;
	return 0;
}