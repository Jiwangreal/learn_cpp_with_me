#include "JApplication.h"

#include "JEvent.h"
#include "JWindow.h"

#include <conio.h>

using namespace JFC;

JApplication* JApplication::self_ = 0;

JApplication::JApplication()
{
	if (self_)
		return;

	self_ = this;
	SetConsoleOutputCP(936);//֧�ּ�������
	COORD size = { 80, 25 };//���ÿ���̨�������Ĵ�С��80��25�У�������Ϻ󣬾�û���ұߵĹ�������
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), size);
	HideCursor();//���ع��
	root_ = new JWindow(0, 0, 80, 25);//ÿ��Ӧ�ó�����һ��80��25�еĴ���
	root_->Show();
}

JApplication::~JApplication()
{
	delete root_;
}

//��ʾ���
void JApplication::ShowCursor() const
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(hOut,&cci);//�Ȼ�ȡһ�¹����Ϣ
	cci.bVisible=true;
	SetConsoleCursorInfo(hOut,&cci);
}

//���ع��
void JApplication::HideCursor() const
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(hOut,&cci);
	cci.bVisible=false;
	SetConsoleCursorInfo(hOut,&cci);
}

int JApplication::Exec()
{
	while (1)
	{
		int key = _getch();
		if (current_)
		{
			JEvent e(key, current_);
			current_->OnKeyEvent(&e);
		}
		
	}
	return 0;
}

