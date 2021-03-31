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
	// 遍历子窗口列表，对各个子窗口进行绘制
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

	//判断事件是发送给谁的
	//eg：Form如果没有任何一个子窗口的话，就是Form自身，
	//若Form有子窗口的话，就是Form里面具有焦点的子窗口
	if (e->GetSender() == this)//发送给自身
		return;

	int key = e->GetEventCode();
	JWindow* win;

	switch (key)
	{
	//查找上一个具有焦点的窗口
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

	//查找的是下一个窗口
	case KEY_ENTER:
	case KEY_DOWN:
	case KEY_RIGHT:
	case KEY_TAB:
		e->Done();//说明这个事件不再进行分发了
		win = FindNext(e->GetSender());//查找下一个子窗口
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