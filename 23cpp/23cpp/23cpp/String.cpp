#pragma warning(disable:4996)//����VS2008��4096�ľ���
#include "String.h"
#include <string.h>
#include <iostream>
using namespace std;

String::String(const char* str)
{
	str_ = AllocAndCpy(str);
}


//�������캯��
String::String(const String& other)
{
	//�������죬��ζ�����������ǰ�����ڣ����Բ���ɾ��
	str_ = AllocAndCpy(other.str_);
}

//��û���ṩ��ֵ�������Ĭ��Ҳ��ǳ������
//��Ϊeg��s1=s2
//s1.str_=s2.str_;Ҳ����ڣ�����2�������ͷŵ�ʱ�����������Ὣָ����ָ����ڴ��ͷ�2��
String& String::operator=(const String& other)
{
	//Ϊ�˷�ֹs1=s1;
	if (this == &other)
		return *this;

	//��ֵ��������ζ����������Ѿ������ˣ�ԭ���Ŀռ�Ҫ��ɾ��
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
	//�ж��ַ����ǿգ�ֻ��Ҫ�ж��ַ������Ȳ�����0
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