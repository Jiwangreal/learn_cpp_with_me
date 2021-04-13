#include "JUtil.h"

#include <sstream>
using namespace PUBLIC;
using namespace std;

int Convert::StringToInt(const string& str)
{
	stringstream ss;
	ss<<str;//�Ȳ��뵽�ַ�����
	int x;
	ss>>x;//����ȡ�����ͱ���

	return x;
}

string Convert::IntToString(int x)
{
	stringstream ss;
	ss<<x;
	string str;
	ss>>str;

	return str;
}

double Convert::StringToDouble(const string& str)
{
	stringstream ss;
	ss<<str;
	double x;
	ss>>x;

	return x;
}

string Convert::DoubleToString(double x)
{
	stringstream ss;
	ss<<x;
	string str;
	ss>>str;

	return str;
}