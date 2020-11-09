#include <math.h>
#include <iostream>
using namespace std;

class Point
{
	//Distance��������Point��ĳ�Ա����
	friend double Distance(const Point& p1, const Point& p2);
public:
	Point(int x, int y);
private:
	//friend double Distance(const Point& p1, const Point& p2);����Ҳ��
	int x_;
	int y_;
};

Point::Point(int x, int y) : x_(x), y_(y)
{

}

//Distance��Ԫ������������������֮�⣬�������������涨��
//��Ԫ�������Է������˽�г�Ա
//��Ԫ��������������mainһ��������ȫ�ֵ�
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
