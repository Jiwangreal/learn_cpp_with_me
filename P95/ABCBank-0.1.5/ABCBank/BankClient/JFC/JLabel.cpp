#include "JLabel.h"

using namespace JFC;

JLabel::JLabel()
	: JWindow(0, 0, 0, 0, 0)
{

}

JLabel::JLabel(SHORT x, SHORT y, SHORT width, SHORT height,
			   const std::string& text,
			   JWindow* parent)
	: JWindow(x, y, width, height, parent),
	  text_(text)
{
}

JLabel::~JLabel()
{

}

//实现label控件是透明的：它的背景色和父窗口的背景色是一样的
void JLabel::Draw()
{
	SetTextColor(FCOLOR_BLUE);//label文本为蓝色
	if (parent_)//有父窗口的话
	{
		SetBkColor(parent_->GetBkColor());
	}
	else
		SetBkColor(BCOLOR_WHITE);

	JRECT rect = { 0, 0, Width()-1, Height()-1 };
	FillRect(rect);
	DrawText(0, 0, text_);
}