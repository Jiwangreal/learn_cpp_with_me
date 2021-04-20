#include "BankService.h"

#include "../Server.h"
#include "../../Public/Logging.h"
#include "../../Public/Exception.h"
#include "../../Public/JUtil.h"

#include <sstream>
using namespace std;

using namespace DAL;
using namespace PUBLIC;

int BankService::UserLogin(const string& user, const string& pass)
{
	if (user != "admin" || pass != "123456")
		return 1;

	return 0;
}


// 开户
int BankService::OpenAccount(Account& account)
{
	
	return 0;
}


// 存款
int BankService::Deposit(Account& account)
{
	
	return 0;
}

// 取款
int BankService::WithDraw(Account& account)
{
	return 0;
}
// 转帐
int BankService::Transfer(Account& account, const string& otherAccountId)
{
	
	return 0;
}
// 查询余额
int BankService::BalanceInquiry(Account& account)
{
	
	return 0;
}

// 修改密码
int BankService::ChangePassword(Account& account, const string& newPass)
{
	
	return 0;
}

// 查询某日报表
int BankService::QueryDayBill(list<TransDetail>& result, int page, const string& date)
{
	
	return 0;
}
// 根据日期查询明细
int BankService::QueryHistoryBill(list<TransDetail>& result, int page, const string& begin, const string& end)
{
	
	return 0;
}
// 根据帐号查询明细
int BankService::QueryAccountHistoryBill(list<TransDetail>& result, int page, const string& accountId, const string& begin, const string& end)
{
	
	return 0;
}

// 销户
int BankService::CloseAccount(Account& account, double& interest)
{
	
	return 0;

}
