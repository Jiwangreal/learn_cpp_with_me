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
����������Ϣ��Login��ť���յ�������
����JButton��û�и���OnKeyEvent�������������û���JWindow::OnKeyEvent������������¼�

JWindow::OnKeyEvent����
����¼�û�б������꣬�ͽ��¼��ַ��������ڶ���������

JButton�ĸ�����LoginForm�࣬��������LoginForm::OnKeyEvent,��������JForm::OnKeyEvent
��LoginForm��û�и���OnKeyEvent�����ֱ�ӵ���JForm::OnKeyEvent
*/
void JWindow::OnKeyEvent(JEvent* e)
{
	if (!e->IsDone())//����¼�û�б�����
	{
		//JButton�ĸ����ڶ�����LoginForm�������LoginForm::OnKeyEvent
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
	//����ǵ�ǰ����
	if (IsCurrent())
		return;

	if (canFocus_)
		jApp->SetCurrent(this);
	else
	{
		std::vector<JWindow*>::const_iterator it;
		// �����Ӵ����б������Ƿ����Ӵ����ǵ�ǰ���ڣ��������break����ѭ��
		for (it=childs_.begin(); it!=childs_.end(); ++it)
		{
			if ((*it)->IsCurrent())
				break;
		}

		//���û�ҵ�
		if (it == childs_.end())
		{
			// ���ҵ�һ���ܹ����ý�����Ӵ���
			JWindow* win = FindFirst();
			if (win)
				jApp->SetCurrent(win);	// ����һ���ܹ����ý�����Ӵ�������Ϊ��ǰ����
			else
			{
				jApp->SetCurrent(this);//��ǰ����ֻ����Form����
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

	//���������
	std::vector<JWindow*>::const_reverse_iterator ri;
	//rbegin���һ��
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

//��ǰ����
JWindow* JWindow::FindPrev(JWindow* win)
{

	JWindow* p = 0;

	std::vector<JWindow*>::const_reverse_iterator ri;
	//���ҵ�win�������ڵĵ�����λ��
	ri = std::find(childs_.rbegin(), childs_.rend(), win);
	if (ri == childs_.rend())//û�ҵ�
		return NULL;

	if (*ri == FindFirst())//˵��win���ڵ�λ���ǵ�1��
		p = FindLast();//��1����ǰ1���������1��
	else
	{
		++ri;//���������++
		for ( ; ri != childs_.rbegin(); ++ri)
		{
			if ((*ri)->canFocus_)//�ҵ���һ����break
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