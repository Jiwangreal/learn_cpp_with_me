#ifndef _STRING_H_
#define _STRING_H_

class String
{
public:
	String(char* str="");//Ĭ�ϲ����ǿմ�
	~String();
	String(const String& other);
	String& operator=(const String& other);

	

	void Display();

private:
	char* AllocAndCpy(char* str);
	
	char* str_;//���ڲ��漰����̬�ڴ���䣬��ʹ����������˹����ڴ�

	//��ֹ���������������Ƕ�һ�޶��Ķ��󣬶�һ�޶��Ķ������������������Լ�ʵ�ֶ�ע�͵������Իᵼ�±������
	// String(const String& other);
	// String& operator=(const String& other);
};

#endif // _STRING_H_
