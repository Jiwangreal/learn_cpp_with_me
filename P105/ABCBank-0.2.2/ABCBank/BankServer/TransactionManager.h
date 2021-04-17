#ifndef _TRANSACTION_MANAGER_H_
#define _TRANSACTION_MANAGER_H_

#include "../Public/Singleton.h"
#include "BankSession.h"
#include "CMD/Transaction.h"
#include <map>
#include <string>
using namespace std;

using namespace CMD;

//交易管理类
//单例类：每一个服务器端都有一个单例的管理器类
class TransactionManager
{
	friend class Singleton<TransactionManager>;
public:
	bool DoAction(BankSession& session);

private:
	//key是命令类型，value是交易对象
	map<uint16, Transaction*> m_actions;
	TransactionManager();
	TransactionManager(const TransactionManager& rhs);
	~TransactionManager();

};

#endif // _TRANSACTION_MANAGER_H_
