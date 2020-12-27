#include <iostream>
#include <memory>
using namespace std;

//单例模式是保证一个类在一个程序中只有一个对象，一个实例
//实现单例模式的关键点是：对象禁止拷贝（只需将拷贝构造函数与等号运算符声明为私有的，且并提供它的实现，这样的话，编译会报错），此外将
//构造函数声明为私有的，防止外部任意构造对象，所以需要提供一个接口ingleton::GetInstance();让外部得到这样一个对象
//因为无法通过对象调用成员函数，所以只能通过类调用成员函数，所以将GetInstance声明为static，此外，不论调用多少次GetInstance，返回的是同一个对象
//否则一个程序就有多个对象的拷贝
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
	//解决办法是使用智能指针，当智能指针生命周期结束的时候，会自动调用析构函数，从而释放指针所持有（指向）的资源
	//所以智能指针能用在单例模式中，对资源进行释放
	static Singleton* instacne_;//仅仅声明，这是裸指针，用智能指针管理
	// static shared_ptr<Singleton> instacne_;
	//当整个程序结束时，静态对象也会被销毁，就会调用这个shared_ptr类的析构函数，析构就会将其持有的指针资源进行释放
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