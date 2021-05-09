#include <Windows.h>
#include <mysql.h>
#include <stdio.h>

int main(void)
{

	//����ķ���������ʼ��conn�����ڲ����������MYSQL����
	// MYSQL conn;
	// mysql_init(&conn);
	// mysql_close(&conn));closeʱ�����ͷ�conn������Ϊconn������ջ�ϵı���

	// ��ʼ��һ�����Ӿ��MYSQL
	MYSQL* mysql;
	mysql = mysql_init(NULL);//���������NULL�����ڲ������һ��MYSQL���󣬼���̬������һ���ڴ�
	if (mysql == NULL)
	{
		printf("error: %s\n", mysql_error(mysql));
		return 1;
	}

	//��������ѡ��
	//my_boolʵ������char����
	my_bool reconnect = true;
	mysql_options(mysql, MYSQL_OPT_RECONNECT, &reconnect);//����ѡ��
	mysql_options(mysql, MYSQL_SET_CHARSET_NAME, "gbk");//���õ��ַ���gdb������ʹ������

	//�������ݿ�
	/*MYSQL *mysql_real_connect(MYSQL *mysql, const char *host, const char *user, const char *passwd, const char *db, unsigned int port, const char *unix_socket, unsigned long client_flag) 
	������mysql���Ӿ����
		DB���������ƣ�
		�û�����
		���룻
		Ҫ���ӵ����ݿ⣻
		�˿ںţ���д0��ʹ��Ĭ�϶˿ں�3306��
		unix���׽������ƻ��������ܵ�������(windowsֻ�������ܵ�������)��ͨ����дNULL��
		ͨ����д0���ɣ�
	*/

	//localhost��ʾ����
	if (!mysql_real_connect(mysql, "localhost", "root", "123456", "scott",
		0, NULL, 0))
	{
		printf("error: %s\n", mysql_error(mysql));
		return 1;
	}

	int result;

	//û�з��ؽ�����Ĳ���
	// sql������insert��update��deleteû�з��ؽ�����Ĳ��������ǻ�ı����ݿ��״̬
	//ִ�в�ѯ��䣬����һ����¼
	result = mysql_query(mysql, "insert into emp values(8888, 'YYYY', 'CLERK', 7782, '1982-01-23', 1300, null, 30)");
	if (result != 0)
	{
		printf("error: %s\n", mysql_error(mysql));
		return 1;
	}

	//����û�з��ؽ�����Ĳ���������ͨ��mysql_affected_rows�������ж�Ӱ���˶�����
	printf("%llu ����Ӱ��\n", mysql_affected_rows(mysql));//mysql_affected_rows����ֵ��ulonglong��������llu��ӡ

	// �з��ؽ�����Ĳ���
	//��ѯ����
	result = mysql_query(mysql, "select * from emp where deptno=30;");
	if (result != 0)
	{
		printf("error: %s\n", mysql_error(mysql));
		return 1;
	}

	//�����з��ؽ�����Ĳ�����ȡ�������mysql_res
	MYSQL_RES* mysql_res;
	MYSQL_FIELD* mysql_field;
	MYSQL_ROW mysql_row;//������ʵ��char**
	unsigned int cols;
	mysql_res = mysql_store_result(mysql);//ȡ�������mysql_res
	cols = mysql_num_fields(mysql_res);//mysql_num_fields��ʾ�ֶεĸ�����������
	if (mysql_res)
	{
		printf("����%llu��\n", mysql_num_rows(mysql_res));//����

		while ((mysql_field = mysql_fetch_field(mysql_res)))//��ȡÿ���ֶε�����
		{
			printf("%s\t", mysql_field->name);
		}
		printf("\n");

		while ((mysql_row = mysql_fetch_row(mysql_res)))//һ��һ�л�ȡ���������ж����
		{	
			//��Ϊ�е��ֶο�����NULL�����Բ���ͨ����ָ�����жϣ�ֻ��ͨ���еĸ������ж�
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