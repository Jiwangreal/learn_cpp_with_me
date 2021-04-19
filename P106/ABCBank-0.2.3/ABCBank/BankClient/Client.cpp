#include "Client.h"

#include "../Public/Socket.h"

Client::Client()
{
	Socket::Startup();
}

Client::~Client()
{
	Socket::Cleanup();
}
