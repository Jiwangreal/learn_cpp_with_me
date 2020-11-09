#ifndef _STRING_H_
#define _STRING_H_

class String
{
public:
	explicit String(const char* str="");

	//拷贝构造函数实现深拷贝
	//构造函数不能有返回值，拷贝构造函数也是构造函数
	String(const String& other);

	String& operator=(const String& other);
	String& operator=(const char* str);

	//!是一元操作符，=号是二元操作符重载，因为s3=s1，操作数是s3和s1
	bool operator!() const;//const不会改变类数据成员
	~String(void);

	void Display() const;

private:
	char* AllocAndCpy(const char* str);
	char* str_;//这样的情况，一定要提供拷贝构造函数，实现深拷贝
};

#endif // _STRING_H_
