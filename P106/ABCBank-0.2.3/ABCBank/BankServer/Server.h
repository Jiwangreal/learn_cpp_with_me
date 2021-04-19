#ifndef _SERVER_H_
#define _SERVER_H_

#include "../Public/Singleton.h"

using namespace PUBLIC;

class Server
{
	friend class Singleton<Server>;
public:
	int Start();
private:
	Server();
	Server(const Server& rhs);
	~Server();
};

#endif // _SERVER_H_