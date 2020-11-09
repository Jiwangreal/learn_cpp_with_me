#pragma warning(disable:4996)//屏蔽VS2008中4096的警告
#include "String.h"
#include <string.h>
#include <iostream>
using namespace std;

String::String(const char* str)
{
	str_ = AllocAndCpy(str);
}


//拷贝构造函数
String::String(const String& other)
{
	//拷贝构造，意味着这个对象先前不存在，所以不用删除
	str_ = AllocAndCpy(other.str_);
}

//若没有提供赋值运算符，默认也是浅拷贝的
//因为eg：s1=s2
//s1.str_=s2.str_;也会存在：档当2个对象释放的时候，析构函数会将指针所指向的内存释放2次
String& String::operator=(const String& other)
{
	//为了防止s1=s1;
	if (this == &other)
		return *this;

	//赋值操作，意味着这个对象已经存在了，原来的空间要先删除
	delete[] str_;
	str_ = AllocAndCpy(other.str_);
	return *this;
}

String& String::operator=(const char* str)
{
	delete[] str_;
	str_ = AllocAndCpy(str);
	return *this;
}

bool String::operator!() const
{
	//判断字符串非空，只需要判断字符串长度不等于0
	return strlen(str_) != 0;
}

String::~String()
{
	delete[] str_;
}

char* String::AllocAndCpy(const char* str)
{
	int len = strlen(str) + 1;
	char* newstr = new char[len];
	memset(newstr, 0, len);
	strcpy(newstr, str);

	return newstr;
}

void String::Display() const
{
	cout<<str_<<endl;
}