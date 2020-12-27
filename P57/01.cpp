#include <iostream>
#include <memory>
using namespace std;

//����ģʽ�Ǳ�֤һ������һ��������ֻ��һ������һ��ʵ��
//ʵ�ֵ���ģʽ�Ĺؼ����ǣ������ֹ������ֻ�轫�������캯����Ⱥ����������Ϊ˽�еģ��Ҳ��ṩ����ʵ�֣������Ļ�������ᱨ�������⽫
//���캯������Ϊ˽�еģ���ֹ�ⲿ���⹹�����������Ҫ�ṩһ���ӿ�ingleton::GetInstance();���ⲿ�õ�����һ������
//��Ϊ�޷�ͨ��������ó�Ա����������ֻ��ͨ������ó�Ա���������Խ�GetInstance����Ϊstatic�����⣬���۵��ö��ٴ�GetInstance�����ص���ͬһ������
//����һ��������ж������Ŀ���
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
	//����취��ʹ������ָ�룬������ָ���������ڽ�����ʱ�򣬻��Զ����������������Ӷ��ͷ�ָ�������У�ָ�򣩵���Դ
	//��������ָ�������ڵ���ģʽ�У�����Դ�����ͷ�
	static Singleton* instacne_;//����������������ָ�룬������ָ�����
	// static shared_ptr<Singleton> instacne_;
	//�������������ʱ����̬����Ҳ�ᱻ���٣��ͻ�������shared_ptr������������������ͻὫ����е�ָ����Դ�����ͷ�
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