#include "Clock.h"
#include <iostream>
using namespace std;

void Clock::Display()
{
	cout<<hour_<<":"<<minute_<<":"<<second_<<endl;
}

Clock::Clock(int hour/* =0 */, int minute/* =0 */, int second/* =0 */)
{
	hour_ = hour;
	minute_ = minute;
	second_ = second;
	cout<<"Clock::Clock"<<endl;
}

Clock::~Clock()
{
	cout<<"Clock::~Clock"<<endl;
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