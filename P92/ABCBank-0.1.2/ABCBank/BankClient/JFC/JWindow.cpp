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
	//若父窗口不为空，说明当前创建的窗口是父窗口的子窗口
	if (parent_)
	{
		parent_->AddChild(this);
	}
}

JWindow::~JWindow()
{
	//若有父窗口，应该从父窗口的子窗口列表中移除
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
	SetCurrent();	// 设置当前窗口
	Draw();			// 窗口绘制，并没有绘制到屏幕，仅仅只是在缓冲区准备数据
	Refresh();		// 将缓冲区中的数据绘制到屏幕
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