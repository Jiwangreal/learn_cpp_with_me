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
	//bindʧ���ˡ�����
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
		
		//һ������һ���߳�
		/*
		��Ҫʹ�þֲ�����
		BankThread bt;
		bt.Start();
		��Ϊ����߳��뿪���������֮���̶߳���ͽ����ˣ���������̵߳Ĺ������ݻ�û�н����ء�
		���ǿ����ں�������bt.Wait();
		���������߳̾Ͳ���Accept�ˣ���������������ȡ

		Socket conn;
		ͬ��conn����ʹ��ջ���������뿪���while������󣬶�������٣������Socket����������
		���������н���socket close���ˣ���ô���ݵ�BankThread�����connҲ�Ͳ���ͨ���ˡ�
		����Ҫôʹ������ָ�룬Ҫô��Socket������BankThread�����١������������쳣�������Socket�����޷���BankThread�����١�
		*/
		//������ָ����󴫵ݸ�BankThread
		//BankThread��ͻ���ͨ��
		BankThread* bt = new BankThread(conn);	// ����Ȩ�Ѿ�ת�Ƶ���BankThread�е�����ָ�����
												//conn�뿪�˸��������Ҳ����ȥ���ٸ�Socket����Socket��
												//����Ȩ�Ѿ�ת�Ƶ���BankThread�����ˣ�����������Socket��������
		bt->SetAutoDel(true);//���߳�ִ��Run��Ϻ󣬻��Զ�����BankThread����
		bt->Start();

	}
	return 0;
}