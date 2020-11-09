#ifndef _INTEGER_H_
#define _INTEGER_H_

class Integer
{
public:
	Integer(int n);
	~Integer();

	//��Ԫ���������ض��ȳ�Ա���������ض�һ����������Ϊ��Ա����������һ������Ĳ�������
	//++������Ƽ�ʹ�ó�Ա�����ķ�ʽ���أ���Ϊ��Ԫ�����������൱�ڶ���һЩȫ�ֵĺ������ں��б�Ҫ������£���ȥ��

	//ǰ����������أ���VC6.0�У��������ܹ��棬������Ҫע�͵�һ��
	Integer& operator++();
	//friend Integer& operator++(Integer& i);

	//������������أ�int n��������Ϊ������ǰ�ã��������ܹ�������
	Integer operator++(int n);
	//friend Integer operator++(Integer& i, int n);

	void Display() const;
private:
	int n_;
};

#endif // _INTEGER_H_