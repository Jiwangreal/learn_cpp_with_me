#include "BankService.h"

#include "../Server.h"
#include "../../Public/Logging.h"
#include "../../Public/Exception.h"
#include "../../Public/JUtil.h"

#include <sstream>
using namespace std;

using namespace DAL;
using namespace PUBLIC;

//����Ӧ���Ƿ������ݿ��
//��ʱд���������֤���ݵķ�ʽ
int BankService::UserLogin(const string& user, const string& pass)
{
	if (user != "admin" || pass != "123456")
		return 1;

	return 0;
}


// ����
int BankService::OpenAccount(Account& account)
{
	
	return 0;
}


// ���
int BankService::Deposit(Account& account)
{
	
	return 0;
}

// ȡ��
int BankService::WithDraw(Account& account)
{
	return 0;
}
// ת��
int BankService::Transfer(Account& account, const string& otherAccountId)
{
	
	return 0;
}
// ��ѯ���
int BankService::BalanceInquiry(Account& account)
{
	
	return 0;
}

// �޸�����
int BankService::ChangePassword(Account& account, const string& newPass)
{
	
	return 0;
}

// ��ѯĳ�ձ���
int BankService::QueryDayBill(list<TransDetail>& result, int page, const string& date)
{
	
	return 0;
}
// �������ڲ�ѯ��ϸ
int BankService::QueryHistoryBill(list<TransDetail>& result, int page, const string& begin, const string& end)
{
	
	return 0;
}
// �����ʺŲ�ѯ��ϸ
int BankService::QueryAccountHistoryBill(list<TransDetail>& result, int page, const string& accountId, const string& begin, const string& end)
{
	
	return 0;
}

// ����
int BankService::CloseAccount(Account& account, double& interest)
{
	
	return 0;

}
