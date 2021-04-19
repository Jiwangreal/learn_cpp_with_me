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
		throw Exception("����ʧ��");

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
	//�Ƚ���Ӧ����İ�ͷ
	ret = socket_->RecvN(buffer_, sizeof(ResponseHead));
	if (ret == 0)
		throw Exception("�������˶Ͽ�");
	else if (ret != sizeof(ResponseHead))
		throw Exception("�������ݰ�����");

	//ת���������ֽ���
	uint16 cmd = Endian::NetworkToHost16(responsePack_->head.cmd);
	uint16 len = Endian::NetworkToHost16(responsePack_->head.len);

	responsePack_->head.cmd = cmd;
	responsePack_->head.len = len;

	//Ŀǰû�Ӱ�β�����ǹ�Ա�Ļ��������ǿյģ����Բ���ȥ������
	if (len == 0)
		return;

	ret = socket_->RecvN(responsePack_->buf, len);
	if (ret == 0)
		throw Exception("�������˶Ͽ�");
	else if (ret != len)
		throw Exception("�������ݰ�����");

	
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

