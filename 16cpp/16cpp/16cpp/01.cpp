#include "CountedObject.h"
#include <iostream>
using namespace std;

int main(void)
{
	//����ͨ����ֱ�ӷ��ʾ�̬��Ա
	//cout<<CountedObject::count_<<endl;
	//GetCount�Ǿ�̬��Ա����
	cout<<CountedObject::GetCount()<<endl;
	CountedObject co1;
	//cout<<CountedObject::count_<<endl;
	cout<<CountedObject::GetCount()<<endl;
	CountedObject* co2 = new CountedObject;//��û���κβ������Ͳ�Ҫд�ɣ�new CountedObject()
	//cout<<CountedObject::count_<<endl;
	cout<<CountedObject::GetCount()<<endl;
	delete co2;
	//cout<<CountedObject::count_<<endl;
	cout<<CountedObject::GetCount()<<endl;

}