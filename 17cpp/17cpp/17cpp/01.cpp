#include <iostream>
using namespace std;

class Date
{
public:
	Date(int year) : year_(year)
	{

	}
	//�ж�����Ƿ�������
	static bool IsLeapYear(int year)
	{
		return (year % 4 == 0 && year % 100 != 0) || (year % 400 ==0);
	}
	bool IsLeapYear()
	{
		return (year_ % 4 == 0 && year_ % 100 != 0) || (year_ % 400 ==0);
	}
private:
	int year_;
};

int main(void)
{
	// Date d(2012);
	cout<<d.IsLeapYear()<<endl;
	
	//ʹ�þ�̬��Ա����������Ҫ����һ�����ڶ��󣬾��ܷ��ʣ�����ֱ���жϸ������Ƿ�������
	cout<<Date::IsLeapYear(2010)<<endl;
	return 0;
}