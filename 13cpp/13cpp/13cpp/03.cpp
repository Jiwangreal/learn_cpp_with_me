#include <iostream>
using namespace std;

// const成员的初始化只能在构造函数初始化列表中进行
// 引用成员的初始化也只能在构造函数初始化列表中进行
// 对象成员（对象所对应的类没有默认构造函数）的初始化，也只能在构造函数初始化列表中进行
class Object
{
public:
	enum E_TYPE
	{
		//TYPE_A和TYPE_B对所有对象来讲，都是常量
		TYPE_A = 100,
		TYPE_B = 200
	};
public:
	Object(int num=0) : num_(num), kNum_(num), refNum_(num_)
	{
		//kNum_ = 100;//放在这里只是赋值，不是初始化
		//refNum_ = num_;//放在这里只是赋值，不是初始化
		cout<<"Object "<<num_<<" ..."<<endl;
	}
	~Object()
	{
		cout<<"~Object "<<num_<<" ..."<<endl;
	}

	void DisplayKNum()
	{
		cout<<"kNum="<<kNum_<<endl;
	}
private:
	int num_;
	//常量一旦内存分配了，就要进行初始化，所以只能放在初始化列表中进行
	const int kNum_;// const成员的初始化只能在构造函数初始化列表中进行
	int& refNum_;// 引用成员的初始化也只能在构造函数初始化列表中进行
};

int main(void)
{
	Object obj1(10);//kNum_只在对象内部是常量，不同的对象有不同的值，并不是所有对象都是常量，除非用枚举来实现
	Object obj2(20);
	obj1.DisplayKNum();
	obj2.DisplayKNum();

	//TYPE_A对任何对象来说都是常量
	cout<<obj1.TYPE_A<<endl;
	cout<<obj2.TYPE_A<<endl;
	cout<<Object::TYPE_A<<endl;


	return 0;
}