#include "Test.h"
#include <iostream>
using namespace std;

// ���������Ĺ��캯����ΪĬ�Ϲ��캯��
Test::Test()
{
	num_ = 0;
	cout<<"Initializing Default"<<endl;
}

Test::Test(int num)
{
	num_ = num;
	cout<<"Initializing "<<num_<<endl;
}

Test::~Test()
{
	cout<<"Destroy "<<num_<<endl;
}

void Test::Display()
{
	cout<<"num="<<num_<<endl;
}

Test& Test::operator=(const Test& other)
{
	cout<<"Test::operator="<<endl;
	//���Է�ֹt=t��ͬһ�������ֹ��ֵ
	if (this == &other)
		return *this;
	//��ͬ�Ķ���������ͬ��Ҳ������ֵ������Ҫ��if (*this == other)��
	//����ǰ����==���������Ҫ����
	

	//��other������ÿһ����Ա����ֵ����ǰ�����ÿһ����Ա�����Ա��ֵ
	num_ = other.num_;
	return *this;//���ض�������
}