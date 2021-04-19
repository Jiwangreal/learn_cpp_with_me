#include "BankSession.h"

#include "TransactionManager.h"

#include "../Public/Exception.h"
#include "../Public/Singleton.h"

BankSession::BankSession(std::auto_ptr<Socket>& socket) : socket_(socket), isDead_(false)
{
	requestPack_= (RequestPack*)buffer_;
}

BankSession::~BankSession()
{
}

void BankSession::Process()
{
	Recv();
	DoAction();
}

void BankSession::Send(const char* buf, size_t len)
{
	socket_->SendN(buf, len);
}

void BankSession::Recv()
{
	int ret;
	// 接收包头
	ret = socket_->RecvN(buffer_, sizeof(RequestHead));
	if (ret == 0)	// 客户端关闭
		throw Exception("客户端关闭");
	else if (ret != sizeof(RequestHead))
	{
		throw Exception("接收数据包出错");
	}

	uint16 cmd = Endian::NetworkToHost16(requestPack_->head.cmd);
	uint16 len = Endian::NetworkToHost16(requestPack_->head.len);
	requestPack_->head.cmd = cmd;
	requestPack_->head.len = len;

	// 接收包体，下面2种方式都可以
	ret = socket_->RecvN(/*buffer_+sizeof(RequestHead)*/requestPack_->buf, len);
	if (ret == 0)	// 客户端关闭
		throw Exception("客户端关闭");
	else if (ret != len)
	{
		throw Exception("接收数据包出错");
	}
}

void BankSession::DoAction()
{
	Singleton<TransactionManager>::Instance().DoAction(*this);
}
