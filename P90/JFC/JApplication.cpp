#include "JApplication.h"

#include "JEvent.h"
#include "JWindow.h"

#include <conio.h>

//写法1
// namespace JFC
// {
// 	JApplication::JApplication() {}
// 	JApplication::~JApplication() {}
// }

//写法2
using namespace JFC;

//static定义
JApplication* JApplication::self_ = 0;//cpp中，NULL就是0

JApplication::JApplication()
{
	//单例模式
	if (self_)
		return;

	self_ = this;
	root_ = new JWindow;//新建一个窗口
	current_ = root_;//将当前窗口设置为当前窗口

}

JApplication::~JApplication()
{
	delete root_;
}


int JApplication::Exec()
{
	while (1)
	{
		//既可以接收键盘事件，也可以接收鼠标事件：ReadConsoleInput
		//消息循环用来接收键盘事件
		int key = _getch();
		if (current_)
		{
			//current_为 当前接收按键的窗口
			JEvent e(key, current_);//将按键抽象为JEvent事件，构造一个事件对象
			current_->OnKeyEvent(&e);//将这个事件e交给窗口来处理
		}
		
	}
	return 0;
}

