#include <iostream>
using namespace std;

class Test
{
public:
	int num_;
};

//num_ = 20;		Error,num_的作用域在类内部
int num_ = 20;		// （1）num_的作用域是文件作用域，与类中的num_是不同的作用域

int add(int a, int b);	// （3）a, b两个标识符的作用域为函数原型作用域，只在函数括号内可见，还可以写成int add(int , int );
						//但是不能写成：int add(int a, int a);

int main(void)
{
	int num_ = 30;		// （2）num_Ϊ为块作用域
	{
		int num_ = 100;	// （2）num_Ϊ为块作用域
	}

	cout<<num_<<endl;//输出30
	cout<<::num_<<endl;//输出20
	return 0;
}

int add(int a, int b)	// （3）形参a与形参b也算是块作用域
{
	return a + b;
}

int test()
{
LABEL1://（4）函数作用域：LABEL1标签只在函数内部有效，仅仅针对go to语句来说的
	cout<<"label1"<<endl;
	goto LABEL3;
LABEL2:
	cout<<"label2"<<endl;
	goto LABEL1;
LABEL3:
	cout<<"label3"<<endl;
	goto LABEL2;
}