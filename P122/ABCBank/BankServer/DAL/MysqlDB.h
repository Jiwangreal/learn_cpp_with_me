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
	//���У��У�
	const string& GetItem(unsigned int nRow, unsigned int nCol) const
	{
		return rows_[nRow][nCol];
	}

	//(�У�ĳһ�е�����)
	const string& GetItem(unsigned int nRow, const string& name) const
	{
		unsigned int index = GetFieldIndex(name);
		return rows_[nRow][index];
	}

	//�ܵ�����
	unsigned int GetRows() const
	{
		return rows_.size();
	}

	//�ܵ�����
	unsigned int GetCols() const
	{
		return fields_.size();
	}

	//�ҵ������ڵڼ���
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
	vector<ROW> rows_;//�б�����vector��
	FIELDS fields_;//�ֶα�����vector��
};

class MysqlDB
{
public:
	MysqlDB();
	~MysqlDB();

	//���ӹ���DB
	void Open(const char* host,
		const char* user,
		const char* passwd,
		const char* db,
		unsigned int port);
	void Close();

	//ִ��sql��䣬�޷��ؽ����
	unsigned long long ExecSQL(const char* sql);
	
	//ִ��sql��䣬�з��ؽ����
	MysqlRecordset QuerySQL(const char* sql);

	//��ȡmysql���Զ����ӵ��ֶ�id��auto_increment������һ����¼��mysql��id��+1
	unsigned long long GetInsertId() const;

	//��������
	void StartTransaction();
	//�ύ����
	void Commit();
	//�ع�����
	void Rollback();


private:
	MYSQL* mysql_;
};

}

#endif // _MYSQL_DB_H_
