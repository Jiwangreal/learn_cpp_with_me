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
		JWindow* parent = jApp->Root());//父窗口默认是根窗口，每个应用程序都有一个root窗口
	virtual ~JWindow();

	void AddChild(JWindow* win);
	void DelChild(JWindow* win);

	virtual void OnKeyEvent(JEvent* e);
	virtual void Draw();
	void Show();

	void SetCurrent();//将JWindow对象设置为当前窗口，当前窗口由JApplication中的JWindow* current_;来维护
	
	//是否是当前窗口
	//this代表JWindow对象
	//若相等，说明是该JWindow窗口是整个应用程序的当前窗口
	bool IsCurrent() { return this == jApp->GetCurrent(); }

protected:
	JWindow* parent_;//每一个窗口除了root窗口都有一个父窗口
	std::vector<JWindow*> childs_;//子窗口列表，一个窗口可以有多个子窗口
};

}

#endif // _JWINDOW_H_