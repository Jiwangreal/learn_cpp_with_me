#include <iostream>
using namespace std;

// 不能返回对局部变量的引用。


int& add(int a, int b)
{
	int sum;
	sum = a + b;
	return sum;
}

int main(void)
{
	int n = add(3, 4);
	int& n2 = add(5, 6);		// n2是引用，没有自己独立的空间
								// n2的值依赖于它所引用的变量
								// 如果n2所引用的变量的生命周期结束了，也就是说n2是一个
								// 无效的引用，那么n2的值将是不确定的
	cout<<"n2="<<n2<<endl;//输出11
	cout<<"n="<<n<<endl;//输出7，返回时将局部变量sum的值已经覆盖了，所以会出现乱码，所以不要对返回
	//的局部变量进行引用
	cout<<"n2="<<n2<<endl;//输出乱码
	return 0;
}