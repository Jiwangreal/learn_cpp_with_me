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

	//非静态成员函数
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
								//原因四静态成员函数没有this指针，没有this指针指向某个对象，而y_是属于某个对象的，
								//既然它没有this指针指向某个对象，因而它不能访问非静态成员（非静态成员是不被所有对象共享的，
								//是每个对象都有的一份拷贝）
	}
	static int x_;		// 静态成员的引用性说明
	int y_;
};

int Test::x_ = 100;		// 静态成员的定义性说明

int main(void)
{
	Test t(10);
	cout<<Test::x_<<endl;
	t.TestFun();

	cout<<t.x_<<endl;		// 可以访问，但不推荐这么使用，因为x_是属于类的，这样写会误认为x_属于对象t
}