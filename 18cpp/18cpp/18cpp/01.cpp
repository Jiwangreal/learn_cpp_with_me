#include <iostream>
using namespace std;

class Singleton
{
public:
	//GetInstance��Ա�������Է���Singleton˽�еĹ��캯��
	static Singleton* GetInstance()
	{
		if (instacne_ == NULL)
		{
			instacne_ = new Singleton;//new������һ�����ʵ��
		}
		return instacne_;
	}

	~Singleton()
	{
		cout<<"~Singleton ..."<<endl;
	}
private:

	//��ֹ�������ǽ��������캯�����Ⱥ����������Ϊ˽�еģ��Ϳ��Ա�֤�����п������죬Ҳ���ܸ�ֵ
	//��ֹ����1����ֹ���ÿ������캯��
	//���������캯������Ϊ˽�еģ��Ҳ��ṩ����ʵ��
	Singleton(const Singleton& other);

	//��ֹ����2��
	//����ֵ��������Ϊ˽�еģ���ֹ��ֵ����
	Singleton& operator=(const Singleton& other);

	//�����캯������Ϊ˽�еģ���main�����оͲ��ܵ��ù��캯��
	Singleton()
	{
		cout<<"Singleton ..."<<endl;
	}
	static Singleton* instacne_;//��������
};

Singleton* Singleton::instacne_;//�����Ե�˵��

int main(void)
{
	//Singleton s1;
	//Singleton s2;

	//���۵��ü���GetInstance�����Ƿ���ͬһ������ͬһ��ʵ��
	//�����֤������ͬһ��ʵ����ֻ��鿴s1��s2ָ����ָ��ĵ�ַ�Ƿ�һ��
	Singleton* s1 = Singleton::GetInstance();
	Singleton* s2 = Singleton::GetInstance();

	//Singleton s3(*s1);		// ���ÿ������캯��
	//s4=s2
	return 0;
}