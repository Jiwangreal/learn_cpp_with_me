#include "String.h"
#include <iostream>
using namespace std;


int main(void)
{
	String s1("abc");
	String s2(s1);//此时会调用拷贝构造函数

	String s3;
	s3 = s1;//此时会调用=等号运算符，即赋值运算符
	s3.Display();

	//（1）目前这么写的话："xxxx"执行等号运算符，等号运算符可以接收一个字符串：String& operator=(const char* str);
	//（2）若不写（1）的方式，若explicit String(const char* str="");写成：String(const char* str="");先把"xxxx"转换构造成
	//为一个对象，然后再调用等号运算符
	s3 = "xxxx";
	s3.Display();

	String s4;
	bool notempty;
	notempty = !s4;//现在字符串为空
	cout<<notempty<<endl;

	s4 = "aaaa";
	notempty = !s4;//现在字符串非空
	cout<<notempty<<endl;

	return 0;
}