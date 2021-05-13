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
	//通过单例对象server，从配置文件ABCBank-0.3.1\ABCBank\Bin\server.conf中获取DB的ip等
	Server& server = Singleton<Server>::Instance();

	try
	{
		db.Open(server.GetDbServerIp().c_str(),
			server.GetDbUser().c_str(),
			server.GetDbPass().c_str(),
			server.GetDbName().c_str(),//数据库的名称
			server.GetDbServerPort());

		stringstream ss;
		ss<<"select teller_name from teller where teller_name='"<<
			user<<"' and teller_pass='"<<
			pass<<"';";
		MysqlRecordset rs;
		rs = db.QuerySQL(ss.str().c_str());

		//找到记录，应该>=1，一般是=1的，就找到了
		if (rs.GetRows() < 1)
			return 1;//返回值参照：ABCBank项目手册中的2.2.2.1.6错误代码与错误信息对照表
					//1表示用户名或密码错误
	}
	catch (Exception& e)
	{
		LOG_INFO<<e.what();
		return -1;//-1表示数据库错误
	}

	return 0;
}


// 开户
//account是一个输入输出值
int BankService::OpenAccount(Account& account)
{
	MysqlDB db;
	Server& server = Singleton<Server>::Instance();

	try
	{
		//先打开数据库
		db.Open(server.GetDbServerIp().c_str(),
			server.GetDbUser().c_str(),
			server.GetDbPass().c_str(),
			server.GetDbName().c_str(),
			server.GetDbServerPort());

		//开启事务
		db.StartTransaction();

		//将sql语句拼接起来放在流当中
		/*直接用string类也行，可以直接拼接
		string ss;
		ss + "aaa" + "b"
		*/
		//stringstream的好处是可以格式化，setprecision(2)<<setiosflags(ios::fixed)<<account.balance
		//将余额精度格式为2位有效数字
		stringstream ss;
		//id字段是自动增长的，要填写null
		ss<<"insert into bank_account values(null, '"<<
			account.name<<"', '"<<
			account.pass<<"', '"<<
			account.id<<"', "<<
			//这里插入的日期用的是now()
			setprecision(2)<<setiosflags(ios::fixed)<<account.balance<<", now(), "<<
			0<<");";
		unsigned long long ret = db.ExecSQL(ss.str().c_str());


		ss.clear();
		ss.str("");
		//获取实际的id值
		//说明account是一个输入输出值，输入的时候并不知道account中的account_id值是多少
		//在这里就可以知道account中的account_id值是多少了
		account.account_id = static_cast<int>(db.GetInsertId());

		//生成一个交易流水，即往交易表中插入一条与account_id相关的记录：交易金额以及余额
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
		//返回开户日期
		ss<<"select open_date from bank_account where account_id='"<<
			account.account_id<<"';";
		MysqlRecordset rs = db.QuerySQL(ss.str().c_str());
		account.op_date = rs.GetItem(0, "open_date");//返回给客户端，保存在op_date

	}
	catch (Exception& e)
	{
		LOG_INFO<<e.what();
		db.Rollback();
		return -1;
	}

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
