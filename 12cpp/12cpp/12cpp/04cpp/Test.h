#ifndef _TEST_H_
#define _TEST_H_

class Test
{
public:
	// ����಻�ṩ�κ�һ�����캯����ϵͳ��Ϊ�����ṩһ������������
	// Ĭ�ϵĹ��캯��
	Test();
	explicit Test(int num);//��ʾֻ����ʽ������󣬲�����ʽ�������
	void Display();

	//��operator=����һ������������һ��������
	Test& operator=(const Test& other);

	~Test();
private:
	int num_;
};
#endif // _TEST_H_