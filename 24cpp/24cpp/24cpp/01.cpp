#include "String.h"
#include <iostream>
using namespace std;

int main(void)
{
	String s1("abcdefg");

	char ch = s1[2];
	cout<<ch<<endl;

	//һ�������������õĻ�����ô���Ϳ��Գ����ڱ��ʽ����ߣ�����Ƿ������õĺô�
	s1[2] = 'A';
	s1.Display();

	const String s2("xyzabc");//����ã�const char& String::operator[](unsigned int index) const
	ch = s2[2];
	//s2[2] = 'M';//��Ϊs2��const���������������ֲ��������Է��ص�������const���ü���
	s2.Display();


	String s3 = "xxx";
	String s4 = "yyy";

	String s5 = s3 + s4;//����Ҫ����һ���¶��󣬸�ֵ��s5�������޸�s3��s4�����ֵ
	s5.Display();

	//��Ϊ��aaa�����Ե���String(const char* str="");ת�������һ���ַ��������
	//��Ϊ����������Ԫ�ķ�ʽ�����صģ��������ó�Ա�����ķ�ʽ����Ա�������������ĵ�һ�������Ƕ��������������ַ���
	String s6 = "aaa" + s3 + "sdfadfa" + "xxxx";
	//String s6 = "xxx" + "aaa" + s3 + "sdfadfa" + "xxxx";//������������Ϊû������2��char*�����������ӷ�ʱ��
	//ǰ2��������һ���Ƕ���
	s6.Display();

	s3+=s4;
	s3.Display();

	//����������Ƕ�Ԫ�ģ���һ������������������cout���ڶ���������Ҫ����Ķ�����s3
	//�����Գ�Ա�����ķ�ʽ���أ���Ϊ���Գ�Ա�����ķ�ʽ���أ���һ���������ɶ��������������ǲ������
	cout<<s3<<endl;

	String s7;
	cin>>s7;//�Ӽ�������
	cout<<s7<<endl;



	return 0;
}