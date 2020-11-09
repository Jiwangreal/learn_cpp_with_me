#ifndef _STRING_H_
#define _STRING_H_
//#include <iostream>等一般不会包含在头文件当中，而这里使用了ostream类型，则需要包含
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

	//为什么要返回引用？
	//因为一个函数返回引用的话，那么它就可以出现在表达式的左边
	char& operator[](unsigned int index);
	const char& operator[](unsigned int index) const;

	//+运算符是二元运算符，既可以用+运算符来重载，也可以用友元的方式来重载，推荐用友元的方式
	//const String& s1用引用的原因是：参数传递过来，会少一次拷贝构造
	friend String operator+(const String& s1, const String& s2);

	//+=运算符重载，最好以成员函数的方式重载
	//返回的时候用引用，避免返回时对象的拷贝
	String& operator+=(const String& other);

	//输出为string对象
	//cout的类型是ostream
	//返回的是流对象的引用，可以继续输出
	friend ostream& operator<<(ostream& os, const String& str);

	//输入到字符串str中
	friend istream& operator>>(istream& is, String& str);
	~String(void);

	void Display() const;

private:
	String& Assign(const char* str);
	char* AllocAndCpy(const char* str);
	char* str_;
};

#endif // _STRING_H_
