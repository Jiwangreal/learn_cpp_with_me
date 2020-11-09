#include <iostream>
using namespace std;

class Object
{
public:
	//对象成员的初始化，应该在初始化列表中提供
	Object(int num) : num_(num)
	{
		cout<<"Object "<<num_<<" ..."<<endl;
	}
	~Object()
	{
		cout<<"~Object "<<num_<<" ..."<<endl;
	}
private:
	int num_;
};


class Container
{
public:
	//总结
	//对数据成员的初始化，推荐放在初始化列表中，包括普通数据成员和对象数据成员
	//如果obj1_对象所对应的Object类没有默认构造函数，那么她的初始化一定要放在Container类的初始化列表中
	//如果有，则可以省略obj1_对象在Container类的初始化列表中的初始化

	Container(int obj1=0, int obj2=0) : obj2_(obj2), obj1_(obj1)
	{
		cout<<"Container ..."<<endl;
	}
	~Container()
	{
		cout<<"~Container ..."<<endl;
	}

private:
	//要构造一个Container对象，首先要构造Object对象，若在初始化列表中没有指定如何构造Object对象，
	//则会调用Object对象的默认构造函数，若Object对象没有默认构造函数，那么编译会报错“没有合适的默认构造函数

	//实例化Container类的一个对象时，其本质是一个内存，obj1_内存在前，obj2_内存在后，所以obj1_对象先构造
	//构造的顺序与定义的顺序有关，和她在Container(int obj1=0, int obj2=0) : obj2_(obj2), obj1_(obj1)初始化
	//列表的顺序无关
	Object obj1_;//定义子对象，也叫对象成员
	Object obj2_;
};

int main(void)
{
	Container c(10,20);//实例化Container对象
	return 0;
}