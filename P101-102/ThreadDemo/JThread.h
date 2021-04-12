#ifndef _JTHREAD_H_
#define _JTHREAD_H_

#include <Windows.h>
//JThread是抽象类
class JThread
{
public:
	JThread();
	virtual ~JThread();

	virtual void Run() = 0;//每个对象都执行一个任务，
							//纯虚函数：任何一个继承JThread类，都应该去实现Run函数

	/*
	ThreadFun不能做成是虚函数，因为他是全局函数，当调用_beginthreadex，OS会回调ThreadFun来开辟一个线程
	而虚函数的第一个参数是this指针（指向调用该函数的对象），而回调函数ThreadFun第一个参数就不是this指针，所以不行。
	*/
	static unsigned __stdcall ThreadFun(void* p);//static函数无this指针
	bool Start();//启动线程

	void Wait(DWORD timeout=INFINITE);

private:
	HANDLE hThread_;
	unsigned threadId_;
};

#endif // _JTHREAD_H_