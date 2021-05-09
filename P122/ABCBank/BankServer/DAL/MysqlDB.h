#ifndef _MYSQL_DB_H_
#define _MYSQL_DB_H_

//#define WIN32_LEAN_AND_MEAN
#include <winsock2.h>
#include <mysql.h>

#include <vector>
#include <string>
using namespace std;

namespace DAL
{

class MysqlDB;
class MysqlRecordset
{
	friend class MysqlDB;
public:
	//（行，列）
	const string& GetItem(unsigned int nRow, unsigned int nCol) const
	{
		return rows_[nRow][nCol];
	}

	//(行，某一列的名称)
	const string& GetItem(unsigned int nRow, const string& name) const
	{
		unsigned int index = GetFieldIndex(name);
		return rows_[nRow][index];
	}

	//总的行数
	unsigned int GetRows() const
	{
		return rows_.size();
	}

	//总的列数
	unsigned int GetCols() const
	{
		return fields_.size();
	}

	//找到名称在第几列
	unsigned int GetFieldIndex(const std::string &name) const
	{
		unsigned int index = -1;
		for(unsigned int i = 0; i < fields_.size(); ++i)
		{
			if (fields_[i].name == name)
				index = fields_[i].index;
		}
		return index;
	}

	void Clear()
	{
		rows_.clear();
		fields_.clear();
	}

	typedef struct Field
	{
		string name;
		unsigned int index;
	} FIELD;
	typedef vector<FIELD> FIELDS;
	typedef vector<string> ROW;
private:
	vector<ROW> rows_;//行保存在vector中
	FIELDS fields_;//字段保存在vector中
};

class MysqlDB
{
public:
	MysqlDB();
	~MysqlDB();

	//连接管理DB
	void Open(const char* host,
		const char* user,
		const char* passwd,
		const char* db,
		unsigned int port);
	void Close();

	//执行sql语句，无返回结果集
	unsigned long long ExecSQL(const char* sql);
	
	//执行sql语句，有返回结果集
	MysqlRecordset QuerySQL(const char* sql);

	//获取mysql中自动增加的字段id：auto_increment，插入一条记录，mysql该id会+1
	unsigned long long GetInsertId() const;

	//开启事务
	void StartTransaction();
	//提交事务
	void Commit();
	//回滚事务
	void Rollback();


private:
	MYSQL* mysql_;
};

}

#endif // _MYSQL_DB_H_
