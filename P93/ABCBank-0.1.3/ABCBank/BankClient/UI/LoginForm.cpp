#include "LoginForm.h"

using namespace UI;

LoginForm::LoginForm(SHORT x, SHORT y, SHORT width, SHORT height,
					 JWindow* parent)
	: JForm(x, y, width, height, parent)
{
	//2个按钮
	btnLogin_ = new JButton(22, 17, 11, 3, "LOGIN", this);//父窗口是this

	btnExit_ = new JButton(48, 17, 10, 3, "EXIT", this);
}

LoginForm::~LoginForm()
{
	delete btnLogin_;
	delete btnExit_;
}

void LoginForm::Draw()
{
	//绘制边框
	DrawBorder();

	SetTextColor(FCOLOR_BLUE);
	SetBkColor(BCOLOR_WHITE);

	//x=28，y=3
	DrawText(28, 3, "Login To The Bank System");
	DrawHLine(4, 25, 54, '-');

	DrawText(2, 23, "Bank System, Author: www.cppcourse.com");

	//LoginForm对象在绘制窗口的时候，除了绘制自身，还会绘制子窗口：2个按钮
	JForm::Draw();//直接调用基类的Draw()来增加子窗口
}

void LoginForm::DrawBorder()
{
	SetTextColor(FCOLOR_YELLO);
	SetBkColor(BCOLOR_RED);

	DrawHLine(0, 0, Width()-1, '-');//第一行---------
	DrawHLine(Height()-1, 0, Width()-1, '-');//最后一行------

	//第一列
	DrawVLine(0, 1, Height()-2, ' ');//x=0的位置，y从1的位置到高度-2的位置
	//最后一列
	DrawVLine(Width()-1, 1, Height()-2, ' ');


}