#include <iostream>
using namespace std;

class Test
{
public:
	Test()
	{

	}
	~Test()
	{

	}
	
	//����static const��Ա�������ඨ�����г�ʼ�����ó�Ա���Բ�����������ж���
	static const int x_ = 100;		// static const���ͳ�Ա���ʼ�����������н��У����﷨��vc6���ǲ������
};

const int Test::x_;					// ��̬��Ա�Ķ�����˵��

int main(void)
{
	cout<<Test::x_<<endl;
}