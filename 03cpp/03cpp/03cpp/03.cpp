#include <iostream>
using namespace std;


void fun(int a, int b)
{
	cout<<"int fun"<<endl;
}

void fun(double a, double b)
{
	cout<<"double fun"<<endl;
}

//extern "C"表示不进行名字改编，而按照C语言的方式解释函数名,就是不支持函数重载了
extern "c" void fun(int a)
{
	cout<<"xxxx"<<endl;
}

#ifdef __cpluscplus  //C++语言有定义该宏的，目的是为了可将下面的代码放置头文件中，让C++的程序也能被C语言使用
//extern "C"可以括起来多个函数
extern "C"
{
#endif
void fun(int a)
{
	cout<<"xxxx"<<endl;
}
void fun2(double a)
{
	cout<<"yyyy"<<endl;
}
#ifdef __cpluscplus
}
#endif

/*
若头文件是a.h，头文件只有函数声明，实现放在c++中，但是提供的头文件
也可以被C语言所使用
#ifdef __cpluscplus  
extern "C"
{
#endif
void fun(int a)
void fun2(double a)

#ifdef __cpluscplus
}
#endif


*/



int main(void)
{
	fun(3,4);
	fun(3.3, 4.4);
	fun(3);
	return 0;
}