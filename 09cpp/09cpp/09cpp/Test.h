#ifndef _TEST_H_
#define _TEST_H_

class Test
{
public:
	//定义内联函数的方法2，直接在类体中实现就是内联的
	//2种内联方法仅是给编译器一种提示，但是编译器会根据代码的长度来决定是否将其解析为内联的
	int Add(int a, int b)
	{
		return a + b;
	}

	//函数重载必须在相同的作用域中！！
	//所以，类成员函数重载也必须在同一个类作用域中
	//void Init();
	//void Init(int x);
	//void Init(int x, int y);
	//void Init(int x, int y, int z);

	
	//缺省参数的使用
	//在参数有缺省值时，要注意避免二义性！！
	//void Init(int x=0, int y=0, int z=0);和void Init();不要同时使用，因为在main中使用t.Init();初始化对象时
	//后者可以解析成前者的函数调用，造成函数二义性问题
	void Init(int x=0, int y=0, int z=0);

	void Display();

private:
	int x_;
	int y_;
	int z_;
};
#endif // _TEST_H_
