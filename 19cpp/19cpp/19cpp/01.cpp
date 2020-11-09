#include <iostream>
using namespace std;

class Test
{
public:
	Test(int x) : x_(x), outputTimes_(0)
	{

	}

	//const��Ա�����������޸����ݳ�Ա��ֵ
	//const��Ա�������const��Ա�������Թ�������
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
		outputTimes_++;//const��Ա���������޸ķ�const�����ݳ�Ա��ֵ����
						//const��Ա���������޸�mutable�����ݳ�Ա
	}

	int GetOutputTimes() const
	{
		return outputTimes_;
	}
private:
	int x_;

	mutable int outputTimes_;//ͳ�Ʊ�������Ĵ���
};

int main(void)
{
	const Test t(10);//const���󣺶����ǳ����������״̬���ܱ�����
	t.GetX();//const����ֻ�ܵ���const��Ա����(�������캯��)

	Test t2(20);
	t2.GetX();

	t.Output();
	t.Output();
	cout<<t.GetOutputTimes()<<endl;
	return 0;
}