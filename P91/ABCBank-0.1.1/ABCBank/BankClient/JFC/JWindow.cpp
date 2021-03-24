#include "JWindow.h"
#include "JEvent.h"

using namespace JFC;

JWindow::JWindow()
{
}

//调用基类JWindowBase的构造函数初始化
JWindow::JWindow(SHORT x, SHORT y, SHORT width, SHORT height)
	: JWindowBase(x, y, width, height)
{

}
JWindow::~JWindow()
{
}

void JWindow::OnKeyEvent(JEvent* e)
{

}

//最普通的白底黑字
void JWindow::Draw()
{
	SetTextColor(FCOLOR_BLACK);
	SetBkColor(BCOLOR_WHITE);
	JRECT rect={ 0, 0, Width()-1, Height()-1 };
	FillRect(rect);//绘制矩形，只是放到了buffer_屏幕缓冲区这里
}

void JWindow::Show()
{
	jApp->SetCurrent(this);
	Draw();//不同窗口有不同的绘制方式，这是一个虚函数
	Refresh();//刷新到屏幕
}