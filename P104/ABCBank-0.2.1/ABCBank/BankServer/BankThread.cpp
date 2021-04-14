#include "BankThread.h"

#include "../Public/Logging.h"
#include "../Public/StringUtil.h"

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


		std::vector<std::string> v = StringUtil::Split(buffer, '#');

		//打印解析到的数据
		if (v.size() != 2)
		{
			LOG_INFO<<"错误的消息";
		}
		else
			LOG_INFO<<"user="<<v[0]<<" pass="<<v[1];

		socket_->Send(buffer, ret);

	}
}
