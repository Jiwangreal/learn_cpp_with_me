#include "Server.h"
#include "../Public/MD5.h"

#include <stdio.h>
using namespace PUBLIC;

int main(void)
{
	//MD5���ʹ��
	//MD5 md5;

	//unsigned char hash[16];�������16bytes�Ĺ�ϣ�ַ���
	//���ܵ��ַ�����cppcourse
	//�����ַ����ĳ��ȣ�9
	//������ַ�����hash
	//md5.MD5Make(hash, (unsigned char const *)"cppcourse", 9);
	
	//��16bytes���ַ������Ϊ32bytes���ַ���
	//int i;
	//for (i=0; i<16; ++i)
	//{
	//	printf("%0X", hash[i]);
	//}

	//printf("\n");
	return Singleton<Server>::Instance().Start();
}