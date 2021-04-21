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
	// ���հ�ͷ
	ret = socket_->RecvN(buffer_, sizeof(RequestHead));
	if (ret == 0)	// �ͻ��˹ر�
		throw Exception("�ͻ��˹ر�");
	else if (ret != sizeof(RequestHead))
	{
		throw Exception("�������ݰ�����");
	}

	uint16 cmd = Endian::NetworkToHost16(requestPack_->head.cmd);
	uint16 len = Endian::NetworkToHost16(requestPack_->head.len);
	requestPack_->head.cmd = cmd;
	requestPack_->head.len = len;

	// ���հ��壬����2�ַ�ʽ������
	ret = socket_->RecvN(/*buffer_+sizeof(RequestHead)*/requestPack_->buf, len);
	if (ret == 0)	// �ͻ��˹ر�
		throw Exception("�ͻ��˹ر�");
	else if (ret != len)
	{
		throw Exception("�������ݰ�����");
	}
}

void BankSession::DoAction()
{
	Singleton<TransactionManager>::Instance().DoAction(*this);
}