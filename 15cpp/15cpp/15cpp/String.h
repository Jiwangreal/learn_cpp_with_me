#ifndef _STRING_H_
#define _STRING_H_

class String
{
public:
	String(char* str="");//默认参数是空串
	~String();
	String(const String& other);
	String& operator=(const String& other);

	

	void Display();

private:
	char* AllocAndCpy(char* str);
	
	char* str_;//类内部涉及到动态内存分配，则使用深拷贝，除了共享内存

	//禁止拷贝的做法：若是独一无二的对象，独一无二的对象不允许拷贝，将声明以及实现都注释掉，所以会导致编译出错
	// String(const String& other);
	// String& operator=(const String& other);
};

#endif // _STRING_H_
