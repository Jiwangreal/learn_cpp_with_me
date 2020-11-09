#include "Test.h"

int main(void)
{
	//构造函数无法显式调用，析构函数可以显式调用，但一般很少用。
	Test t;
	t.~Test();	
	return 0;
}