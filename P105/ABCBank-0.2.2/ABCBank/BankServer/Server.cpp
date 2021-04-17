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
	LOG_INFO<<"����������...";
	Socket sock;
	sock.Create();
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

		//��һ�����ӹ������Ὺ��һ���̣߳�һ������һ���߳�
		
		BankThread* bt = new BankThread(conn);	// Socket���������Ȩ�Ѿ�ת�Ƶ���BankThread�е�����ָ�����
												//��������BankThread������
		bt->SetAutoDel(true);
		bt->Start();

	}
	return 0;
}