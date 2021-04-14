#ifndef _CLIENT_H_
#define _CLIENT_H_

#include "../Public/Singleton.h"

using namespace PUBLIC;

//µ¥Àý
class Client
{
	friend class Singleton<Client>;
private:
	Client();
	Client(const Client& rhs);
	~Client();
};

#endif // _CLIENT_H_
