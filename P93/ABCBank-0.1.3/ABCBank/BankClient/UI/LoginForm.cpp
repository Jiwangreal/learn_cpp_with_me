#include "LoginForm.h"

using namespace UI;

LoginForm::LoginForm(SHORT x, SHORT y, SHORT width, SHORT height,
					 JWindow* parent)
	: JForm(x, y, width, height, parent)
{
	//2����ť
	btnLogin_ = new JButton(22, 17, 11, 3, "LOGIN", this);//��������this

	btnExit_ = new JButton(48, 17, 10, 3, "EXIT", this);
}

LoginForm::~LoginForm()
{
	delete btnLogin_;
	delete btnExit_;
}

void LoginForm::Draw()
{
	//���Ʊ߿�
	DrawBorder();

	SetTextColor(FCOLOR_BLUE);
	SetBkColor(BCOLOR_WHITE);

	//x=28��y=3
	DrawText(28, 3, "Login To The Bank System");
	DrawHLine(4, 25, 54, '-');

	DrawText(2, 23, "Bank System, Author: www.cppcourse.com");

	//LoginForm�����ڻ��ƴ��ڵ�ʱ�򣬳��˻���������������Ӵ��ڣ�2����ť
	JForm::Draw();//ֱ�ӵ��û����Draw()�������Ӵ���
}

void LoginForm::DrawBorder()
{
	SetTextColor(FCOLOR_YELLO);
	SetBkColor(BCOLOR_RED);

	DrawHLine(0, 0, Width()-1, '-');//��һ��---------
	DrawHLine(Height()-1, 0, Width()-1, '-');//���һ��------

	//��һ��
	DrawVLine(0, 1, Height()-2, ' ');//x=0��λ�ã�y��1��λ�õ��߶�-2��λ��
	//���һ��
	DrawVLine(Width()-1, 1, Height()-2, ' ');


}