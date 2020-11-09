#include "String.h"
#include <iostream>
using namespace std;

int main(void)
{
	String s1("abcdefg");

	char ch = s1[2];
	cout<<ch<<endl;

	//一个函数返回引用的话，那么它就可以出现在表达式的左边，这就是返回引用的好处
	s1[2] = 'A';
	s1.Display();

	const String s2("xyzabc");//会调用：const char& String::operator[](unsigned int index) const
	ch = s2[2];
	//s2[2] = 'M';//因为s2是const常量，不允许这种操作，所以返回的引用是const引用即可
	s2.Display();


	String s3 = "xxx";
	String s4 = "yyy";

	String s5 = s3 + s4;//这里要返回一个新对象，赋值给s5，不能修改s3和s4对象的值
	s5.Display();

	//因为“aaa”可以调用String(const char* str="");转换构造成一个字符串类对象
	//因为这里是以友元的方式来重载的，而不能用成员函数的方式，成员函数重载隐含的第一个参数是对象自身，而不是字符串
	String s6 = "aaa" + s3 + "sdfadfa" + "xxxx";
	//String s6 = "xxx" + "aaa" + s3 + "sdfadfa" + "xxxx";//这样不允许，因为没有重载2个char*，所以在做加法时，
	//前2个至少有一个是对象
	s6.Display();

	s3+=s4;
	s3.Display();

	//插入运算符是二元的，第一个运算符是输出流对象cout，第二个参数是要输出的对象本身s3
	//不能以成员函数的方式重载，因为若以成员函数的方式重载，第一个操作会变成对象自身，这明显是不合理的
	cout<<s3<<endl;

	String s7;
	cin>>s7;//从键盘输入
	cout<<s7<<endl;



	return 0;
}