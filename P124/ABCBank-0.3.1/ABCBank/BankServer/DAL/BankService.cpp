#include "BankService.h"
#include "MysqlDB.h"

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
	/*
	if (user != "admin" || pass != "123456")
		return 1;
		*/
	MysqlDB db;
	//ͨ����������server���������ļ�ABCBank-0.3.1\ABCBank\Bin\server.conf�л�ȡDB��ip��
	Server& server = Singleton<Server>::Instance();

	try
	{
		db.Open(server.GetDbServerIp().c_str(),
			server.GetDbUser().c_str(),
			server.GetDbPass().c_str(),
			server.GetDbName().c_str(),//���ݿ������
			server.GetDbServerPort());

		stringstream ss;
		ss<<"select teller_name from teller where teller_name='"<<
			user<<"' and teller_pass='"<<
			pass<<"';";
		MysqlRecordset rs;
		rs = db.QuerySQL(ss.str().c_str());

		//�ҵ���¼��Ӧ��>=1��һ����=1�ģ����ҵ���
		if (rs.GetRows() < 1)
			return 1;//����ֵ���գ�ABCBank��Ŀ�ֲ��е�2.2.2.1.6��������������Ϣ���ձ�
					//1��ʾ�û������������
	}
	catch (Exception& e)
	{
		LOG_INFO<<e.what();
		return -1;//-1��ʾ���ݿ����
	}

	return 0;
}


// ����
//account��һ���������ֵ
int BankService::OpenAccount(Account& account)
{
	MysqlDB db;
	Server& server = Singleton<Server>::Instance();

	try
	{
		//�ȴ����ݿ�
		db.Open(server.GetDbServerIp().c_str(),
			server.GetDbUser().c_str(),
			server.GetDbPass().c_str(),
			server.GetDbName().c_str(),
			server.GetDbServerPort());

		//��������
		db.StartTransaction();

		//��sql���ƴ����������������
		/*ֱ����string��Ҳ�У�����ֱ��ƴ��
		string ss;
		ss + "aaa" + "b"
		*/
		//stringstream�ĺô��ǿ��Ը�ʽ����setprecision(2)<<setiosflags(ios::fixed)<<account.balance
		//�����ȸ�ʽΪ2λ��Ч����
		stringstream ss;
		//id�ֶ����Զ������ģ�Ҫ��дnull
		ss<<"insert into bank_account values(null, '"<<
			account.name<<"', '"<<
			account.pass<<"', '"<<
			account.id<<"', "<<
			//�������������õ���now()
			setprecision(2)<<setiosflags(ios::fixed)<<account.balance<<", now(), "<<
			0<<");";
		unsigned long long ret = db.ExecSQL(ss.str().c_str());


		ss.clear();
		ss.str("");
		//��ȡʵ�ʵ�idֵ
		//˵��account��һ���������ֵ�������ʱ�򲢲�֪��account�е�account_idֵ�Ƕ���
		//������Ϳ���֪��account�е�account_idֵ�Ƕ�����
		account.account_id = static_cast<int>(db.GetInsertId());

		//����һ��������ˮ���������ױ��в���һ����account_id��صļ�¼�����׽���Լ����
		ss<<"insert into trans values(null, "<<
			account.account_id<<", null, "<<
			1<<", "<<
			setprecision(2)<<setiosflags(ios::fixed)<<account.balance<<", "<<
			setprecision(2)<<setiosflags(ios::fixed)<<account.balance<<
			",  now());";

		ret = db.ExecSQL(ss.str().c_str());

		db.Commit();

		ss.clear();
		ss.str("");
		//���ؿ�������
		ss<<"select open_date from bank_account where account_id='"<<
			account.account_id<<"';";
		MysqlRecordset rs = db.QuerySQL(ss.str().c_str());
		account.op_date = rs.GetItem(0, "open_date");//���ظ��ͻ��ˣ�������op_date

	}
	catch (Exception& e)
	{
		LOG_INFO<<e.what();
		db.Rollback();
		return -1;
	}

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
