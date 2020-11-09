#pragma warning(disable:4996)
#include "String.h"
#include <string.h>
//#include <iostream>
//using namespace std;

String::String(const char* str)
{
	str_ = AllocAndCpy(str);
}

String::String(const String& other)
{
	str_ = AllocAndCpy(other.str_);
}

String& String::operator=(const String& other)
{
	if (this == &other)
		return *this;

	return Assign(other.str_);
}

String& String::operator=(const char* str)
{
	return Assign(str);
}

String& String::Assign(const char* str)
{
	delete[] str_;
	str_ = AllocAndCpy(str);
	return *this;
}

bool String::operator!() const
{
	return strlen(str_) != 0;
}

char& String::operator[](unsigned int index)
{
	//return str_[index];
	//为了避免return str_[index];重复，则应该用
	//non const 版本调用 const版本

	//将非const对象转换为const对象：static_cast<const String&>(*this)
	//static_cast<const String&>(*this)[index]就可以调用到const char& String::operator[](unsigned int index) const这个函数
	//然后返回值去掉常量性const
	return const_cast<char&>(static_cast<const String&>(*this)[index]);
}

const char& String::operator[](unsigned int index) const
{
	return str_[index];
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

String operator+(const String& s1, const String& s2)
{
	//int len = strlen(s1.str_) + strlen(s2.str_) + 1;
	//char* newstr = new char[len];
	//memset(newstr, 0, len);
	//strcpy(newstr, s1.str_);
	//strcat(newstr, s2.str_);
	//
	//String tmp(newstr);//因为返回的是一个对象，所以要返回一个临时对象，如果直接构造一个对象
	//返回：return String(newstr);因为构造函数会分配一个空间，这里newstr会无法释放
	//delete newstr;
	String str = s1;
	str += s2;//调用+=运算符
	return str;
}

String& String::operator+=(const String& other)
{
	int len = strlen(str_) + strlen(other.str_) + 1;
	char* newstr = new char[len];
	memset(newstr, 0, len);
	strcpy(newstr, str_);//自身
	strcat(newstr, other.str_);//other

	//要放到自身对象
	delete[] str_;

	str_ = newstr;
	return *this;
}

ostream& operator<<(ostream& os, const String& str)
{
	os<<str.str_;//因为内部的<<运算符已经重载好了char*，自定义的类型String是没办法重载的
	return os;
}

istream& operator>>(istream& is, String& str)
{
	char tmp[1024];
	cin>>tmp;
	str = tmp;
	return is;
}