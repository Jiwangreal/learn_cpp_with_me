#include "JThread.h"
#include <iostream>
using namespace std;

//用类的方式实现
class TestThread : public JThread
{
public:
	TestThread(int n) : n_(n)
	{

	}
	~TestThread()
	{

	}

	//在Run中实现线程的业务逻辑
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
	t.Wait();//防止主线程比子线程先结束，因为主线程结束了，那么子线程也就结束了，可能子线程还没运行呢
	return 0;
}