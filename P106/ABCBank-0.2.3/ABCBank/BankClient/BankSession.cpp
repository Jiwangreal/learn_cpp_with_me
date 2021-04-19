#include "BankSession.h"
#include "Client.h"

#include "../Public/StringUtil.h"
#include "../Public/Exception.h"


#include <iostream>
using namespace std;

BankSession::BankSession() : socket_(new Socket), errorCode_(0)
{
	socket_->Create();

	if (!socket_->Connect(
		"127.0.0.1",
		8888)
		)
		throw Exception("连接失败");

	responsePack_ = (ResponsePack*)buffer_;
}

BankSession::~BankSession()
{
}

void BankSession::Send(const char* buf, size_t len)
{
	socket_->SendN(buf, len);
}

void BankSession::Recv()
{
	int ret;
	//先接收应答包的包头
	ret = socket_->RecvN(buffer_, sizeof(ResponseHead));
	if (ret == 0)
		throw Exception("服务器端断开");
	else if (ret != sizeof(ResponseHead))
		throw Exception("接收数据包出错");

	//转换成主机字节序
	uint16 cmd = Endian::NetworkToHost16(responsePack_->head.cmd);
	uint16 len = Endian::NetworkToHost16(responsePack_->head.len);

	responsePack_->head.cmd = cmd;
	responsePack_->head.len = len;

	//目前没加包尾，若是柜员的话，包体是空的，所以不用去接收了
	if (len == 0)
		return;

	ret = socket_->RecvN(responsePack_->buf, len);
	if (ret == 0)
		throw Exception("服务器端断开");
	else if (ret != len)
		throw Exception("接收数据包出错");

	
}

void BankSession::Clear()
{
	request_.clear();
	response_.clear();
	errorCode_ = 0;
}

void BankSession::SetAttribute(const string& k, const string& v)
{
	request_[k] = v;
}

const string& BankSession::GetAttribute(const string& k)
{
	return request_[k];
}

