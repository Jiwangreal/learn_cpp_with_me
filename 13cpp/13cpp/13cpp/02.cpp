#include <iostream>
using namespace std;

class Object
{
public:
	//�����Ա�ĳ�ʼ����Ӧ���ڳ�ʼ���б����ṩ
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
	//�ܽ�
	//�����ݳ�Ա�ĳ�ʼ�����Ƽ����ڳ�ʼ���б��У�������ͨ���ݳ�Ա�Ͷ������ݳ�Ա
	//���obj1_��������Ӧ��Object��û��Ĭ�Ϲ��캯������ô���ĳ�ʼ��һ��Ҫ����Container��ĳ�ʼ���б���
	//����У������ʡ��obj1_������Container��ĳ�ʼ���б��еĳ�ʼ��

	Container(int obj1=0, int obj2=0) : obj2_(obj2), obj1_(obj1)
	{
		cout<<"Container ..."<<endl;
	}
	~Container()
	{
		cout<<"~Container ..."<<endl;
	}

private:
	//Ҫ����һ��Container��������Ҫ����Object�������ڳ�ʼ���б���û��ָ����ι���Object����
	//������Object�����Ĭ�Ϲ��캯������Object����û��Ĭ�Ϲ��캯������ô����ᱨ��û�к��ʵ�Ĭ�Ϲ��캯��

	//ʵ����Container���һ������ʱ���䱾����һ���ڴ棬obj1_�ڴ���ǰ��obj2_�ڴ��ں�����obj1_�����ȹ���
	//�����˳���붨���˳���йأ�������Container(int obj1=0, int obj2=0) : obj2_(obj2), obj1_(obj1)��ʼ��
	//�б��˳���޹�
	Object obj1_;//�����Ӷ���Ҳ�ж����Ա
	Object obj2_;
};

int main(void)
{
	Container c(10,20);//ʵ����Container����
	return 0;
}