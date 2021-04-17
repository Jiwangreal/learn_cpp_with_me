#ifndef _BANK_SESSION_H_
#define _BANK_SESSION_H_

#include "../Public/JUtil.h"
#include "../Public/Socket.h"
#include <memory>
using namespace PUBLIC;

//����Ķ���
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

//�������ͷ��
struct RequestHead
{
	unsigned short cmd;//����
	unsigned short len;//����
};

//Ӧ�����ͷ��
struct ResponseHead
{
	unsigned short cmd;
	unsigned short len;
	unsigned short cnt;
	unsigned short seq;
	unsigned short error_code;
	char error_msg[30];
};

//�������
//RequestPack�ǰ�ͷ����
//���岿�ֲ�����
struct RequestPack
{
	RequestHead head;
	char buf[1];//����������𵽱�����ã����壺�����Ǵ����λ�ÿ�ʼ��
};

//Ӧ�����
struct ResponsePack
{
	ResponseHead head;
	char buf[1];
};

//���������˽���ͨ�ŵ�Э��
class BankSession
{
public:
	BankSession(std::auto_ptr<Socket>& socket);
	~BankSession();

	bool IsDead() const { return isDead_; }
	void Kill() { isDead_ = true; }//kill����Ự
	void Process();//�Ự�Ĵ���
	uint16 GetCmd() const { return requestPack_->head.cmd; }//�������������
	RequestPack* GetRequestPack() const { return requestPack_; }//����ָ��
	void Send(const char* buf, size_t len);
	void Recv();
	void DoAction();


private:
	bool isDead_;//��ʾ�Ự�Ƿ��ǻ��״̬���Ự�Ƿ�������
	std::auto_ptr<Socket> socket_;//����ָ�������ջ�϶���socket_��socket_�������ٻᵼ�����װ��Socket
									//�������٣�Socket��ָ����󣬼����϶������٣�std::auto_ptr<Socket> conn(new Socket);
									//���Գ����쳣��Ҳ���������ٶ���������Դ��û��й©��
	char buffer_[2048];//2K
	RequestPack* requestPack_;//�������ָ��
};


#endif // _BANK_SESSION_H_