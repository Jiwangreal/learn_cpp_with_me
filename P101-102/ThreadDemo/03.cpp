#include "JThread.h"
#include <iostream>
using namespace std;

//����ķ�ʽʵ��
class TestThread : public JThread
{
public:
	TestThread(int n) : n_(n)
	{

	}
	~TestThread()
	{

	}

	//��Run��ʵ���̵߳�ҵ���߼�
	void Run()
	{
		while (n_--)
		{
			cout<<"this is a test"<<endl;
			Sleep(1000);
		}
	}

private:
	int n_;
};

int main()
{
	TestThread t(5);
	t.Start();
	t.Wait();//��ֹ���̱߳����߳��Ƚ�������Ϊ���߳̽����ˣ���ô���߳�Ҳ�ͽ����ˣ��������̻߳�û������
	return 0;
}