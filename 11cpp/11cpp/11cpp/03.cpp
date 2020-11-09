#include "Test.h"

int main(void)
{
	//创建了一个对象数组，其中有两个对象，会调用2次构造函数
	//当数组t生命周期结束的时候，会调用析构函数
	Test t[2] = {10, 20};

	//创建一个test对象，传递参数2
	Test* t2 = new Test(2);
	delete t2;

	//这里相当于没有传递任何参数，创建了2个对象，调用默认构造函数
	Test* t3 = new Test[2];
	delete[] t3;//若创建的是数组：Test[2]，delete的中括号不要省略
	//delete不仅调用析构函数，还会对内存进行释放
	return 0;
}