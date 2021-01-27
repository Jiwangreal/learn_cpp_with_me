#ifndef _SINGLETON_H
#define _SINGLETON_H

#include <cstdlib>
#include <iostream>
using namespace std;

//��Singleton��ģ�忴���ǵ���ģʽ��İ�װ�����������Բ�������ģʽ��
//GetInstance���صĲ���Singleton��������������װ�Ķ���T
template <typename T>
class Singleton
{
public:
	//����1��
	// static T& GetInstance()//���ص������ã����Բ�����ÿ������캯��
	// {
	// 	static T instance;		// �ֲ���̬�������������ڳ�ʼ��������״̬��
	// 	return instance;				//��2�ε���ʱ���᷵����ǰ����ʼ����ʵ�����Դ�����֤����
	// }

	//����2��
	//��̬��Ա�������ܵ��÷Ǿ�̬����
	static T& GetInstance()
	{
		// pthread_once(Init());//����̷߳���GetInstanceʱ��Initֻ�ǵ���һ�Σ���3��linux�����Ƽ�ʹ��pthread_once
		Init();
		return *instance_;
	}

	/*
	static T& GetInstance()���ֲ������̰߳�ȫ�ģ�ԭ�����£�
	��Ϊ2���߳̿���ͬʱ������GetInstance��2���߳�ͬʱ������if (instance_ == 0)�жϣ���new2�����󣬴�ʱ�����̰߳�ȫ�ġ�
	����취��
	��1����ͨ��,���Ƽ�
	��2��double check lock˫����������Ƽ�
	��3��linux�����Ƽ�ʹ��pthread_once
	*/


private:
	static void Init()
	{
		// lock();��1����ͨ��
		if (instance_ == 0)
		{
			// //�ټ��һ��
			// lock();��2��double check lock˫�����
			// if (instance_ == 0)
			// ulock();��2��double check lock˫�����
			instance_ =new T;
			//��Destroy����ע���ȥ���������ʱ�������ע��ĺ���������ע��������ע��ĺ����ȵ��ã�
			//����ע��һ��
			atexit(Destroy);//����ģʽ���������Ƽ�ʹ�õķ�ʽ������Ҫʹ������ָ��
		}
		// ulock();//��1����ͨ��
	}
	static void Destroy()
	{
		delete instance_;
	}

	Singleton(const Singleton& other);
	Singleton& operator=(const Singleton& other);
	Singleton();
	~Singleton();

	static T* instance_;
};

T* sSingleton<typename T>::instance_ = 0;//��ʼ��Ϊ��ָ��

#endif //_SINGLETON_H