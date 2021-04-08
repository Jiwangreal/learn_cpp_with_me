#ifndef _SINGLETON_H_
#define _SINGLETON_H_

//����ģ��
namespace PUBLIC
{

//���ģ�����൱��һ����װ��
template <typename T>
class Singleton
{
public:
	static T& Instance()
	{
		//ʵ���Ϸ��ص���T
		static T instance;
		return instance;
	}
private:
	Singleton();
	~Singleton();
};

}

#endif	// _SINGLETON_H_
