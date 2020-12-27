#include <iostream>
#include <memory>
using namespace std;

//为什么Noncopyable类是禁止拷贝的？
//（1）【采用】禁止对象拷贝的eg演示
//Noncopyable不能构造对象，因为构造对象没意义，仅仅用来继承
class Noncopyable
{
protected:
    Noncopyable() {};
    ~Noncopyable() {};
private:
    Noncopyable(const Noncopyable&);
    const Noncopyable& operator=(const Noncopyable&);
};

//这里继承方式是private的，why？
//这里仅仅是继承它的实现，是继承它的实现，而不是继承它的接口，所以是实现继承，而不是接口继承
class Parent : private Noncopyable
{
public:
	//构造函数会调用基类的构造函数，即使没有写出Parent(): Noncopyable()，也是会自动调用的
	Parent()//若基类没有默认构造函数，那么在子类的成员函数列表中给出基类构造函数的调用
	{

	}
	//拷贝构造函数会调用基类的拷贝构造函数，但是只有Parent(const Parent& other) : Noncopyable(other)这么去写
	//才会调用基类的拷贝构造函数的
	Parent(const Parent& other) : Noncopyable(other)
	{

	}
};

//Parent是禁止拷贝的，其子类Child也是禁止拷贝的，因为它也继承了Noncopyable的实现
class Child : public Parent 
{

};

int main(void)
{
	Parent p1;//调用构造函数
	//调用拷贝构造函数，如果这么写：Parent(const Parent& other){}，
	//Parent中实现了拷贝构造函数，是不会调用基类的拷贝构造函数，那么私有的Noncopyable(const Noncopyable&);这个限制就不生效了
	Parent p2(p1);//要调用Parent拷贝构造函数，Parent构造函数又调用Noncopyable的拷贝构造函数
				  //基类的私有成员在派生类中是不能被访问的，所以编译会失败，即使能访问，基类也没
				  //给出实现，同样也会出错

	// Child c1;
	// Child c2(c1);
	return 0;
}