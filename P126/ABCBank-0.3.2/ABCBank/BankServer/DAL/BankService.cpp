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
	Server& server = Singleton<Server>::Instance();

	try
	{
		db.Open(server.GetDbServerIp().c_str(),
			server.GetDbUser().c_str(),
			server.GetDbPass().c_str(),
			server.GetDbName().c_str(),
			server.GetDbServerPort());

		stringstream ss;
		ss<<"select teller_name from teller where teller_name='"<<
			user<<"' and teller_pass='"<<
			pass<<"';";
		MysqlRecordset rs;
		rs = db.QuerySQL(ss.str().c_str());
		if (rs.GetRows() < 1)
			return 1;
	}
	catch (Exception& e)
	{
		LOG_INFO<<e.what();
		return -1;
	}

	return 0;
}


// 开户
int BankService::OpenAccount(Account& account)
{
	MysqlDB db;
	Server& server = Singleton<Server>::Instance();

	try
	{
		db.Open(server.GetDbServerIp().c_str(),
			server.GetDbUser().c_str(),
			server.GetDbPass().c_str(),
			server.GetDbName().c_str(),
			server.GetDbServerPort());

		db.StartTransaction();

		stringstream ss;
		ss<<"insert into bank_account values(null, '"<<
			account.name<<"', '"<<
			account.pass<<"', '"<<
			account.id<<"', "<<
			setprecision(2)<<setiosflags(ios::fixed)<<account.balance<<", now(), "<<
			0<<");";
		unsigned long long ret = db.ExecSQL(ss.str().c_str());


		ss.clear();
		ss.str("");
		account.account_id = static_cast<int>(db.GetInsertId());
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
		ss<<"select open_date from bank_account where account_id='"<<
			account.account_id<<"';";
		MysqlRecordset rs = db.QuerySQL(ss.str().c_str());
		account.op_date = rs.GetItem(0, "open_date");

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
	/*
	存款的含义：
	查询余额；
	对余额进行更新操作；
	把他们放到一个事务当中
	select balance from bank_account where account_id=5 for update;
	update bank_account set balance=balance+100 where account_id=5;
	insert into trans values(...);
	*/


	MysqlDB db;
	Server& server = Singleton<Server>::Instance();

	try
	{
		db.Open(server.GetDbServerIp().c_str(),
			server.GetDbUser().c_str(),
			server.GetDbPass().c_str(),
			server.GetDbName().c_str(),
			server.GetDbServerPort());

		//开始事务，相当于BEGIN
		db.StartTransaction();

		//相当于：select … for update，一个事务开始
		stringstream ss;
		ss<<"select balance from bank_account where account_id="<<
			account.account_id<<
			" and flag=0 for update;";

		MysqlRecordset rs = db.QuerySQL(ss.str().c_str());
		if (rs.GetRows() < 1)	// 帐户不存在
			return 2;

		// 帐户余额
		double balance = Convert::StringToDouble(rs.GetItem(0, "balance"));

		//对账户进行更新，update
		ss.clear();
		ss.str("");
		ss<<"update bank_account set balance=balance+"<<
			setprecision(2)<<setiosflags(ios::fixed)<<account.balance<<" where account_id="<<
			account.account_id<<";";
		unsigned long long ret = db.ExecSQL(ss.str().c_str());
		
		ss.clear();
		ss.str("");
		//因为account_id是自动增长的,所以insert into trans values(null这里填写的是null
		ss<<"insert into trans values(null, "<<
			account.account_id<<", null, "<<
			2<<", "<<
			setprecision(2)<<setiosflags(ios::fixed)<<account.balance<<", "<<
			setprecision(2)<<setiosflags(ios::fixed)<<balance+account.balance<<
			",  now());";

		//相当于：select … for update，一个事务结束，因为需要对bank_account表和trans表操作，要么都成功，要么都失败
		//所以insert操作也要纳入到事务中

		ret = db.ExecSQL(ss.str().c_str());

		/*
		select a.name, b.balance, b.trans_date
		from bank_account a, 
		(select account_id, balance, trans_date from trans where trans_id=1) b
		where a.account_id=b.account_id;
		*/

		//提交，相当于COMMIT
		//获取完GetInsertId之后才可以进行提交，因为account_id是自动增长的
		int trans_id = static_cast<int>(db.GetInsertId());
		db.Commit();


		//查询交易日期，然后回给客户端
		ss.clear();
		ss.str("");
		ss<<"select a.name, b.trans_date "<<
			"from bank_account a, "<<
			"(select account_id, trans_date from trans where trans_id="<<
			trans_id<<") b "<<
			"where a.account_id=b.account_id;";
		rs.Clear();
		rs = db.QuerySQL(ss.str().c_str());
		account.name = rs.GetItem(0, "name");
		account.op_date = rs.GetItem(0, "trans_date");
		account.balance += balance;


	}
	catch (Exception& e)
	{
		db.Rollback();//任何一个过程出现错误，都应该回滚事务
		LOG_INFO<<e.what();
		return -1;
	}

	return 0;
}

// 取款
int BankService::WithDraw(Account& account)
{
	MysqlDB db;
	Server& server = Singleton<Server>::Instance();

	try
	{
		db.Open(server.GetDbServerIp().c_str(),
			server.GetDbUser().c_str(),
			server.GetDbPass().c_str(),
			server.GetDbName().c_str(),
			server.GetDbServerPort());

		db.StartTransaction();

		//也需要使用select … for update
		stringstream ss;
		ss<<"select balance from bank_account where account_id="<<
			account.account_id<<
			" and flag=0;";
		
		//判断账号是否存在
		MysqlRecordset rs = db.QuerySQL(ss.str().c_str());
		if (rs.GetRows() < 1)	// 帐户不存在，记录数<1，或者account.account_id < 1也可以判断
			return 2;

		ss.clear();
		ss.str("");
		ss<<"select balance from bank_account where account_id="<<
			account.account_id<<" and pass="<<account.pass<<" for update;";

		rs.Clear();
		rs = db.QuerySQL(ss.str().c_str());
		if (rs.GetRows() < 1)	// 密码错误
			return 3;//返回值见：ABCBank项目手册.doc中的2.2.2.1.6	错误代码与错误信息对照表

		double balance = Convert::StringToDouble(rs.GetItem(0, "balance"));

		//当前取款的余额大于账户余额
		if (account.balance > balance)	// 余额不足
			return 4;

		//update，明细表插入一条交易流水
		ss.clear();
		ss.str("");
		ss<<"update bank_account set balance=balance-"<<
			setprecision(2)<<setiosflags(ios::fixed)<<account.balance<<" where account_id="<<
			account.account_id<<";";
		unsigned long long ret = db.ExecSQL(ss.str().c_str());


		ss.clear();
		ss.str("");
		ss<<"insert into trans values(null, "<<
			account.account_id<<", null, "<<
			3<<", "<<
			setprecision(2)<<setiosflags(ios::fixed)<<account.balance<<", "<<
			setprecision(2)<<setiosflags(ios::fixed)<<balance-account.balance<<
			",  now());";

		ret = db.ExecSQL(ss.str().c_str());
		int trans_id = static_cast<int>(db.GetInsertId());//返回当前的交易id
		db.Commit();

		//根据交易id获取交易时间
		ss.clear();
		ss.str("");
		ss<<"select a.name, b.trans_date "<<
			"from bank_account a, "<<
			"(select account_id, trans_date from trans where trans_id="<<
			trans_id<<") b "<<
			"where a.account_id=b.account_id;";
		rs.Clear();
		rs = db.QuerySQL(ss.str().c_str());
		account.name = rs.GetItem(0, "name");
		account.op_date = rs.GetItem(0, "trans_date");
		account.balance = balance - account.balance;


	}
	catch (Exception& e)
	{
		LOG_INFO<<e.what();
		db.Rollback();
		return -1;
	}

	return 0;
}
// 转帐
int BankService::Transfer(Account& account, const string& otherAccountId)
{
	MysqlDB db;
	Server& server = Singleton<Server>::Instance();

	try
	{
		db.Open(server.GetDbServerIp().c_str(),
			server.GetDbUser().c_str(),
			server.GetDbPass().c_str(),
			server.GetDbName().c_str(),
			server.GetDbServerPort());

		db.StartTransaction();
		stringstream ss;

		ss<<"select balance from bank_account where account_id="<<
			account.account_id<<
			" and flag=0;";
		MysqlRecordset rs = db.QuerySQL(ss.str().c_str());
		if (rs.GetRows() < 1)	// 帐户不存在
			return 2;

		ss.clear();
		ss.str("");
		ss<<"select balance from bank_account where account_id="<<
			account.account_id<<" and pass="<<account.pass<<" for update;";
		rs.Clear();
		rs = db.QuerySQL(ss.str().c_str());
		if (rs.GetRows() < 1)	// 密码错误
			return 3;

		double balance = Convert::StringToDouble(rs.GetItem(0, "balance"));
		if (account.balance > balance)	// 余额不足
			return 4;

		ss.clear();
		ss.str("");
		ss<<"select balance from bank_account where account_id="<<
			otherAccountId<<
			" and flag=0 for update;";
		rs.Clear();
		rs = db.QuerySQL(ss.str().c_str());
		if (rs.GetRows() < 1)	// 对方帐号不存在
			return 5;

		double balance2 = Convert::StringToDouble(rs.GetItem(0, "balance"));

		//更新自己的账户，自己的余额需要-
		ss.clear();
		ss.str("");
		ss<<"update bank_account set balance=balance-"<<
			setprecision(2)<<setiosflags(ios::fixed)<<account.balance<<" where account_id="<<
			account.account_id<<";";
		unsigned long long ret = db.ExecSQL(ss.str().c_str());
		
		//更新对方的账户，余额需要+
		ss.clear();
		ss.str("");
		ss<<"update bank_account set balance=balance+"<<
			setprecision(2)<<setiosflags(ios::fixed)<<account.balance<<" where account_id="<<
			otherAccountId<<";";
		ret = db.ExecSQL(ss.str().c_str());


		ss.clear();
		ss.str("");
		ss<<otherAccountId;
		int other_account_id;
		ss>>other_account_id;

		//每个账户金额的变动，都需要在trans表中增加交易流水
		//5from：abstract表，5表示转出
		//自己的账户
		ss.clear();
		ss.str("");
		ss<<"insert into trans values(null, "<<
			account.account_id<<", "<<
			other_account_id<<
			", "<<5<<", "<<
			setprecision(2)<<setiosflags(ios::fixed)<<account.balance<<", "<<
			setprecision(2)<<setiosflags(ios::fixed)<<balance-account.balance<<
			",  now());";

		ret = db.ExecSQL(ss.str().c_str());

		int trans_id = static_cast<int>(db.GetInsertId());
		ss.clear();
		ss.str("");
		ss<<"select a.name, b.trans_date "<<
			"from bank_account a, "<<
			"(select account_id, trans_date from trans where trans_id="<<
			trans_id<<") b "<<
			"where a.account_id=b.account_id;";
		rs.Clear();
		rs = db.QuerySQL(ss.str().c_str());

		//对方的账户是转入的操作，4表示转入
		ss.clear();
		ss.str("");
		ss<<"insert into trans values(null, "<<
			other_account_id<<", "<<
			account.account_id<<
			", "<<4<<", "<<
			setprecision(2)<<setiosflags(ios::fixed)<<account.balance<<", "<<
			setprecision(2)<<setiosflags(ios::fixed)<<balance2+account.balance<<
			",  now());";

		ret = db.ExecSQL(ss.str().c_str());

		db.Commit();

		account.balance = balance - account.balance;
		account.name = rs.GetItem(0, "name");
		account.op_date = rs.GetItem(0, "trans_date");

	}
	catch (Exception& e)
	{
		db.Rollback();
		LOG_INFO<<e.what();
		return -1;
	}

	return 0;
}
// 查询余额
int BankService::BalanceInquiry(Account& account)
{
	MysqlDB db;
	Server& server = Singleton<Server>::Instance();

	try
	{
		db.Open(server.GetDbServerIp().c_str(),
			server.GetDbUser().c_str(),
			server.GetDbPass().c_str(),
			server.GetDbName().c_str(),
			server.GetDbServerPort());

		stringstream ss;
		ss<<"select balance from bank_account where account_id="<<
			account.account_id<<
			" and flag=0;";
		MysqlRecordset rs = db.QuerySQL(ss.str().c_str());
		if (rs.GetRows() < 1)	// 帐户不存在
			return 2;

		ss.clear();
		ss.str("");
		ss<<"select balance from bank_account where account_id="<<
			account.account_id<<" and pass="<<account.pass<<";";

		rs.Clear();
		rs = db.QuerySQL(ss.str().c_str());
		if (rs.GetRows() < 1)	// 密码错误
			return 3;

		account.balance = Convert::StringToDouble(rs.GetItem(0, "balance"));

		//查询操作，不会对数据库中的数据进行更新，所以不需要加锁
		//也就是说，一个事务的执行不会影响到另一个事务的并发执行
		ss.clear();
		ss.str("");
		ss<<"select name, now() query_date from bank_account "<<
			"where account_id="<<
			account.account_id<<";";
		rs.Clear();
		rs = db.QuerySQL(ss.str().c_str());
		account.name = rs.GetItem(0, "name");
		account.op_date = rs.GetItem(0, "query_date");
	}
	catch (Exception& e)
	{
		LOG_INFO<<e.what();
		return -1;
	}

	return 0;
}

// 修改密码
int BankService::ChangePassword(Account& account, const string& newPass)
{
	MysqlDB db;
	Server& server = Singleton<Server>::Instance();

	try
	{
		db.Open(server.GetDbServerIp().c_str(),
			server.GetDbUser().c_str(),
			server.GetDbPass().c_str(),
			server.GetDbName().c_str(),
			server.GetDbServerPort());

		stringstream ss;
		ss<<"select balance from bank_account where account_id="<<
			account.account_id<<
			" and flag=0;";
		MysqlRecordset rs = db.QuerySQL(ss.str().c_str());
		if (rs.GetRows() < 1)	// 帐户不存在
			return 2;

		ss.clear();
		ss.str("");
		ss<<"select balance from bank_account where account_id="<<
			account.account_id<<" and pass="<<account.pass<<";";

		rs.Clear();
		rs = db.QuerySQL(ss.str().c_str());
		if (rs.GetRows() < 1)	// 密码错误
			return 3;

		ss.clear();
		ss.str("");
		ss<<"update bank_account set pass='"<<
			newPass<<"' "<<
			"where account_id="<<
			account.account_id<<";";

		db.ExecSQL(ss.str().c_str());
	}
	catch (Exception& e)
	{
		LOG_INFO<<e.what();
		return -1;
	}

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
