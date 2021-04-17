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

//接收客户端的请求包，然后进行处理
void BankSession::Process()
{
	Recv();
	DoAction();
}

void BankSession::Send(const char* buf, size_t len)
{

}

//先接收包头，再接收包体
void BankSession::Recv()
{
	int ret;
	// 接收包头
	ret = socket_->RecvN(buffer_, sizeof(RequestHead));
	if (ret == 0)	// 客户端关闭
		throw Exception("客户端关闭");//抛出的异常用来被catch (Exception& e)这里捕获。可以理解为通过异常来进行代码跳转，流程控制作用
	else if (ret != sizeof(RequestHead))
	{
		throw Exception("接收数据包出错");
	}

	uint16 cmd = Endian::NetworkToHost16(requestPack_->head.cmd);
	uint16 len = Endian::NetworkToHost16(requestPack_->head.len);
	requestPack_->head.cmd = cmd;
	requestPack_->head.len = len;

	// 接收包体
	ret = socket_->RecvN(buffer_, len);//接收的数据放到buffer_
	if (ret == 0)	// 客户端关闭
		throw Exception("客户端关闭");
	else if (ret != len)
	{
		throw Exception("接收数据包出错");
	}
}

void BankSession::DoAction()
{
	//把自身对象传递进去
	Singleton<TransactionManager>::Instance().DoAction(*this);
}
