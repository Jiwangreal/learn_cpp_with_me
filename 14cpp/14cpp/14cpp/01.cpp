#include "Test.h"

int main(void)
{
	Test t(10);
	//Test t2(t);		// 用t对象初始化t2对象，调用拷贝构造函数
	Test t2 = t;		// 等价于Test t2(t);这里的=不是运算符，编译器对他会有特殊的解释

	return 0;
}