#include "CountedObject.h"
#include <iostream>
using namespace std;

int main(void)
{
	//可以通过类直接访问静态成员
	//cout<<CountedObject::count_<<endl;
	//GetCount是静态成员函数
	cout<<CountedObject::GetCount()<<endl;
	CountedObject co1;
	//cout<<CountedObject::count_<<endl;
	cout<<CountedObject::GetCount()<<endl;
	CountedObject* co2 = new CountedObject;//若没有任何参数，就不要写成：new CountedObject()
	//cout<<CountedObject::count_<<endl;
	cout<<CountedObject::GetCount()<<endl;
	delete co2;
	//cout<<CountedObject::count_<<endl;
	cout<<CountedObject::GetCount()<<endl;

}