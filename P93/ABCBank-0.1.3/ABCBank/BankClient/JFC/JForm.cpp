#include "JForm.h"

using namespace JFC;

JForm::JForm()
	: JWindow(0, 0, 0, 0, 0)
{
}

JForm::JForm(SHORT x, SHORT y, SHORT width, SHORT height,
				 JWindow* parent)
	: JWindow(x, y, width, height, parent)
{

}

JForm::~JForm()
{
}

//�������ڵĻ��ƣ���������JForm����Ĵ��ڽ��棨������̳���JForm��������JForm������λ��ƣ�����Ҫ���Ƹ����Ӵ���
void JForm::Draw()
{
	// �����Ӵ����б�std::vector<JWindow*> childs_;���Ը����Ӵ��ڽ��л���
	std::vector<JWindow*>::const_iterator it;
	for (it=childs_.begin(); it!=childs_.end(); ++it)
	{
		(*it)->Draw();
	}
}