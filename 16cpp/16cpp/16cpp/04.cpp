#include <iostream>
using namespace std;

class Test
{
public:
	Test(int y) : y_(y)
	{

	}
	~Test()
	{

	}

	void TestFun()
	{
		cout<<"x="<<x_<<endl;	//OK,非静态成员函数可以访问静态成员
		TestStaticFun();
	}
	static void TestStaticFun()
	{
		cout<<"TestStaticFun ..."<<endl;
		//TestFun();		Error,静态成员函数不能调用非静态成员函数
		//cout<<"y="<<y_<<endl;		Error,静态成员函数不能访问非静态成员
	}
	static int x_;		// 静态成员的引用性说明
	int y_;
};

int Test::x_ = 100;		// 静态成员的定义性说明

int main(void)
{
	//类大小与成员函数无关，与静态数据成员无关
	cout<<sizeof(Test)<<endl;
}