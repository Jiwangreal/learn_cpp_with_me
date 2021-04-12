#include <windows.h>
#include <process.h>
#include <iostream>
using namespace std;

//__stdcall unsigned  ThreadProc(void* lpParameter)也行
unsigned __stdcall ThreadProc(void* lpParameter)
{
	cout<<"GetCurrentThreadId()="<<GetCurrentThreadId()<<endl;
	int n = (int)lpParameter;
	while (n--)
	{
		cout<<"this is a test"<<endl;
		Sleep(1000);
	}
	//ExitThread();不要使用ExitThread(),这里要么使用return，要么使用_endthreadex()，要配套使用
	return 100;
}

int main()
{

	unsigned threadId;
	//_beginthreadex(安全属性，堆栈大小，线程函数的入口地址，传递给线程函数的参数，线程选项，返回的线程ID)
	//0表示线程没有挂起
	HANDLE hThread = (HANDLE)_beginthreadex(NULL, 0, ThreadProc, (void*)5, 0, &threadId);
	if (hThread == NULL)
	{
		cout<<"error with code"<<GetLastError()<<endl;
		exit(1);
	}

	cout<<"threadId="<<threadId<<endl;

	DWORD ret;
	ret = WaitForSingleObject(hThread, INFINITE);
	if (ret == WAIT_FAILED)
	{
		cout<<"error with code="<<GetLastError()<<endl;
		exit(1);
	}
	else if (ret == WAIT_OBJECT_0)
	{
		cout<<"wait succ"<<endl;
	}

	//Sleep(10*1000);

	CloseHandle(hThread);
	return 0;
}