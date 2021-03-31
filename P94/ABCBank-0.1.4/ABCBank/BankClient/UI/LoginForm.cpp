#include "LoginForm.h"

using namespace UI;

LoginForm::LoginForm(SHORT x, SHORT y, SHORT width, SHORT height,
					 JWindow* parent)
	: JForm(x, y, width, height, parent)
{
	//������˵��JButton�ĸ�����LoginForm��
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

	DrawHLine(0, 0, Width()-1, '-');//��һ�л���
	DrawHLine(Height()-1, 0, Width()-1, '-');//���һ�л���

	DrawVLine(0, 1, Height()-2, ' ');//��1������
	DrawVLine(Width()-1, 1, Height()-2, ' ');//���1������


}

void LoginForm::OnKeyEvent(JEvent* e)
{
	JWindow* win = e->GetSender();
	int key = e->GetEventCode();

	//win == btnLogin_˵���ǵ�¼��ť���յ����¼�
	/*
	LOGIN��ť���»س���������JButton��û�и���OnKeyEvent��������JWindow��OnKeyEvent��
	��JWindow��OnKeyEvent�ǽ����¼��ַ��������ڶ���LOGIN���ڵĸ����ڶ�����LoginForm����
	���������LoginForm��OnKeyEvent����
	*/
	if (win == btnLogin_ && key == KEY_ENTER)//�����¼��ť�س���
	{
		// �¼�����
		e->Done();		// ˵���¼�������ϣ����ٽ�һ���ַ�
	}

	if (win == btnExit_ && key == KEY_ENTER)//�����Ƴ���ť�س���
	{
		// �¼�����
		e->Done();		// ˵���¼�������ϣ����ٽ�һ���ַ�
	}
	JForm::OnKeyEvent(e);//һ����¼������û����OnKeyEvent����������
}