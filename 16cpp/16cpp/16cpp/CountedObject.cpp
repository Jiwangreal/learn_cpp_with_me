#include "CountedObject.h"

//static���ݳ�Ա��������Ķ��󣬱����ж���������
int CountedObject::count_ = 0;		// ��̬��Ա�Ķ�����������static��Ա��������������������У���static���Բ���Ҫ��

CountedObject::CountedObject()
{
	//count_����������������Χ֮�ڣ�����û��Ҫд��++CountedObject::count_;
	++count_;
}

CountedObject::~CountedObject()
{
	--count_;
}

int CountedObject::GetCount()
{
	return count_;
}
