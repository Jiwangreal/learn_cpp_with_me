#include <windows.h>
#include <iostream>
using namespace std;

//WINAPI就是_stdcall
DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
	//GetCurrentThreadId类似于LinuxC中的pthread_self
	cout<<"GetCurrentThreadId()="<<GetCurrentThreadId()<<endl;//返回本线程ID
	int n = (int)lpParameter;//强转为int
	while (n--)
	{
		cout<<"this is a test"<<endl;
		Sleep(1000);//毫秒为单位，1000=1s
	}
	return 100;
}


int main()
{

	DWORD dwThreadId;
	//类似于LinuxC下的pthread_creat
	//LPVOIDs是void*，typedef void *LPVOID
	//typedef unsignd long DWORD，typedef DWORD *LPDWORD，typedef void *HANDLE
	//CreateThread(默认的安全属性，线程堆栈大小默认1M，线程的入口函数，线程函数的参数，线程选项，返回线程ID)
	//HANDLE标识了一个线程，该句柄会索引OS为该线程开辟的内存而已。类似Linux打开文件返回的fd
	//(LPVOID)5强转为指针类型
	//CREATE_SUSPENDED表示线程被挂起，不会被执行
	HANDLE hThread = CreateThread(NULL, 0, ThreadProc, (LPVOID)5, CREATE_SUSPENDED/*0*/, &dwThreadId);
	if (hThread == NULL)
	{
		//网络错误使用WSAGetLastError(),其余错误用GetLastError
		cout<<"error with code"<<GetLastError()<<endl;
		exit(1);
	}

	cout<<"dwThreadId="<<dwThreadId<<endl;//与GetCurrentThreadId一样

	SuspendThread(hThread);//挂起线程
	ResumeThread(hThread);//恢复挂起线程去执行
	ResumeThread(hThread);//因为挂起了2次，所以要恢复2次

	//方法1
	//DWORD exitCode = 0;
	//// 主线程轮询子线程是否退出
	//do 
	//{
	//	GetExitCodeThread(hThread, &exitCode);		// 这个函数不会阻塞,因而处于忙等待，但是我们应当尽可能避免。
	//} while (exitCode == STILL_ACTIVE);

	//cout<<"exitCode="<<exitCode<<endl;//线程的退出码，这里是100

	//CloseHandle(hThread);//在这里CloseHandle，子线程并未销毁，WaitForSingleObject不能用了而已

	//方法2
	DWORD ret;
	//（线程句柄，线程超时时间）
	//INFINITE表示永久等待
	//类似于LinuxC下的pthread_join
	ret = WaitForSingleObject(hThread, INFINITE);//WaitForSingleObject会阻塞，所以不会忙等
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