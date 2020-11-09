#include <iostream>
using namespace std;

class Singleton
{
public:
	static Singleton& GetInstance()//返回的是引用，所以不会调用拷贝构造函数
	{
		static Singleton instance;		// 局部静态对象：是在运行期初始化，是有状态的
		return instance;				//第2次调用时，会返回先前所初始化的实例，以此来保证单例
	}
	//写法2
	// static Singleton* GetInstance()
	// {
	// 	static Singleton instance;	
	// 	return &instance;				
	// }

	~Singleton()
	{
		cout<<"~Singleton ..."<<endl;
	}

private:
	Singleton(const Singleton& other);
	Singleton& operator=(const Singleton& other);
	Singleton()
	{
		cout<<"Singleton ..."<<endl;
	}
};

int main(void)
{
	Singleton& s1 = Singleton::GetInstance();
	Singleton& s2 = Singleton::GetInstance();

	//写法2
	// Singleton* s1 = Singleton::GetInstance();
	// Singleton* s2 = Singleton::GetInstance();

	return 0;
}