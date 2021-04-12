#include <windows.h>
#include <process.h>
#include <iostream>
using namespace std;

//__stdcall unsigned  ThreadProc(void* lpParameter)Ҳ��
unsigned __stdcall ThreadProc(void* lpParameter)
{
	cout<<"GetCurrentThreadId()="<<GetCurrentThreadId()<<endl;
	int n = (int)lpParameter;
	while (n--)
	{
		cout<<"this is a test"<<endl;
		Sleep(1000);
	}
	//ExitThread();��Ҫʹ��ExitThread(),����Ҫôʹ��return��Ҫôʹ��_endthreadex()��Ҫ����ʹ��
	return 100;
}

int main()
{

	unsigned threadId;
	//_beginthreadex(��ȫ���ԣ���ջ��С���̺߳�������ڵ�ַ�����ݸ��̺߳����Ĳ������߳�ѡ����ص��߳�ID)
	//0��ʾ�߳�û�й���
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