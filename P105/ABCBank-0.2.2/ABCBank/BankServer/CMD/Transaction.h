#ifndef _TRANSACTION_H_
#define _TRANSACTION_H_

#include "../BankSession.h"

namespace CMD
{

// 命令基类，抽象类
class Transaction
{
public:
	//与客户端的会话传递进来
	//BankSession保存与客户端交换的一些数据
	virtual void Execute(BankSession& session) = 0;
	virtual ~Transaction() {};
};

}

#endif // _TRANSACTION_H_
