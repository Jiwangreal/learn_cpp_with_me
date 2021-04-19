#include "Server.h"

int main(void)
{
	return Singleton<Server>::Instance().Start();
}