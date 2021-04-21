#include "Server.h"
#include "BankThread.h"

#include "../Public/Socket.h"
#include "../Public/Logging.h"

#include <memory>
#include <iostream>
#include <sstream>

//����config_����
//server.conf�����ļ���Ҫ����BankServer.vcproj���ڵ�Ŀ¼���������
//SystemConfig��assert(fin);�����
/*
�������ļ�server.conf����ABCBank\Bin\�����ԭ���ǣ���Ϊ���ɵ�exe�ļ�����binĿ¼�£���ô��ǰĿ¼����binĿ¼��
����vs2008�����У���ǰĿ¼��BankServer.vcproj���ڵ�Ŀ¼�����������ļ����������ˡ�
*/
Server::Server() : config_("server.conf")
{
	Socket::Startup();
	serverIp_ = config_.GetProperty("SERVER.SERVER_IP");
	string port = config_.GetProperty("SERVER.PORT");
	//ͨ�����ķ�ʽ����string��portת��Ϊunsigned short 
	stringstream ss;
	ss<<port;//��port�ŵ������棬�ٰ����ó���
	ss>>port_;

	dbServerIp_ = config_.GetProperty("DB.IP");

	port = config_.GetProperty("DB.PORT");
	ss.clear();//�����
	ss.str("");//�����еĻ��������
	ss<<port;
	ss>>dbServerPort_;

	dbUser_ = config_.GetProperty("DB.USER");//�û�
	dbPass_ = config_.GetProperty("DB.PASS");//����
	dbName_ = config_.GetProperty("DB.NAME");//���ݿ������

	ss.clear();
	ss.str("");
	string interetRate = config_.GetProperty("BANK.INTERATE");//����
	
	//��û����������
	if (interetRate.empty())
	{
		interetRate_ = 0.0035;
	}
	else
	{
		//ͨ�����ķ�ʽ�ܽ�������ת��
		ss<<interetRate;
		ss>>interetRate_;
	}
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
	//if (!sock.Bind(NULL, 8888))
	//������const char*���ͣ�������Ҫȡstring.c_str()
	if (!sock.Bind(serverIp_ == "" ? NULL : serverIp_.c_str(), port_))
		return 1;
	if (!sock.Listen())
		return 1;

	while (1)
	{
		std::auto_ptr<Socket> conn(new Socket);
		conn->socket_ = sock.Accept();
		if (!conn->IsValid())
			continue;

		BankThread* bt = new BankThread(conn);	// ����Ȩ�Ѿ�ת�Ƶ���BankThread�е�����ָ�����
		bt->SetAutoDel(true);
		bt->Start();

	}
	return 0;
}