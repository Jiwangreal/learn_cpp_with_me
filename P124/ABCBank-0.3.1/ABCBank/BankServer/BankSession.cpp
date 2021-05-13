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
	Recv();//接收数据包
	DoAction();//接收到数据包后，就可以去处理他了
}

void BankSession::Send(const char* buf, size_t len)
{
	socket_->SendN(buf, len);
}

void BankSession::Recv()
{
	int ret;
	
	//先接收包头，可以计算出来包体+包尾的长度，这样就可以接收包体+包尾部分了
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
	

	// 接收包体+包尾
	ret = socket_->RecvN(/*buffer_+sizeof(RequestHead)*/requestPack_->buf, len);
	if (ret == 0)	// 客户端关闭
		throw Exception("客户端关闭");
	else if (ret != len)
	{
		throw Exception("接收数据包出错");
	}

	// 计算hash，与接收过来的包尾哈希uffer_+sizeof(RequestHead)+len-8进行比较，相等则是完整的数据包
	unsigned char hash[16];
	MD5 md5;
	md5.MD5Make(hash, (unsigned char const *)buffer_, sizeof(RequestHead)+len-8);
	for (int i=0; i<8; ++i)
	{
		hash[i] = hash[i] ^ hash[i+8];
		hash[i] = hash[i] ^ ((cmd >> (i%2)) & 0xff);
	}

	if (memcmp(hash, buffer_+sizeof(RequestHead)+len-8, 8))
		throw Exception("错误的数据包");

	requestPack_->head.cmd = cmd;
	requestPack_->head.len = len;

}

void BankSession::DoAction()
{
	//进入到TransactionManager的DoAction，接着进入相应的server端的CMD层的Execute对应函数
	Singleton<TransactionManager>::Instance().DoAction(*this);
}
