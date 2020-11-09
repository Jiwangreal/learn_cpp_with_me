#include "Clock.h"

//main是类外部的代码
int main(void)
{
	Clock c;//把类看成一种类型。类是抽象的，对象是具体的
	c.Init(10, 10, 10);
	c.Display();//输出为10：10：10
	//c.second_ += 1;
	c.Update();//输出为10：10：11
	c.Display();

	//c.hour_ = 11;
	c.SetHour(11);//输出为11：10：11
	c.Display();

	return 0;
}