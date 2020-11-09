#include "Test.h"
#include <iostream>
using namespace std;

//内联成员函数的定义方法1
//inline int Test::Add(int a, int b)
//{
//	return a + b;
//}

//void Test::Init()
//{
//	x_ = 0;
//	y_ = 0;
//	z_ = 0;
//}
//
//void Test::Init(int x)
//{
//	x_ = x;
//	y_ = 0;
//	z_ = 0;
//}
//
//void Test::Init(int x, int y)
//{
//	x_ = x;
//	y_ = y;
//	z_ = 0;
//}
//
//void Test::Init(int x, int y, int z)
//{
//	x_ = x;
//	y_ = y;
//	z_ = z;
//}

void Test::Init(int x/* =0 */, int y/* =0 */, int z/* =0 */)//vs2010助手自动将缺省参数注释了
{
	x_ = x;
	y_ = y;
	z_ = z;
}

void Test::Display()
{
	cout<<"x="<<x_<<" y="<<y_<<" z="<<z_<<endl;
}