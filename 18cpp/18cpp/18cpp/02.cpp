#include <iostream>
using namespace std;

class Singleton
{
public:
	static Singleton* GetInstance()
	{
		if (instacne_ == NULL)
		{
			instacne_ = new Singleton;
		}
		return instacne_;
	}

	~Singleton()
	{
		cout<<"~Singleton ..."<<endl;
	}
	
	//释放方法1
	//static void Free()
	//{
	//	if (instacne_ != NULL)
	//	{
	//		delete instacne_;
	//	}
	//}

	//释放方法2
	//Garbo功能：垃圾回收
	//嵌套类
	class Garbo
	{
	public:
		~Garbo()
		{
			if (Singleton::instacne_ != NULL)
			{
				delete instacne_;
			}
		}
	};
private:
	Singleton(const Singleton& other);
	Singleton& operator=(const Singleton& other);
	Singleton()
	{
		cout<<"Singleton ..."<<endl;
	}
	static Singleton* instacne_;

	//释放方法2
	//garbo_对象在生命周期结束的时候，会自动调用析构函数，达到销毁单例模式对象的目的
	//利用的是确定性析构的原则
	static Garbo garbo_;	// 利用对象的确定性析构
};

//释放方法2
Singleton::Garbo Singleton::garbo_;//Singleton::Garbo 是类型，Singleton表示garbo_是Singleton的一个成员
Singleton* Singleton::instacne_;

int main(void)
{
	//Singleton s1;
	//Singleton s2;

	Singleton* s1 = Singleton::GetInstance();
	Singleton* s2 = Singleton::GetInstance();

	//Singleton s3(*s1);		// 调用拷贝构造函数

	//释放方法1
	// Singleton::free();

	return 0;
}