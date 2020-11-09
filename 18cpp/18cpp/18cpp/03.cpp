#include <iostream>
using namespace std;

class Singleton
{
public:
	static Singleton& GetInstance()//���ص������ã����Բ�����ÿ������캯��
	{
		static Singleton instance;		// �ֲ���̬�������������ڳ�ʼ��������״̬��
		return instance;				//��2�ε���ʱ���᷵����ǰ����ʼ����ʵ�����Դ�����֤����
	}
	//д��2
	// static Singleton* GetInstance()
	// {
	// 	static Singleton instance;	
	// 	return &instance;				
	// }

	~Singleton()
	{
		cout<<"~Singleton ..."<<endl;
	}

private:
	Singleton(const Singleton& other);
	Singleton& operator=(const Singleton& other);
	Singleton()
	{
		cout<<"Singleton ..."<<endl;
	}
};

int main(void)
{
	Singleton& s1 = Singleton::GetInstance();
	Singleton& s2 = Singleton::GetInstance();

	//д��2
	// Singleton* s1 = Singleton::GetInstance();
	// Singleton* s2 = Singleton::GetInstance();

	return 0;
}