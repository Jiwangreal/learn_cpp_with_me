#ifndef _STRING_H_
#define _STRING_H_
//#include <iostream>��һ�㲻�������ͷ�ļ����У�������ʹ����ostream���ͣ�����Ҫ����
#include <iostream>
using namespace std;

class String
{
public:
	String(const char* str="");
	String(const String& other);
	String& operator=(const String& other);
	String& operator=(const char* str);

	bool operator!() const;

	//ΪʲôҪ�������ã�
	//��Ϊһ�������������õĻ�����ô���Ϳ��Գ����ڱ��ʽ�����
	char& operator[](unsigned int index);
	const char& operator[](unsigned int index) const;

	//+������Ƕ�Ԫ��������ȿ�����+����������أ�Ҳ��������Ԫ�ķ�ʽ�����أ��Ƽ�����Ԫ�ķ�ʽ
	//const String& s1�����õ�ԭ���ǣ��������ݹ���������һ�ο�������
	friend String operator+(const String& s1, const String& s2);

	//+=��������أ�����Գ�Ա�����ķ�ʽ����
	//���ص�ʱ�������ã����ⷵ��ʱ����Ŀ���
	String& operator+=(const String& other);

	//���Ϊstring����
	//cout��������ostream
	//���ص�������������ã����Լ������
	friend ostream& operator<<(ostream& os, const String& str);

	//���뵽�ַ���str��
	friend istream& operator>>(istream& is, String& str);
	~String(void);

	void Display() const;

private:
	String& Assign(const char* str);
	char* AllocAndCpy(const char* str);
	char* str_;
};

#endif // _STRING_H_
