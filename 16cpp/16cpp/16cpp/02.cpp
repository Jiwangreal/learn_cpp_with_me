#include <iostream>
using namespace std;

class Test
{
public:
	Test()
	{

	}
	~Test()
	{

	}
	
	//整型static const成员可以在类定义体中初始化，该成员可以不在类体外进行定义
	static const int x_ = 100;		// static const整型成员其初始化可以在类中进行，其语法在vc6中是不允许的
};

const int Test::x_;					// 静态成员的定义性说明

int main(void)
{
	cout<<Test::x_<<endl;
}