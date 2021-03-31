#include "JWindow.h"
#include "JEvent.h"

#include <algorithm>

using namespace JFC;

JWindow::JWindow()
	: parent_(0),
	  canFocus_(false)
{
}

JWindow::JWindow(SHORT x, SHORT y, SHORT width, SHORT height,
				 JWindow* parent)
	: JWindowBase(x, y, width, height),
	  parent_(parent),
	  canFocus_(false)
{

	if (parent_)
	{
		parent_->AddChild(this);
	}
}

JWindow::~JWindow()
{
	if (parent_)
	{
		parent_->DelChild(this);
	}
}

/*
按键就是消息，Login按钮接收到按键。
由于JButton类没有覆盖OnKeyEvent函数，因而会调用基类JWindow::OnKeyEvent函数处理这个事件

JWindow::OnKeyEvent含义
如果事件没有被处理完，就将事件分发给父窗口对象来处理

JButton的父类是LoginForm类，因而会调用LoginForm::OnKeyEvent,进而调用JForm::OnKeyEvent
若LoginForm类没有覆盖OnKeyEvent，则会直接调用JForm::OnKeyEvent
*/
void JWindow::OnKeyEvent(JEvent* e)
{
	if (!e->IsDone())//如果事件没有被处理
	{
		//JButton的父窗口对象是LoginForm，会调用LoginForm::OnKeyEvent
		if (parent_)
		{
			parent_->OnKeyEvent(e);
		}
	}
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
	//如果是当前窗口
	if (IsCurrent())
		return;

	if (canFocus_)
		jApp->SetCurrent(this);
	else
	{
		std::vector<JWindow*>::const_iterator it;
		// 遍历子窗口列表，查找是否有子窗口是当前窗口，如果有则break跳出循环
		for (it=childs_.begin(); it!=childs_.end(); ++it)
		{
			if ((*it)->IsCurrent())
				break;
		}

		//如果没找到
		if (it == childs_.end())
		{
			// 查找第一个能够设置焦点的子窗口
			JWindow* win = FindFirst();
			if (win)
				jApp->SetCurrent(win);	// 将第一个能够设置焦点的子窗口设置为当前窗口
			else
			{
				jApp->SetCurrent(this);//当前窗口只能是Form自身
			}

		}
	}
}

JWindow* JWindow::FindFirst()
{
	JWindow* p = NULL;
	std::vector<JWindow*>::const_iterator it;
	for (it=childs_.begin(); it!=childs_.end(); ++it)
	{
		if ((*it)->canFocus_)
		{
			p = *it;
			break;
		}
	}

	return p;
}

JWindow* JWindow::FindLast()
{
	JWindow* p = NULL;

	//反向迭代器
	std::vector<JWindow*>::const_reverse_iterator ri;
	//rbegin最后一个
	for (ri = childs_.rbegin(); ri != childs_.rend(); ++ri)
	{
		if ((*ri)->canFocus_)
		{
			p = *ri;
			break;
		}
	}
	return p;
}

//向前查找
JWindow* JWindow::FindPrev(JWindow* win)
{

	JWindow* p = 0;

	std::vector<JWindow*>::const_reverse_iterator ri;
	//先找到win窗口所在的迭代器位置
	ri = std::find(childs_.rbegin(), childs_.rend(), win);
	if (ri == childs_.rend())//没找到
		return NULL;

	if (*ri == FindFirst())//说明win所在的位置是第1个
		p = FindLast();//第1个的前1个就是最后1个
	else
	{
		++ri;//反向迭代器++
		for ( ; ri != childs_.rbegin(); ++ri)
		{
			if ((*ri)->canFocus_)//找到第一个就break
			{
				p = *ri;
				break;
			}
		}
	}

	return p;

}

JWindow* JWindow::FindNext(JWindow* win)
{
	JWindow* p = 0;

	std::vector<JWindow*>::const_iterator it;
	it = std::find(childs_.begin(), childs_.end(), win);
	if (it == childs_.end())
		return NULL;

	if (*it == FindLast())
		p = FindFirst();
	else
	{
		++it;
		for ( ; it != childs_.end(); ++it)
		{
			if ((*it)->canFocus_)
			{
				p = *it;
				break;
			}
		}


	}

	return p;
}