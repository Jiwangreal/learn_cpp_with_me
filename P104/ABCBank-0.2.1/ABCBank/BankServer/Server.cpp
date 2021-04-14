#include "Server.h"
#include "BankThread.h"

#include "../Public/Socket.h"
#include "../Public/Logging.h"

#include <memory>

Server::Server()
{
	Socket::Startup();
}

Server::~Server()
{
	Socket::Cleanup();
}

int Server::Start()
{
	LOG_INFO<<"启动服务器...";
	Socket sock;
	sock.Create();
	//bind失败了。。。
	if (!sock.Bind(NULL, 8888))
		return 1;
	if (!sock.Listen())
		return 1;

	while (1)
	{
		std::auto_ptr<Socket> conn(new Socket);
		conn->socket_ = sock.Accept();
		if (!conn->IsValid())
			continue;
		
		//一个连接一个线程
		/*
		不要使用局部对象
		BankThread bt;
		bt.Start();
		因为这个线程离开了这个作用之后，线程对象就结束了，但是这个线程的工作内容还没有结束呢。
		但是可以在后面增加bt.Wait();
		但这样主线程就不能Accept了，这样的作法不可取

		Socket conn;
		同样conn不能使用栈变量，当离开这个while作用域后，对象会销毁，会调用Socket的析构函数
		析构函数中将该socket close掉了，那么传递到BankThread对象的conn也就不能通信了。
		所以要么使用智能指针，要么该Socket对象由BankThread来销毁。但是若出现异常情况，该Socket对象无法由BankThread来销毁。
		*/
		//将智能指针对象传递给BankThread
		//BankThread与客户端通信
		BankThread* bt = new BankThread(conn);	// 所有权已经转移到了BankThread中的智能指针对象
												//conn离开了该作用域后，也不会去销毁该Socket，该Socket的
												//所有权已经转移到了BankThread类中了，由其来管理Socket的生存期
		bt->SetAutoDel(true);//当线程执行Run完毕后，会自动销毁BankThread对象
		bt->Start();

	}
	return 0;
}