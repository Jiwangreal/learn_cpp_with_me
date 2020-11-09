#ifndef _TEST_H_
#define _TEST_H_

class Test
{
public:
	// 如果类不提供任何一个构造函数，系统将为我们提供一个不带参数的
	// 默认的构造函数
	Test();
	explicit Test(int num);//表示只能显式构造对象，不能隐式构造对象
	void Display();

	//将operator=看成一个函数，这是一个函数名
	Test& operator=(const Test& other);

	~Test();
private:
	int num_;
};
#endif // _TEST_H_