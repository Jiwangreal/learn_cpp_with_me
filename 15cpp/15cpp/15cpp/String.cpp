#include "String.h"

#include <cstring>//等价于#include <string.h>
#include <iostream>
using namespace std;

String::String(char* str/* = */)
{
	str_ = AllocAndCpy(str);
}

String::~String()
{
	delete[] str_;
}

//错误的浅拷贝做法：自己实现一个拷贝构造函数
String::String(const String& other) : str_(other.str_)
{

}

//深拷贝做法：自己实现一个拷贝构造函数
String::String(const String& other)
{
	str_ = AllocAndCpy(other.str_);
}

//返回String&：减少拷贝构造函数的调用，返回自身的对象
String& String::operator =(const String &other)
{
	//对象赋值给自身
	if (this == &other)
		return *this;
	
	//等号运算符意味着左边的对象已经存在了，所以先销毁
	//而拷贝构造函数说明对象还不存在，所以不用先销毁
	delete[] str_;
	str_ = AllocAndCpy(other.str_);
	return *this;
}

char* String::AllocAndCpy(char* str)
{
	int len = strlen(str) + 1;//分配这么长的字符串
	char* tmp = new char[len];//分配空间
	memset(tmp, 0, len);
	strcpy(tmp, str);
	return tmp;
}

void String::Display()
{
	cout<<str_<<endl;
}