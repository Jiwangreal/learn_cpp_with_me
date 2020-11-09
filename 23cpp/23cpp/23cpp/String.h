#ifndef _STRING_H_
#define _STRING_H_

class String
{
public:
	explicit String(const char* str="");

	//�������캯��ʵ�����
	//���캯�������з���ֵ���������캯��Ҳ�ǹ��캯��
	String(const String& other);

	String& operator=(const String& other);
	String& operator=(const char* str);

	//!��һԪ��������=���Ƕ�Ԫ���������أ���Ϊs3=s1����������s3��s1
	bool operator!() const;//const����ı������ݳ�Ա
	~String(void);

	void Display() const;

private:
	char* AllocAndCpy(const char* str);
	char* str_;//�����������һ��Ҫ�ṩ�������캯����ʵ�����
};

#endif // _STRING_H_
