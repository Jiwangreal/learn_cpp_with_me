#include "JThread.h"
#include <process.h>

JThread::JThread() : hThread_(NULL), threadId_(0)
{
}

JThread::~JThread()
{
	if (hThread_ != NULL)
		CloseHandle(hThread_);
}

unsigned __stdcall JThread::ThreadFun(void* p)
{
	//获取到传递的this指针，访问到JThread成员中的变量
	JThread* jtp = (JThread*)p;//t.Start();后，基类指针jtp指向派生类对象t
	jtp->Run();//未来是派生类对象调用Start函数，所以这里是基类指针指向派生类对象
				//其调用虚函数，调用的是派生类的虚函数
	return 0;
}

bool JThread::Start()
{
	//传递this指针
	hThread_ = (HANDLE)_beginthreadex(NULL, 0, ThreadFun, this, 0, &threadId_);
	return hThread_ != NULL;
}

void JThread::Wait(DWORD timeout)
{
	WaitForSingleObject(hThread_, timeout);
}