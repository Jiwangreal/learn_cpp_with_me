#ifndef _JTHREAD_H_
#define _JTHREAD_H_

#include <Windows.h>
//JThread�ǳ�����
class JThread
{
public:
	JThread();
	virtual ~JThread();

	virtual void Run() = 0;//ÿ������ִ��һ������
							//���麯�����κ�һ���̳�JThread�࣬��Ӧ��ȥʵ��Run����

	/*
	ThreadFun�����������麯������Ϊ����ȫ�ֺ�����������_beginthreadex��OS��ص�ThreadFun������һ���߳�
	���麯���ĵ�һ��������thisָ�루ָ����øú����Ķ��󣩣����ص�����ThreadFun��һ�������Ͳ���thisָ�룬���Բ��С�
	*/
	static unsigned __stdcall ThreadFun(void* p);//static������thisָ��
	bool Start();//�����߳�

	void Wait(DWORD timeout=INFINITE);

private:
	HANDLE hThread_;
	unsigned threadId_;
};

#endif // _JTHREAD_H_