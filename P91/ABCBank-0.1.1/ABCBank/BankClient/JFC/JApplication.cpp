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
	SetConsoleOutputCP(936);//支持简体中文
	COORD size = { 80, 25 };//设置控制台缓冲区的大小，80列25行，设置完毕后，就没有右边的滚动条了
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), size);
	HideCursor();//隐藏光标
	root_ = new JWindow(0, 0, 80, 25);//每个应用程序都有一个80列25行的窗口
	root_->Show();
}

JApplication::~JApplication()
{
	delete root_;
}

//显示光标
void JApplication::ShowCursor() const
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(hOut,&cci);//先获取一下光标信息
	cci.bVisible=true;
	SetConsoleCursorInfo(hOut,&cci);
}

//隐藏光标
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

