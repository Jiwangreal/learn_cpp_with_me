#include "String.h"
#include <iostream>
using namespace std;


int main(void)
{
	String s1("abc");
	String s2(s1);//��ʱ����ÿ������캯��

	String s3;
	s3 = s1;//��ʱ�����=�Ⱥ������������ֵ�����
	s3.Display();

	//��1��Ŀǰ��ôд�Ļ���"xxxx"ִ�еȺ���������Ⱥ���������Խ���һ���ַ�����String& operator=(const char* str);
	//��2������д��1���ķ�ʽ����explicit String(const char* str="");д�ɣ�String(const char* str="");�Ȱ�"xxxx"ת�������
	//Ϊһ������Ȼ���ٵ��õȺ������
	s3 = "xxxx";
	s3.Display();

	String s4;
	bool notempty;
	notempty = !s4;//�����ַ���Ϊ��
	cout<<notempty<<endl;

	s4 = "aaaa";
	notempty = !s4;//�����ַ����ǿ�
	cout<<notempty<<endl;

	return 0;
}