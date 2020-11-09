//#pragma once
//作用：防止头文件重复包含，等价于#ifndef。。。。。。。#endif

#ifndef _CLOCK_H_
#define _CLOCK_H_

//类的数据成员：表示类的属性，状态
//类的成员函数：表示类的行为
class Clock
{
public:
	void Display();
	void Init(int hour, int minute, int second);
	void Update();

	int GetHour();
	int GetMinute();
	int GetSecond();

	void SetHour(int hour);
	void SetMinute(int minute);
	void SetSecond(int second);
private:
	int hour_;
	int minute_;
	int second_;
};
#endif // _CLOCK_H_

