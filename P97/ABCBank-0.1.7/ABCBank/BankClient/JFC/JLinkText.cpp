#include "JLinkText.h"

using namespace JFC;

JLinkText::JLinkText()
	: JWindow(0, 0, 0, 0, 0)
{
	SetCanFocus(true);//可以接收焦点
}

JLinkText::JLinkText(SHORT x, SHORT y, SHORT width, SHORT height,
					 const std::string& text,
					 JWindow* parent)
	: JWindow(x, y, width, height, parent),
	  text_(text)
{
	SetCanFocus(true);
}

JLinkText::~JLinkText()
{

}

//具有自己的绘制方式
void JLinkText::Draw()
{
	if (IsCurrent())
	{
		//COMMON_LVB_UNDERSCORE表示文本显示的时候具有下划线
		SetTextColor(FCOLOR_RED | COMMON_LVB_UNDERSCORE);
		jApp->HideCursor();
		DrawText(0, 0, "-> "+text_);//文本前面加上箭头
	}
	else
	{
		SetTextColor(FCOLOR_BLUE);
		//当有焦点转变为没有焦点时，其后面没有三个字符
		DrawText(0, 0, text_+"   ");
	}
}


