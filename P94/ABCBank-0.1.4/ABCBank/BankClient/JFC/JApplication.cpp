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
	SetConsoleOutputCP(936);
	COORD size = { 80, 25 };
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), size);
	HideCursor();
	root_ = new JWindow(0, 0, 80, 25, 0);
	root_->Show();
}

JApplication::~JApplication()
{
	delete root_;
}

void JApplication::ShowCursor() const
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(hOut,&cci);
	cci.bVisible=true;
	SetConsoleCursorInfo(hOut,&cci);
}

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
		//=224说明是特殊的按键
		if (key == 224)		// 上、下、左、右、F11、F12、home、pg up、pg dn、end、delete、insert
		{
			key = (224 << 8) + _getch();//需要再次调用_getch()才能知道哪个key按键
		}
		else if (key == 0)	// F1~F10
		{
			key = -1 * _getch();
		}
		if (current_)
		{
			//接收事件是发送给当前窗口的
			//eg：按下13ENTER，当前对象是按钮对象，会调用按钮对象的OnKeyEvent
			//而按钮对象没有覆盖OnKeyEvent函数，则会调用基类JWindow的OnKeyEvent函数
			JEvent e(key, current_);
			current_->OnKeyEvent(&e);
		}
		
	}
	return 0;
}

