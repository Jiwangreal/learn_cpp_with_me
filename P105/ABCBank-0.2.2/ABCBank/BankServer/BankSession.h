#ifndef _BANK_SESSION_H_
#define _BANK_SESSION_H_

#include "../Public/JUtil.h"
#include "../Public/Socket.h"
#include <memory>
using namespace PUBLIC;

//命令的定义
#define CMD_LOGIN					0x01
#define CMD_OPEN_ACCOUNT			0x02
#define CMD_DEPOSIT					0x03
#define CMD_WITHDRAW				0x04
#define CMD_TRANSFER				0x05
#define CMD_BALANCE_INQUIRY			0x06
#define CMD_CHANGE_PASSWORD			0x07
#define CMD_DAY_BILL				0x08
#define CMD_HISTORY_BILL			0x09
#define CMD_ACCOUNT_HISTORY_BILL	0x0A
#define CMD_CLOSE_ACCOUNT			0x0B

//请求包的头部
struct RequestHead
{
	unsigned short cmd;//命令
	unsigned short len;//长度
};

//应答包的头部
struct ResponseHead
{
	unsigned short cmd;
	unsigned short len;
	unsigned short cnt;
	unsigned short seq;
	unsigned short error_code;
	char error_msg[30];
};

//请求包体
//RequestPack是包头部分
//包体部分不定长
struct RequestPack
{
	RequestHead head;
	char buf[1];//这里仅仅是起到标记作用，含义：包体是从这个位置开始的
};

//应答包体
struct ResponsePack
{
	ResponseHead head;
	char buf[1];
};

//负责与服务端进行通信的协议
class BankSession
{
public:
	BankSession(std::auto_ptr<Socket>& socket);
	~BankSession();

	bool IsDead() const { return isDead_; }
	void Kill() { isDead_ = true; }//kill这个会话
	void Process();//会话的处理
	uint16 GetCmd() const { return requestPack_->head.cmd; }//返回请求的命令
	RequestPack* GetRequestPack() const { return requestPack_; }//返回指针
	void Send(const char* buf, size_t len);
	void Recv();
	void DoAction();


private:
	bool isDead_;//表示会话是否是活的状态，会话是否处理完了
	std::auto_ptr<Socket> socket_;//智能指针对象是栈上对象socket_，socket_对象销毁会导致其包装的Socket
									//对象销毁，Socket是指针对象，即堆上对象销毁，std::auto_ptr<Socket> conn(new Socket);
									//所以出现异常，也能正常销毁对象，这样资源就没有泄漏了
	char buffer_[2048];//2K
	RequestPack* requestPack_;//请求包的指针
};


#endif // _BANK_SESSION_H_