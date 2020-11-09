#include "Test.h"

int main(void)
{
	Test t;
	t.Init();
	t.Display();//输出x=0 y=0 z=0

	t.Init(10);
	t.Display();//输出x=10 y=0 z=0
	return 0;
}