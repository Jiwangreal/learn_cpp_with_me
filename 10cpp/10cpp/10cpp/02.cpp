#include <iostream>
using namespace std;

class Outer//Outer是外围类
{
public:
	class Inner//Inner为嵌套类
	{
	public:
		void Fun();
		//{
		//	cout<<"Inner::Fun ..."<<endl;
		//}
	};
public:
	Inner obj_;//外围类使用嵌套类对象
	void Fun()
	{
		cout<<"Outer::Fun ..."<<endl;
		obj_.Fun();
	}
};

//嵌套类的函数实现可以放在外部
void Outer::Inner::Fun()
{
	cout<<"Inner::Fun ..."<<endl;
}


void Fun()
{
	//局部类
	class LocalClass
	{
	public:
		int num_;
		void Init(int num)
		{
			num_ = num;
		}
		void Display()//局部类的函数只能在类体中实现
		{
			cout<<"num="<<num_<<endl;
		}

		//static int num2_;	// 静态变量的初始化必须是文件作用域的初始化，局部类内部不能定义静态成员
	};

	LocalClass lc;
	lc.Init(10);
	lc.Display();
}

int main(void)
{
	Outer o;
	o.Fun();
	/*
	若不注释：Inner嵌套类的在类内定义的成员函数
	输出为：Outer::Fun ...
			Inner::Fun ...
	*/

	Outer::Inner i;
	i.Fun();
	/*
	嵌套类仅仅只是语法上的嵌入的解释：
	class Outer//Outer是外围类
	{
	public://这里必须要将嵌套类声明为public才行
		class Inner//Inner为嵌套类
	
	*/

	Fun();
	//LocalClass lc;		Error,局部类只能在定义他的函数体中使用
	return 0;
}