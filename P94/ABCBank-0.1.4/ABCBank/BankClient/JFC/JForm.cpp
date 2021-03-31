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

void JForm::Draw()
{
	// �����Ӵ����б��Ը����Ӵ��ڽ��л���
	std::vector<JWindow*>::const_iterator it;
	for (it=childs_.begin(); it!=childs_.end(); ++it)
	{
		(*it)->Draw();
	}
}

void JForm::OnKeyEvent(JEvent* e)
{
	if (e->IsDone())
		return;

	//�ж��¼��Ƿ��͸�˭��
	//eg��Form���û���κ�һ���Ӵ��ڵĻ�������Form����
	//��Form���Ӵ��ڵĻ�������Form������н�����Ӵ���
	if (e->GetSender() == this)//���͸�����
		return;

	int key = e->GetEventCode();
	JWindow* win;

	switch (key)
	{
	//������һ�����н���Ĵ���
	case KEY_UP:
	case KEY_LEFT:
		e->Done();
		win = FindPrev(e->GetSender());
		if (win == NULL)
			return;

		win->Show();

		(e->GetSender())->Draw();
		(e->GetSender())->Refresh();
		break;

	//���ҵ�����һ������
	case KEY_ENTER:
	case KEY_DOWN:
	case KEY_RIGHT:
	case KEY_TAB:
		e->Done();//˵������¼����ٽ��зַ���
		win = FindNext(e->GetSender());//������һ���Ӵ���
		if (win == NULL)
			return;

		win->Show();

		(e->GetSender())->Draw();
		(e->GetSender())->Refresh();
		break;

	default:
		break;

	}

	//JWindow* win = FindNext()
}