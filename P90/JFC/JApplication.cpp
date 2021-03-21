#include "JApplication.h"

#include "JEvent.h"
#include "JWindow.h"

#include <conio.h>

//д��1
// namespace JFC
// {
// 	JApplication::JApplication() {}
// 	JApplication::~JApplication() {}
// }

//д��2
using namespace JFC;

//static����
JApplication* JApplication::self_ = 0;//cpp�У�NULL����0

JApplication::JApplication()
{
	//����ģʽ
	if (self_)
		return;

	self_ = this;
	root_ = new JWindow;//�½�һ������
	current_ = root_;//����ǰ��������Ϊ��ǰ����

}

JApplication::~JApplication()
{
	delete root_;
}


int JApplication::Exec()
{
	while (1)
	{
		//�ȿ��Խ��ռ����¼���Ҳ���Խ�������¼���ReadConsoleInput
		//��Ϣѭ���������ռ����¼�
		int key = _getch();
		if (current_)
		{
			//current_Ϊ ��ǰ���հ����Ĵ���
			JEvent e(key, current_);//����������ΪJEvent�¼�������һ���¼�����
			current_->OnKeyEvent(&e);//������¼�e��������������
		}
		
	}
	return 0;
}

