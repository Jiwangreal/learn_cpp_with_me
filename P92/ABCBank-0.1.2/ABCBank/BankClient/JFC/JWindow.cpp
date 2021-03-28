#include "JWindow.h"
#include "JEvent.h"

#include <algorithm>

using namespace JFC;

JWindow::JWindow()
	: parent_(0)
{
}

JWindow::JWindow(SHORT x, SHORT y, SHORT width, SHORT height,
				 JWindow* parent)
	: JWindowBase(x, y, width, height),
	  parent_(parent)
{
	//�������ڲ�Ϊ�գ�˵����ǰ�����Ĵ����Ǹ����ڵ��Ӵ���
	if (parent_)
	{
		parent_->AddChild(this);
	}
}

JWindow::~JWindow()
{
	//���и����ڣ�Ӧ�ôӸ����ڵ��Ӵ����б����Ƴ�
	if (parent_)
	{
		parent_->DelChild(this);
	}
}

void JWindow::OnKeyEvent(JEvent* e)
{

}

void JWindow::Draw()
{
	SetTextColor(FCOLOR_BLACK);
	SetBkColor(BCOLOR_WHITE);
	JRECT rect={ 0, 0, Width()-1, Height()-1 };
	FillRect(rect);
}

void JWindow::Show()
{
	SetCurrent();	// ���õ�ǰ����
	Draw();			// ���ڻ��ƣ���û�л��Ƶ���Ļ������ֻ���ڻ�����׼������
	Refresh();		// ���������е����ݻ��Ƶ���Ļ
}

void JWindow::AddChild(JWindow* win)
{
	childs_.push_back(win);
}

void JWindow::DelChild(JWindow* win)
{
	childs_.erase(std::remove(childs_.begin(), childs_.end(), win), childs_.end());
}

void JWindow::SetCurrent()
{
	if (IsCurrent())
		return;

	jApp->SetCurrent(this);
}