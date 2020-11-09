#include <iostream>
using namespace std;

class Singleton
{
public:
	static Singleton* GetInstance()
	{
		if (instacne_ == NULL)
		{
			instacne_ = new Singleton;
		}
		return instacne_;
	}

	~Singleton()
	{
		cout<<"~Singleton ..."<<endl;
	}
	
	//�ͷŷ���1
	//static void Free()
	//{
	//	if (instacne_ != NULL)
	//	{
	//		delete instacne_;
	//	}
	//}

	//�ͷŷ���2
	//Garbo���ܣ���������
	//Ƕ����
	class Garbo
	{
	public:
		~Garbo()
		{
			if (Singleton::instacne_ != NULL)
			{
				delete instacne_;
			}
		}
	};
private:
	Singleton(const Singleton& other);
	Singleton& operator=(const Singleton& other);
	Singleton()
	{
		cout<<"Singleton ..."<<endl;
	}
	static Singleton* instacne_;

	//�ͷŷ���2
	//garbo_�������������ڽ�����ʱ�򣬻��Զ����������������ﵽ���ٵ���ģʽ�����Ŀ��
	//���õ���ȷ����������ԭ��
	static Garbo garbo_;	// ���ö����ȷ��������
};

//�ͷŷ���2
Singleton::Garbo Singleton::garbo_;//Singleton::Garbo �����ͣ�Singleton��ʾgarbo_��Singleton��һ����Ա
Singleton* Singleton::instacne_;

int main(void)
{
	//Singleton s1;
	//Singleton s2;

	Singleton* s1 = Singleton::GetInstance();
	Singleton* s2 = Singleton::GetInstance();

	//Singleton s3(*s1);		// ���ÿ������캯��

	//�ͷŷ���1
	// Singleton::free();

	return 0;
}