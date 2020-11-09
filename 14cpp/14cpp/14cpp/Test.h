#ifndef _TEST_H_
#define _TEST_H_

class Test
{
public:
	// 如果类不提供任何一个构造函数，系统将为我们提供一个不带参数的
	// 默认的构造函数
	Test();
	explicit Test(int num);

	//为啥不能是这样？Test(const Test other);
	//实参t初始化同一种类型的对象other，若不用引用，则是值传递，实参调用形参调用拷贝构造函数，调用
	//到拷贝构造函数又涉及到实参初始化形参，会调用拷贝构造函数，所以这边应该调用拷贝构造函数
	//引用没有自己独立的地址空间，它与实参共享同一个空间，所以不会再构造出一个对象出来了
	//用引用传递可以减少内存的复制，对象的拷贝，可以提供效率
	Test(const Test& other);//拷贝构造函数：所接受的参数是对象的引用
	void Display();

	Test& operator=(const Test& other);

	~Test();
private:
	int num_;
};
#endif // _TEST_H_