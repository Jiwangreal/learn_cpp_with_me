#include "Client.h"

#include "../Public/Socket.h"

#include <sstream>//stringstream流类的头文件
using namespace std;

Client::Client() : config_("client.conf")
{
	Socket::Startup();
	serverIp_ = config_.GetProperty("CLIENT.SERVER_IP");
	string port = config_.GetProperty("CLIENT.PORT");
	stringstream ss;
	ss<<port;
	ss>>port_;
}

Client::~Client()
{
	Socket::Cleanup();
}
