#include "JUtil.h"

#include <sstream>
using namespace PUBLIC;
using namespace std;

int Convert::StringToInt(const string& str)
{
	stringstream ss;
	ss<<str;//先插入到字符串流
	int x;
	ss>>x;//再提取到整型变量

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