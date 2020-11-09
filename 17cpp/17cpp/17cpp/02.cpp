#include <iostream>
using namespace std;

class Test
{
public:
	Test(int n) : n_(n)
	{
		cout<<"Test "<<n_<<" ..."<<endl;
	}
	~Test()
	{
		cout<<"~Test "<<n_<<" ..."<<endl;
	}
private:
	int n_;
};

int n;			// 未初始化的全局变量，初始值为0。n存储于.bss段中。(bss含义：block started by symbol)
int n2 = 100;	// 已初始化的全局变量，初始值为100。n2存储于.data段中。
Test g(100);		// 全局对象的构造先于main函数
static Test g2(200);	//静态全局对象的构造也先于main函数

int main(void)
{
	cout<<"Entering main ..."<<endl;
	cout<<n<<endl;

	//作用域在main的括号之内（块作用域）
	Test t(10);		// 栈上创建的对象，在生存期结束的时候自动释放
	{				
		Test t(20);
	}

	{
		Test* t3 = new Test(30);		// 堆上创建的对象，要显示释放
		delete t3;
	}

	{
		//注意局部静态类对象和局部静态变量的区别
		static int n3;			// n3存储于.bss段中		（在编译期初始化，在编译的时候就会分配空间）
		static int n4 = 100;	// n4存储于.data段中	（在编译期初始化，在编译的时候就会分配空间）

		//t4对象的作用域范围是在块作用域范围内，但是生存期是在整个程序范围之内
		static Test t4(333);	// t4对象在运行期初始化，存储于.data段
	}
	cout<<"Exiting main ..."<<endl;
}