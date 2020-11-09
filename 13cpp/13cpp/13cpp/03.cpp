#include <iostream>
using namespace std;

// const��Ա�ĳ�ʼ��ֻ���ڹ��캯����ʼ���б��н���
// ���ó�Ա�ĳ�ʼ��Ҳֻ���ڹ��캯����ʼ���б��н���
// �����Ա����������Ӧ����û��Ĭ�Ϲ��캯�����ĳ�ʼ����Ҳֻ���ڹ��캯����ʼ���б��н���
class Object
{
public:
	enum E_TYPE
	{
		//TYPE_A��TYPE_B�����ж������������ǳ���
		TYPE_A = 100,
		TYPE_B = 200
	};
public:
	Object(int num=0) : num_(num), kNum_(num), refNum_(num_)
	{
		//kNum_ = 100;//��������ֻ�Ǹ�ֵ�����ǳ�ʼ��
		//refNum_ = num_;//��������ֻ�Ǹ�ֵ�����ǳ�ʼ��
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
	//����һ���ڴ�����ˣ���Ҫ���г�ʼ��������ֻ�ܷ��ڳ�ʼ���б��н���
	const int kNum_;// const��Ա�ĳ�ʼ��ֻ���ڹ��캯����ʼ���б��н���
	int& refNum_;// ���ó�Ա�ĳ�ʼ��Ҳֻ���ڹ��캯����ʼ���б��н���
};

int main(void)
{
	Object obj1(10);//kNum_ֻ�ڶ����ڲ��ǳ�������ͬ�Ķ����в�ͬ��ֵ�����������ж����ǳ�����������ö����ʵ��
	Object obj2(20);
	obj1.DisplayKNum();
	obj2.DisplayKNum();

	//TYPE_A���κζ�����˵���ǳ���
	cout<<obj1.TYPE_A<<endl;
	cout<<obj2.TYPE_A<<endl;
	cout<<Object::TYPE_A<<endl;


	return 0;
}