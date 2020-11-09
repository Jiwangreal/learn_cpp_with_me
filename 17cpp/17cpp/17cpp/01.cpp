#include <iostream>
using namespace std;

class Date
{
public:
	Date(int year) : year_(year)
	{

	}
	//判断年份是否是闰年
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
	
	//使用静态成员函数，不需要创建一个日期对象，就能访问，就能直接判断该日期是否是闰年
	cout<<Date::IsLeapYear(2010)<<endl;
	return 0;
}