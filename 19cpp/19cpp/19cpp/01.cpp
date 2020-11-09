#include <iostream>
using namespace std;

class Test
{
public:
	Test(int x) : x_(x), outputTimes_(0)
	{

	}

	//const成员函数：不能修改数据成员的值
	//const成员函数与非const成员函数可以构成重载
	int GetX() const
	{
		cout<<"const GetX ..."<<endl;
		//x_ = 100;
		return x_;
	}

	int GetX()
	{
		cout<<"GetX ..."<<endl;
		return x_;
	}

	void Output() const
	{
		cout<<"x="<<x_<<endl;
		outputTimes_++;//const成员函数不能修改非const的数据成员的值！！
						//const成员函数可以修改mutable的数据成员
	}

	int GetOutputTimes() const
	{
		return outputTimes_;
	}
private:
	int x_;

	mutable int outputTimes_;//统计变量输出的次数
};

int main(void)
{
	const Test t(10);//const对象：对象是常量，对象的状态不能被更改
	t.GetX();//const对象只能调用const成员函数(包括构造函数)

	Test t2(20);
	t2.GetX();

	t.Output();
	t.Output();
	cout<<t.GetOutputTimes()<<endl;
	return 0;
}