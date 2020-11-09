#include <iostream>
using namespace std;

struct Test2
{
	int x_;
	int y_;
	int z_;
	void Init(int x, int y, int z)//结构体中可以有成员函数，默认是公有的
	{
		x_ = x;
		y_ = y;
		z_ = z;
	}
	void Display()
	{
		cout<<"x="<<x_<<" y="<<y_<<" z="<<z_<<endl;
	}
};

class Test3
{
public:
	int x_;
	int y_;
	int z_;
	void Init(int x, int y, int z)
	{
		x_ = x;
		y_ = y;
		z_ = z;
	}
	void Display()
	{
		cout<<"x="<<x_<<" y="<<y_<<" z="<<z_<<endl;
	}
};
int main(void)
{
	//C++初始化结构体的方式
	//在C++中，将结构体可以当成类，直接写成：Test2 t
	//在C语言中，必须要写成：struct Test2 t
	//Test2 t;
	//t.Init(10, 20, 30);
	//t.Display();

	//C语言初始化结构体的方式
	//Test2 t2 = {10, 20, 30};
	//t2.Display();

	//C++类的初始化方式1
	//Test3 t3;
	//t3.Init(10, 20, 30);

	//C++类的初始化方式2
	Test3 t3 = {10, 20, 30};
	t3.Display();//输出x=10 y=20 z=30
	return 0;
}