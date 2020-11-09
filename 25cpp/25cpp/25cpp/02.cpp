#include <iostream>
using namespace std;

class DBHelper
{
public:
	DBHelper()
	{
		cout<<"DB ..."<<endl;
	}
	~DBHelper()
	{
		cout<<"~DB ..."<<endl;
	}

	//�����ݿ�
	void Open()
	{
		cout<<"Open ..."<<endl;
	}

	//�ر����ݿ�
	void Close()
	{
		cout<<"Close ..."<<endl;
	}

	//��ѯ���ݿ�
	void Query()
	{
		cout<<"Query ..."<<endl;
	}
};

class DB
{
public:
	DB()
	{
		//����һ��DBHelper����
		db_ = new DBHelper;
	}

	~DB()
	{
		delete db_;
	}

	//����ָ�������->
	//ָ����������ط���һ���ڲ���ָ�룬Ȼ��ͨ���ڲ���ָ�����DBHelper�ĳ�Ա����
	DBHelper* operator->()
	{
		return db_;
	}
private:
	DBHelper* db_;//DBHelper���󣬺���ָ����db_
};


int main(void)
{
	//���������dbȷ���������ƣ���������װ�Ķ�̬�������ٵ�
	DB db;
	db->Open();
	db->Query();
	db->Close();


	return 0;
}