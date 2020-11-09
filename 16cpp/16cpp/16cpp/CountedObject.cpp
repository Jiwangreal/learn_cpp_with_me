#include "CountedObject.h"

//static数据成员与类关联的对象，被所有对象所共享
int CountedObject::count_ = 0;		// 静态成员的定义性声明（static成员的名字是在类的作用域中），static可以不需要了

CountedObject::CountedObject()
{
	//count_作用域在类作用域范围之内，所以没必要写成++CountedObject::count_;
	++count_;
}

CountedObject::~CountedObject()
{
	--count_;
}

int CountedObject::GetCount()
{
	return count_;
}
