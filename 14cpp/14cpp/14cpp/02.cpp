#include "Test.h"
#include <iostream>
using namespace std;

void TestFun(const Test t)//����t���������ڿ����������ڣ��������ڽ������ͻ�����
{

}

void TestFun2(const Test& t)
{

}

Test TestFun3(const Test& t)
{
	return t;
}

const Test& TestFun4(const Test& t)
{
	//return const_cast<Test&>(t);
	return t;
}

int main(void)
{
	Test t(10);
	TestFun(t);//����ÿ������캯��
	TestFun2(t);//������ÿ������캯������Ϊ���ݵ������ã������ββ��ṹ��һ�����󣬷����ڴ棬�βκ�ʵ�ι���ͬһ���ڴ�


	return 0;
}