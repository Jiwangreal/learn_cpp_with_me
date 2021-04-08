#ifndef _SINGLETON_H_
#define _SINGLETON_H_

//单例模板
namespace PUBLIC
{

//这个模板类相当于一个包装器
template <typename T>
class Singleton
{
public:
	static T& Instance()
	{
		//实际上返回的是T
		static T instance;
		return instance;
	}
private:
	Singleton();
	~Singleton();
};

}

#endif	// _SINGLETON_H_
