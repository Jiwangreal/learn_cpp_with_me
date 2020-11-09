#include "Test.h"
#include <iostream>
using namespace std;

void TestFun(const Test t)//对象t的作用域在块作用域以内，当生存期结束，就会销毁
{

}

void TestFun2(const Test& t)
{

}

//将对象t拷贝构造到一个临时对象中去
Test TestFun3(const Test& t)
{
    //所返回的对象与对象t是不同的
	return t;
}

const Test& TestFun4(const Test& t)
{
	//return const_cast<Test&>(t);//去除const属性
	return t;
}

//TestFun4也可以这么写：
//  Test& TestFun4(const Test& t)
// {
// 	return const_cast<Test&>(t);//去除const属性
// 	return t;
// }

int main(void)
{
	Test t(10);
	//t = TestFun3(t);//产生一个临时对象，将临时对象赋值给t（调用等号运算符），接着临时对象会马上销毁
	//Test t2 = TestFun3(t);//在返回对象的时候要调用拷贝构造函数，构造了一个临时对象，临时对象被t2接管
                            //TestFun3(t)产生的临时对象不会马上销毁，临时对象改名字成为了t2有名对象，会被有名对象t2接管

	//Test& t2 = TestFun3(t);//Destroy在....之后，临时对象不会马上销毁，这里的拷贝构造函数是在函数返回对象的时候调用的

	//Test t2 = TestFun4(t);//返回对象的时候，并没有调用拷贝构造函数，返回对象的引用，然后将对象初始化到t2，调用拷贝构造函数
	const Test& t2 = TestFun4(t);//不再调用拷贝构造函数，因为是引用t2接收的，引用要和返回的对象t共享一个内存空间
	cout<<"........"<<endl;

	return 0;
}