#ifndef _DATE_H_
#define _DATE_H_

#include <string>

#include <time.h>
#include <stdio.h>

namespace PUBLIC
{

//日期类
class Date
{
public:
	Date()
		: time_(0)
	{}

	//年月日
	Date(int year, int month, int day);

	explicit Date(__time64_t time)
		: time_(time)
	{}

	void swap(Date& that)
	{
		std::swap(time_, that.time_);
	}

	bool valid() const { return time_ != -1; }
	std::string toIsoString() const;

	int year() const;
	int month() const;
	int day() const;
	// [0, 1, ..., 6] => [Sunday, Monday, ..., Saturday ]
	int weekDay() const;

	__time64_t getTime() const
	{
		return time_;
	}
private:
	
	struct tm* getLocalTm(struct tm* ptm) const;
	__time64_t time_;//某个时间到1970年1月1日0点的秒数
};

inline bool operator<(Date x, Date y)
{
	return x.getTime() < y.getTime();
}

inline bool operator==(Date x, Date y)
{
	return x.getTime() == y.getTime();
}

}
#endif  // _DATE_H_
