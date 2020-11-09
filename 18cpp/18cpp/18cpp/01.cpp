#include <iostream>
using namespace std;

class Singleton
{
public:
	//GetInstance成员函数可以访问Singleton私有的构造函数
	static Singleton* GetInstance()
	{
		if (instacne_ == NULL)
		{
			instacne_ = new Singleton;//new：创建一个类的实例
		}
		return instacne_;
	}

	~Singleton()
	{
		cout<<"~Singleton ..."<<endl;
	}
private:

	//禁止拷贝就是将拷贝构造函数，等号运算符声明为私有的，就可以保证不进行拷贝构造，也不能赋值
	//禁止拷贝1：禁止调用拷贝构造函数
	//将拷贝构造函数声明为私有的，且不提供她的实现
	Singleton(const Singleton& other);

	//禁止拷贝2：
	//将赋值操作声明为私有的，禁止赋值操作
	Singleton& operator=(const Singleton& other);

	//将构造函数声明为私有的，在main函数中就不能调用构造函数
	Singleton()
	{
		cout<<"Singleton ..."<<endl;
	}
	static Singleton* instacne_;//仅仅声明
};

Singleton* Singleton::instacne_;//定义性的说明

int main(void)
{
	//Singleton s1;
	//Singleton s2;

	//不论调用几次GetInstance，总是返回同一个对象，同一个实例
	//如何验证他们是同一个实例？只需查看s1和s2指针所指向的地址是否一致
	Singleton* s1 = Singleton::GetInstance();
	Singleton* s2 = Singleton::GetInstance();

	//Singleton s3(*s1);		// 调用拷贝构造函数
	//s4=s2
	return 0;
}