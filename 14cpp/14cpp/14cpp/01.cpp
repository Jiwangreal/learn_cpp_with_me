#include "Test.h"

int main(void)
{
	Test t(10);
	//Test t2(t);		// ��t�����ʼ��t2���󣬵��ÿ������캯��
	Test t2 = t;		// �ȼ���Test t2(t);�����=�����������������������������Ľ���

	return 0;
}