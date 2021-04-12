#include "JThread.h"
#include <process.h>

JThread::JThread() : hThread_(NULL), threadId_(0), autoDel_(false)
{
}

JThread::~JThread()
{
	if (hThread_ != NULL)
		CloseHandle(hThread_);
}

void JThread::SetAutoDel(bool autoDel)
{
	autoDel_ = autoDel;
}


unsigned __stdcall JThread::ThreadFun(void* p)
{
	JThread* jtp = (JThread*)p;
	jtp->Run();
	if (jtp->autoDel_)
		delete jtp;//ServiceThread中的Run执行完毕后，这里自动销毁线程，p这个对象指向的就是ServiceThread
					//这样就可以正常销毁ServiceThread对象了
	return 0;
}

bool JThread::Start()
{
	hThread_ = (HANDLE)_beginthreadex(NULL, 0, ThreadFun, this, 0, &threadId_);
	return hThread_ != NULL;
}

void JThread::Wait(DWORD timeout)
{
	WaitForSingleObject(hThread_, timeout);
}