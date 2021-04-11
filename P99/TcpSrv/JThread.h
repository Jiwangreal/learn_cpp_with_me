#ifndef _JTHREAD_H_
#define _JTHREAD_H_

#include <Windows.h>
class JThread
{
public:
	JThread();
	virtual ~JThread();

	virtual void Run() = 0;

	static unsigned __stdcall ThreadFun(void* p);
	bool Start();

	void Wait(DWORD timeout=INFINITE);
	void SetAutoDel(bool autoDel);

private:
	HANDLE hThread_;
	unsigned threadId_;
	bool autoDel_;
};

#endif // _JTHREAD_H_