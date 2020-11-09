#include "String.h"

#include <cstring>//�ȼ���#include <string.h>
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

//�����ǳ�����������Լ�ʵ��һ���������캯��
String::String(const String& other) : str_(other.str_)
{

}

//����������Լ�ʵ��һ���������캯��
String::String(const String& other)
{
	str_ = AllocAndCpy(other.str_);
}

//����String&�����ٿ������캯���ĵ��ã���������Ķ���
String& String::operator =(const String &other)
{
	//����ֵ������
	if (this == &other)
		return *this;
	
	//�Ⱥ��������ζ����ߵĶ����Ѿ������ˣ�����������
	//���������캯��˵�����󻹲����ڣ����Բ���������
	delete[] str_;
	str_ = AllocAndCpy(other.str_);
	return *this;
}

char* String::AllocAndCpy(char* str)
{
	int len = strlen(str) + 1;//������ô�����ַ���
	char* tmp = new char[len];//����ռ�
	memset(tmp, 0, len);
	strcpy(tmp, str);
	return tmp;
}

void String::Display()
{
	cout<<str_<<endl;
}