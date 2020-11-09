#include "Test.h"

int main(void)
{

	//不通过，原因是：阻止隐式转化，初始化语句就不等价于Test t(10)
	Test t = 10;		

	//不通过
	Test t;
	t = 10;//不会通过的原因是：此时要转换一个临时对象出来赋值给t

	return 0;
}