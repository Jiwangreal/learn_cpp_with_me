#include "BankThread.h"

#include "BankSession.h"

#include "../Public/Logging.h"
#include "../Public/StringUtil.h"
#include "../Public/Exception.h"

#include <string>
#include <vector>

BankThread::BankThread(std::auto_ptr<Socket>& socket) : socket_(socket)
{
}

BankThread::~BankThread()
{
}

void BankThread::Run()
{
	/*
	int ret;
	while (1)
	{
		char buffer[1024] = {0};
		ret = socket_->Recv(buffer, sizeof(buffer));
		if (ret == -1)
		{
			LOG_INFO<<"读取网络消息错误";
			break;
		}
		if (ret == 0)
		{
			LOG_INFO<<"客户端关闭";
			break;
		}

		//解析通信包
		std::vector<std::string> v = StringUtil::Split(buffer, '#');
		if (v.size() != 2)
		{
			LOG_INFO<<"错误的消息";
		}
		else
			LOG_INFO<<"user="<<v[0]<<" pass="<<v[1];

		socket_->Send(buffer, ret);

	}
	*/

	//与客户端通信的细节放到BankSession类中
	//具体的命令的解析放到Transaction类中
	//将解析的通信包用不同的交易类Transaction来处理
	BankSession* bs = new BankSession(socket_);	// ABCBank\BankServer\Server.cpp中的Socket对象的所有权转移到了BankSession
											

	//如果还活着
	while (!bs->IsDead())
	{
		try
		{
			bs->Process();//与客户端通信
		}
		catch (Exception& e)
		{
			LOG_INFO<<e.what();
			bs->Kill();//一个连接一个线程，异常的话，跳出循环
		}
	}
	delete bs;//会调用BankSession的析构函数
				//BankSession对象销毁，要保证他所持有的Socket对象也要被销毁
}
