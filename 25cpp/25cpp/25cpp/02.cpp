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

	//打开数据库
	void Open()
	{
		cout<<"Open ..."<<endl;
	}

	//关闭数据库
	void Close()
	{
		cout<<"Close ..."<<endl;
	}

	//查询数据库
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
		//构造一个DBHelper对象
		db_ = new DBHelper;
	}

	~DB()
	{
		delete db_;
	}

	//重载指针运算符->
	//指针运算符重载返回一个内部的指针，然后通过内部的指针访问DBHelper的成员函数
	DBHelper* operator->()
	{
		return db_;
	}
private:
	DBHelper* db_;//DBHelper对象，函数指针是db_
};


int main(void)
{
	//利用类对象db确定析构机制，将它所包装的动态对象销毁掉
	DB db;
	db->Open();
	db->Query();
	db->Close();


	return 0;
}