#include <iostream>
using namespace std;

class Test
{
public:
	Test(int y) : y_(y)
	{

	}
	~Test()
	{

	}

	void TestFun()
	{
		cout<<"x="<<x_<<endl;	//OK,�Ǿ�̬��Ա�������Է��ʾ�̬��Ա
		TestStaticFun();
	}
	static void TestStaticFun()
	{
		cout<<"TestStaticFun ..."<<endl;
		//TestFun();		Error,��̬��Ա�������ܵ��÷Ǿ�̬��Ա����
		//cout<<"y="<<y_<<endl;		Error,��̬��Ա�������ܷ��ʷǾ�̬��Ա
	}
	static int x_;		// ��̬��Ա��������˵��
	int y_;
};

int Test::x_ = 100;		// ��̬��Ա�Ķ�����˵��

int main(void)
{
	//���С���Ա�����޹أ��뾲̬���ݳ�Ա�޹�
	cout<<sizeof(Test)<<endl;
}