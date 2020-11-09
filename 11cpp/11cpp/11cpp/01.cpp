#include "Test.h"

int main(void)
{
	//构造函数被重载
	//t和t2是栈上的内存，其作用域在花括号内，当程序跳出花括号，就要释放这俩对象
	//t和t22内存释放的顺序与创建的顺序相反
	Test t;//新建一个对象的时候，构造函数会被自动调用
	t.Display();

	Test t2(10);
	t2.Display();

	//定义一个动态对象，会调用带一个参数的构造函数
	//new与malloc的区别：不仅分配内存，还调用了构造函数，所以称之为：new operator
	//t3是堆内存
	Test* t3 = new Test(20);
	t3->Display();

	//delete不仅释放内存，还调用了析构函数
	delete t3;//动态分配的内存需要自己释放

	
	return 0;
}