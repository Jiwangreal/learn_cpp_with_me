#ifndef _JLINK_TEXT_H_
#define _JLINK_TEXT_H_

#include "JWindow.h"

#include <string>

namespace JFC
{
/*
JLinkText没有覆盖OnKeyEvent接口，会交给JLinkText父窗口JWindow来处理
parent_->OnKeyEvent(e);
而JWindow窗口对象的父窗口是谁呢？就是MainMenuForm，所以会调用MainMenuForm的OnKeyEvent
*/

//JLinkText也是一个窗口
class JLinkText : public JWindow
{
public:
	JLinkText();
	virtual ~JLinkText();
	JLinkText(SHORT x, SHORT y, SHORT width, SHORT height,
		const std::string& text = std::string(),
		JWindow* parent = jApp->Root());

	virtual void Draw();//只需要覆盖Draw函数即可

private:
	std::string text_;//文本
};

}

#endif // _JLINK_TEXT_H_