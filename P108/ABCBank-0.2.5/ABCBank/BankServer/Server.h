#ifndef _SERVER_H_
#define _SERVER_H_

#include "../Public/SystemConfig.h"
#include "../Public/Singleton.h"

using namespace PUBLIC;

class Server
{
	friend class Singleton<Server>;
public:
	int Start();
	const string& GetServerIp() const
	{
		return serverIp_;
	}

	unsigned short GetPort() const
	{
		return port_;
	}

	const string& GetDbServerIp() const
	{
		return dbServerIp_;
	}

	unsigned short GetDbServerPort() const
	{
		return dbServerPort_;
	}

	const string& GetDbUser() const
	{
		return dbUser_;
	}

	const string& GetDbPass() const
	{
		return dbPass_;
	}

	const string& GetDbName() const
	{
		return dbName_;
	}

	double GetInteretRate() const
	{
		return interetRate_;
	}
private:
	Server();
	Server(const Server& rhs);
	~Server();

	SystemConfig config_;

	//内容：构造对象的时候，从配置文件读取
	string serverIp_;//服务器的ip
	unsigned short port_;//服务器的端口
	string dbServerIp_;//数据库的ip
	unsigned short dbServerPort_;//数据库的端口
	string dbUser_;//数据库的用户
	string dbPass_;//数据库的密码
	string dbName_;//数据库的名称

	double interetRate_;//银行利率
};

#endif // _SERVER_H_