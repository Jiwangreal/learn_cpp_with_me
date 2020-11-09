#ifndef _B_H_
#define _B_H_

class A;
//#include "A.h"
class B
{
public:
	B(void);
	~B(void);

	A a_;////定义A类对象，要：include A的头文件,但是A.h的类也定义了B的对象，两个类互相定义对象，造成环形引用
	void fun(A& a)//类A放在形参位置，也只能是形参或者引用，也不能实例化为对象
	{

	}

	A* a_;		//class A;前向声明的类不能实例化对象，无法为对象a_分配内存，但是可以定义指针或者引用
};

#endif // _B_H_