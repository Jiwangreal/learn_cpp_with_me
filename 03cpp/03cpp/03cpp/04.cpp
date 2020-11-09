#include <iostream>
using namespace std;

int fun(int a, int b=5)
{
	return a + b;
}

int fun(int a, int b, int c);//声明给出默认值，定义的时候就不需要给默认值


int main(void)
{
	cout<<fun(3)<<endl;//输出为8
	cout<<fun(3, 4)<<endl;//输出为7
	cout<<fun(3,4,5)<<endl;//输出为12
	return 0;
}

int fun(int a, int b, int c)
{
	return a + b + c;
}