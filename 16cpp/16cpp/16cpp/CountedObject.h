#ifndef _COUNTED_OBJECT_H_
#define _COUNTED_OBJECT_H_

class CountedObject
{
public:
	CountedObject();
	~CountedObject();
public:
	static int GetCount();
private:
	//�����۾�̬���ǷǾ�̬�ģ���Ա�����ĳ�ʼ������������������ʱ�������
	//eg��static int count_ = 100�����Ǵ��
	static int count_;		// ��̬��Ա������������������Ҫ��̬��Ա�Ķ���������
};


#endif // _COUNTED_OBJECT_H_