#include <Windows.h>
#include <mysql.h>
#include <stdio.h>

int main(void)
{

	//下面的方法仅仅初始化conn对象，内部并不会分配MYSQL对象
	// MYSQL conn;
	// mysql_init(&conn);
	// mysql_close(&conn));close时并不释放conn对象，因为conn对象是栈上的变量

	// 初始化一个连接句柄MYSQL
	MYSQL* mysql;
	mysql = mysql_init(NULL);//如果参数是NULL，则内部会分配一个MYSQL对象，即动态创建了一块内存
	if (mysql == NULL)
	{
		printf("error: %s\n", mysql_error(mysql));
		return 1;
	}

	//设置连接选项
	//my_bool实际上是char类型
	my_bool reconnect = true;
	mysql_options(mysql, MYSQL_OPT_RECONNECT, &reconnect);//重连选项
	mysql_options(mysql, MYSQL_SET_CHARSET_NAME, "gbk");//采用的字符集gdb，可以使用中文

	//连接数据库
	/*MYSQL *mysql_real_connect(MYSQL *mysql, const char *host, const char *user, const char *passwd, const char *db, unsigned int port, const char *unix_socket, unsigned long client_flag) 
	参数：mysql连接句柄；
		DB的主机名称；
		用户名；
		密码；
		要连接的数据库；
		端口号，填写0则使用默认端口号3306；
		unix域套接字名称或者命名管道的名称(windows只有命名管道的名称)，通常填写NULL；
		通常填写0即可；
	*/

	//localhost表示本机
	if (!mysql_real_connect(mysql, "localhost", "root", "123456", "scott",
		0, NULL, 0))
	{
		printf("error: %s\n", mysql_error(mysql));
		return 1;
	}

	int result;

	//没有返回结果集的操作
	// sql操作的insert，update，delete没有返回结果集的操作，但是会改变数据库的状态
	//执行查询语句，插入一条记录
	result = mysql_query(mysql, "insert into emp values(8888, 'YYYY', 'CLERK', 7782, '1982-01-23', 1300, null, 30)");
	if (result != 0)
	{
		printf("error: %s\n", mysql_error(mysql));
		return 1;
	}

	//由于没有返回结果集的操作，所以通过mysql_affected_rows函数来判断影响了多少行
	printf("%llu 行受影响\n", mysql_affected_rows(mysql));//mysql_affected_rows返回值是ulonglong，所以用llu打印

	// 有返回结果集的操作
	//查询操作
	result = mysql_query(mysql, "select * from emp where deptno=30;");
	if (result != 0)
	{
		printf("error: %s\n", mysql_error(mysql));
		return 1;
	}

	//对于有返回结果集的操作，取出结果集mysql_res
	MYSQL_RES* mysql_res;
	MYSQL_FIELD* mysql_field;
	MYSQL_ROW mysql_row;//类型其实是char**
	unsigned int cols;
	mysql_res = mysql_store_result(mysql);//取出结果集mysql_res
	cols = mysql_num_fields(mysql_res);//mysql_num_fields表示字段的个数，即列数
	if (mysql_res)
	{
		printf("返回%llu行\n", mysql_num_rows(mysql_res));//行数

		while ((mysql_field = mysql_fetch_field(mysql_res)))//获取每个字段的名称
		{
			printf("%s\t", mysql_field->name);
		}
		printf("\n");

		while ((mysql_row = mysql_fetch_row(mysql_res)))//一行一行获取，行里面有多个列
		{	
			//因为有的字段可能是NULL，所以不能通过空指针来判断，只能通过列的个数来判断
			for (unsigned int i=0; i<cols; ++i)
			{
				printf("%s\t", mysql_row[i] ? mysql_row[i] : "NULL");
			}
			printf("\n");
		}
		mysql_free_result(mysql_res);
	}


	mysql_close(mysql);
	return 0;
}