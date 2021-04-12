#include <windows.h>
#include <iostream>
using namespace std;

//WINAPI����_stdcall
DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
	//GetCurrentThreadId������LinuxC�е�pthread_self
	cout<<"GetCurrentThreadId()="<<GetCurrentThreadId()<<endl;//���ر��߳�ID
	int n = (int)lpParameter;//ǿתΪint
	while (n--)
	{
		cout<<"this is a test"<<endl;
		Sleep(1000);//����Ϊ��λ��1000=1s
	}
	return 100;
}


int main()
{

	DWORD dwThreadId;
	//������LinuxC�µ�pthread_creat
	//LPVOIDs��void*��typedef void *LPVOID
	//typedef unsignd long DWORD��typedef DWORD *LPDWORD��typedef void *HANDLE
	//CreateThread(Ĭ�ϵİ�ȫ���ԣ��̶߳�ջ��СĬ��1M���̵߳���ں������̺߳����Ĳ������߳�ѡ������߳�ID)
	//HANDLE��ʶ��һ���̣߳��þ��������OSΪ���߳̿��ٵ��ڴ���ѡ�����Linux���ļ����ص�fd
	//(LPVOID)5ǿתΪָ������
	//CREATE_SUSPENDED��ʾ�̱߳����𣬲��ᱻִ��
	HANDLE hThread = CreateThread(NULL, 0, ThreadProc, (LPVOID)5, CREATE_SUSPENDED/*0*/, &dwThreadId);
	if (hThread == NULL)
	{
		//�������ʹ��WSAGetLastError(),���������GetLastError
		cout<<"error with code"<<GetLastError()<<endl;
		exit(1);
	}

	cout<<"dwThreadId="<<dwThreadId<<endl;//��GetCurrentThreadIdһ��

	SuspendThread(hThread);//�����߳�
	ResumeThread(hThread);//�ָ������߳�ȥִ��
	ResumeThread(hThread);//��Ϊ������2�Σ�����Ҫ�ָ�2��

	//����1
	//DWORD exitCode = 0;
	//// ���߳���ѯ���߳��Ƿ��˳�
	//do 
	//{
	//	GetExitCodeThread(hThread, &exitCode);		// ���������������,�������æ�ȴ�����������Ӧ�������ܱ��⡣
	//} while (exitCode == STILL_ACTIVE);

	//cout<<"exitCode="<<exitCode<<endl;//�̵߳��˳��룬������100

	//CloseHandle(hThread);//������CloseHandle�����̲߳�δ���٣�WaitForSingleObject�������˶���

	//����2
	DWORD ret;
	//���߳̾�����̳߳�ʱʱ�䣩
	//INFINITE��ʾ���õȴ�
	//������LinuxC�µ�pthread_join
	ret = WaitForSingleObject(hThread, INFINITE);//WaitForSingleObject�����������Բ���æ��
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