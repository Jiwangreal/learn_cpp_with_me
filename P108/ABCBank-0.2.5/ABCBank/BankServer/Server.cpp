#include "Server.h"
#include "BankThread.h"

#include "../Public/Socket.h"
#include "../Public/Logging.h"

#include <memory>
#include <iostream>
#include <sstream>

//构造config_对象
//server.conf配置文件需要放在BankServer.vcproj所在的目录，如果不放
//SystemConfig，assert(fin);会断言
/*
将配置文件server.conf放在ABCBank\Bin\这里的原因是，因为生成的exe文件会在bin目录下，那么当前目录就是bin目录。
若在vs2008中运行，则当前目录是BankServer.vcproj所在的目录，所以配置文件放在那里了。
*/
Server::Server() : config_("server.conf")
{
	Socket::Startup();
	serverIp_ = config_.GetProperty("SERVER.SERVER_IP");
	string port = config_.GetProperty("SERVER.PORT");
	//通过流的方式，将string的port转换为unsigned short 
	stringstream ss;
	ss<<port;//将port放到流里面，再把它拿出来
	ss>>port_;

	dbServerIp_ = config_.GetProperty("DB.IP");

	port = config_.GetProperty("DB.PORT");
	ss.clear();//清除流
	ss.str("");//将流中的缓冲区清空
	ss<<port;
	ss>>dbServerPort_;

	dbUser_ = config_.GetProperty("DB.USER");//用户
	dbPass_ = config_.GetProperty("DB.PASS");//密码
	dbName_ = config_.GetProperty("DB.NAME");//数据库的名称

	ss.clear();
	ss.str("");
	string interetRate = config_.GetProperty("BANK.INTERATE");//利率
	
	//若没有配置利率
	if (interetRate.empty())
	{
		interetRate_ = 0.0035;
	}
	else
	{
		//通过流的方式能进行类型转换
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
	LOG_INFO<<"启动服务器...";
	Socket sock;
	sock.Create();
	//if (!sock.Bind(NULL, 8888))
	//这里是const char*类型，所以需要取string.c_str()
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

		BankThread* bt = new BankThread(conn);	// 所有权已经转移到了BankThread中的智能指针对象
		bt->SetAutoDel(true);
		bt->Start();

	}
	return 0;
}