#ifndef _SINGLETON_H
#define _SINGLETON_H

#include <cstdlib>
#include <iostream>
using namespace std;

//将Singleton类模板看成是单例模式类的包装器，用它可以产生单例模式类
//GetInstance返回的不是Singleton自身，而是它所包装的对象T
template <typename T>
class Singleton
{
public:
	//方法1：
	// static T& GetInstance()//返回的是引用，所以不会调用拷贝构造函数
	// {
	// 	static T instance;		// 局部静态对象：是在运行期初始化，是有状态的
	// 	return instance;				//第2次调用时，会返回先前所初始化的实例，以此来保证单例
	// }

	//方法2：
	//静态成员函数不能调用非静态函数
	static T& GetInstance()
	{
		// pthread_once(Init());//多个线程访问GetInstance时，Init只是调用一次，（3）linux底下推荐使用pthread_once
		Init();
		return *instance_;
	}

	/*
	static T& GetInstance()这种并不是线程安全的，原因如下：
	因为2个线程可能同时调用了GetInstance，2个线程同时进行了if (instance_ == 0)判断，会new2个对象，此时不是线程安全的。
	解决办法：
	（1）普通锁,不推荐
	（2）double check lock双检测锁，不推荐
	（3）linux底下推荐使用pthread_once
	*/


private:
	static void Init()
	{
		// lock();（1）普通锁
		if (instance_ == 0)
		{
			// //再检测一次
			// lock();（2）double check lock双检测锁
			// if (instance_ == 0)
			// ulock();（2）double check lock双检测锁
			instance_ =new T;
			//将Destroy函数注册进去，程序结束时，会调用注册的函数（可以注册多个，后注册的函数先调用）
			//仅仅注册一次
			atexit(Destroy);//单例模式对象销毁推荐使用的方式，而不要使用智能指针
		}
		// ulock();//（1）普通锁
	}
	static void Destroy()
	{
		delete instance_;
	}

	Singleton(const Singleton& other);
	Singleton& operator=(const Singleton& other);
	Singleton();
	~Singleton();

	static T* instance_;
};

T* sSingleton<typename T>::instance_ = 0;//初始化为空指针

#endif //_SINGLETON_H