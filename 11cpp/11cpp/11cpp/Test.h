#ifndef _TEST_H_
#define _TEST_H_

class Test
{
public:
	// 如果类不提供任何一个构造函数，系统将为我们提供一个不带参数的
	// 默认的构造函数
	Test();//若将Test()声明为private的，说明在外部不可见，连main函数都看不到，编译都不会通过
	Test(int num);//提供一个带参数的构造函数，则系统也不再提供一个不带参数的默认构造函数了
	void Display();


	//析构函数不能被重载，意味着析构函数不能有参数
	~Test();
private:
	int num_;
};
#endif // _TEST_H_