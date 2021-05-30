#include "Client.h"

#include "../Public/Socket.h"

#include <sstream>
using namespace std;

Client::Client() : config_("client.conf")
{
	Socket::Startup();
	serverIp_ = config_.GetProperty("CLIENT.SERVER_IP");
	string port = config_.GetProperty("CLIENT.PORT");
	stringstream ss;
	ss<<port;
	ss>>port_;

	//当客户端对象创建的时候，就new一个BankSession，BankSession的构造函数连接了服务器端
	bs_ = new BankSession;
}

Client::~Client()
{
	//析构函数中，delete BankSession
	delete bs_;
	Socket::Cleanup();
}
