#include "Integer.h"
#include <iostream>
using namespace std;

Integer::Integer(int n) : n_(n)
{
}

Integer::~Integer()
{
}

//ǰ�������
//�Գ�Ա�����ķ�ʽ����
//���ص������ã�������ÿ������캯��
Integer& Integer::operator ++()
{
	//cout<<"Integer& Integer::operator ++()"<<endl;
	++n_;
	return *this;
}

//����Ԫ�ķ�ʽ������
//Integer& operator++(Integer& i)
//{
//	//cout<<"Integer& operator++(Integer& i)"<<endl;
//	++i.n_;
//	return i;
//}


//���������
Integer Integer::operator++(int n)
{
	//cout<<"Integer& Integer::operator ++()"<<endl;
	//n_++;
	//���صĶ���û��++������Ķ����Ѿ�++
	Integer tmp(n_);//����һ����ʱ���󣬸���ʱ����������ھ��Ǹú��������ڣ����غ����ʧ��
	n_++;
	return tmp;
}

//Integer operator++(Integer& i, int n)
//{
//	Integer tmp(i.n_);
//	i.n_++;
//	return tmp;
//}

void Integer::Display() const
{
	cout<<n_<<endl;
}