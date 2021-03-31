#include "LoginForm.h"

using namespace UI;

LoginForm::LoginForm(SHORT x, SHORT y, SHORT width, SHORT height,
					 JWindow* parent)
	: JForm(x, y, width, height, parent)
{
	//这里来说明JButton的父类是LoginForm类
	btnLogin_ = new JButton(22, 17, 11, 3, "LOGIN", this);
	btnExit_ = new JButton(48, 17, 10, 3, "EXIT", this);
}

LoginForm::~LoginForm()
{
	delete btnLogin_;
	delete btnExit_;
}

void LoginForm::Draw()
{
	DrawBorder();

	SetTextColor(FCOLOR_BLUE);
	SetBkColor(BCOLOR_WHITE);

	DrawText(28, 3, "Login To The Bank System");
	DrawHLine(4, 25, 54, '-');

	DrawText(2, 23, "Bank System, Author: www.cppcourse.com");

	JForm::Draw();
}

void LoginForm::DrawBorder()
{
	SetTextColor(FCOLOR_YELLO);
	SetBkColor(BCOLOR_RED);

	DrawHLine(0, 0, Width()-1, '-');//第一行划线
	DrawHLine(Height()-1, 0, Width()-1, '-');//最后一行划线

	DrawVLine(0, 1, Height()-2, ' ');//第1列竖线
	DrawVLine(Width()-1, 1, Height()-2, ' ');//最后1列竖线


}

void LoginForm::OnKeyEvent(JEvent* e)
{
	JWindow* win = e->GetSender();
	int key = e->GetEventCode();

	//win == btnLogin_说明是登录按钮接收到的事件
	/*
	LOGIN按钮按下回车键，由于JButton类没有覆盖OnKeyEvent，则会调用JWindow的OnKeyEvent，
	而JWindow的OnKeyEvent是将该事件分发给父窗口对象，LOGIN窗口的父窗口对象是LoginForm对象
	因而调用了LoginForm的OnKeyEvent函数
	*/
	if (win == btnLogin_ && key == KEY_ENTER)//处理登录按钮回车键
	{
		// 事件处理
		e->Done();		// 说明事件处理完毕，不再进一步分发
	}

	if (win == btnExit_ && key == KEY_ENTER)//处理推出按钮回车键
	{
		// 事件处理
		e->Done();		// 说明事件处理完毕，不再进一步分发
	}
	JForm::OnKeyEvent(e);//一般的事件，调用基类的OnKeyEvent。让他处理
}