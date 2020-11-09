#include <math.h>
#include <iostream>
using namespace std;

class Point
{
	//Distance函数不是Point类的成员函数
	friend double Distance(const Point& p1, const Point& p2);
public:
	Point(int x, int y);
private:
	//friend double Distance(const Point& p1, const Point& p2);防着也行
	int x_;
	int y_;
};

Point::Point(int x, int y) : x_(x), y_(y)
{

}

//Distance友元函数的作用域在类体之外，就算在类体里面定义
//友元函数可以访问类的私有成员
//友元函数的作用域与main一样，都是全局的
double Distance(const Point& p1, const Point& p2)
{
	double dx = p1.x_ - p2.x_;
	double dy = p1.y_ - p2.y_;

	return sqrt(dx*dx + dy*dy);
}

int main(void)
{
	Point p1(3, 4);
	Point p2(6, 8);

	cout<<Distance(p1, p2)<<endl;
	return 0;
}
