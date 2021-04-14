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
			LOG_INFO<<"��ȡ������Ϣ����";
			break;
		}
		if (ret == 0)
		{
			LOG_INFO<<"�ͻ��˹ر�";
			break;
		}


		std::vector<std::string> v = StringUtil::Split(buffer, '#');

		//��ӡ������������
		if (v.size() != 2)
		{
			LOG_INFO<<"�������Ϣ";
		}
		else
			LOG_INFO<<"user="<<v[0]<<" pass="<<v[1];

		socket_->Send(buffer, ret);

	}
}
