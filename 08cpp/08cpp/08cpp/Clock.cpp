#include "Clock.h"
#include <iostream>
using namespace std;

void Clock::Display()//::域运算符，表示Display函数属于Clock类
{
	cout<<hour_<<":"<<minute_<<":"<<second_<<endl;
}

void Clock::Init(int hour, int minute, int second)
{
	hour_ = hour;
	minute_ = minute;
	second_ = second;
}

void Clock::Update()
{
	second_++;
	if (second_ == 60)
	{
		minute_++;
		second_ = 0;
	}
	if (minute_ == 60)
	{
		hour_++;
		minute_ = 0;
	}
	if (hour_ == 24)
	{
		hour_ = 0;
	}
}

int Clock::GetHour()
{
	return hour_;
}

int Clock::GetMinute()
{
	return minute_;
}

int Clock::GetSecond()
{
	return second_;
}

void Clock::SetHour(int hour)
{
	hour_ = hour;
}

void Clock::SetMinute(int minute)
{
	minute_ = minute;
}

void Clock::SetSecond(int second)
{
	second_ = second;
}