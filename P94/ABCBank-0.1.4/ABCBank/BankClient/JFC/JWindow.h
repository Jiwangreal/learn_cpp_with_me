#ifndef _JWINDOW_H_
#define _JWINDOW_H_

#include "JApplication.h"
#include "JWindowBase.h"

#include <vector>

namespace JFC
{

class JEvent;

class JWindow : public JWindowBase
{
public:
	JWindow();
	JWindow(SHORT x, SHORT y, SHORT width, SHORT height,
		JWindow* parent = jApp->Root());
	virtual ~JWindow();

	void AddChild(JWindow* win);
	void DelChild(JWindow* win);

	virtual void OnKeyEvent(JEvent* e);
	virtual void Draw();
	void Show();

	void SetCurrent();
	bool IsCurrent() { return this == jApp->GetCurrent(); }
	void SetCanFocus(bool canFocus) { canFocus_ = canFocus; }

	JWindow* FindFirst();//查找第一个能设置焦点的子窗口
	JWindow* FindLast();//查找最后一个能设置焦点的子窗口
	JWindow* FindPrev(JWindow* win);//查找win窗口前一个能设置焦点的子窗口
	JWindow* FindNext(JWindow* win);//查找win窗口下一个能设置焦点的子窗口


protected:
	JWindow* parent_;
	std::vector<JWindow*> childs_;
	bool canFocus_;//是否能够接受焦点
};

}

#endif // _JWINDOW_H_