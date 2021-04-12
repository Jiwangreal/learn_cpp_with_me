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
	//��ȡ�����ݵ�thisָ�룬���ʵ�JThread��Ա�еı���
	JThread* jtp = (JThread*)p;//t.Start();�󣬻���ָ��jtpָ�����������t
	jtp->Run();//δ����������������Start���������������ǻ���ָ��ָ�����������
				//������麯�������õ�����������麯��
	return 0;
}

bool JThread::Start()
{
	//����thisָ��
	hThread_ = (HANDLE)_beginthreadex(NULL, 0, ThreadFun, this, 0, &threadId_);
	return hThread_ != NULL;
}

void JThread::Wait(DWORD timeout)
{
	WaitForSingleObject(hThread_, timeout);
}