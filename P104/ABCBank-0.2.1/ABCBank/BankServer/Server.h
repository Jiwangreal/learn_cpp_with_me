#ifndef _SERVER_H_
#define _SERVER_H_

#include "../Public/Singleton.h"

using namespace PUBLIC;

//单例类
class Server
{
	friend class Singleton<Server>;
public:
	int Start();//server的启动方法
private:
	Server();
	Server(const Server& rhs);
	~Server();
};

#endif // _SERVER_H_