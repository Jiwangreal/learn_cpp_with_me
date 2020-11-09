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
	//Ϊ�˱���return str_[index];�ظ�����Ӧ����
	//non const �汾���� const�汾

	//����const����ת��Ϊconst����static_cast<const String&>(*this)
	//static_cast<const String&>(*this)[index]�Ϳ��Ե��õ�const char& String::operator[](unsigned int index) const�������
	//Ȼ�󷵻�ֵȥ��������const
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
	//String tmp(newstr);//��Ϊ���ص���һ����������Ҫ����һ����ʱ�������ֱ�ӹ���һ������
	//���أ�return String(newstr);��Ϊ���캯�������һ���ռ䣬����newstr���޷��ͷ�
	//delete newstr;
	String str = s1;
	str += s2;//����+=�����
	return str;
}

String& String::operator+=(const String& other)
{
	int len = strlen(str_) + strlen(other.str_) + 1;
	char* newstr = new char[len];
	memset(newstr, 0, len);
	strcpy(newstr, str_);//����
	strcat(newstr, other.str_);//other

	//Ҫ�ŵ��������
	delete[] str_;

	str_ = newstr;
	return *this;
}

ostream& operator<<(ostream& os, const String& str)
{
	os<<str.str_;//��Ϊ�ڲ���<<������Ѿ����غ���char*���Զ��������String��û�취���ص�
	return os;
}

istream& operator>>(istream& is, String& str)
{
	char tmp[1024];
	cin>>tmp;
	str = tmp;
	return is;
}