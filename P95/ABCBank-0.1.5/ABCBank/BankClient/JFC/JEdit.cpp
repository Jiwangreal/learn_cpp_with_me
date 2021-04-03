#include "JEdit.h"
#include "JEvent.h"

using namespace JFC;

JEdit::JEdit()
	: currIndex_(0),
	  mode_(EM_NORMAL),
	  validator_(DefaultValidator)
{
	SetCanFocus(true);//编辑框是可以接受焦点的
}

JEdit::JEdit(SHORT x, SHORT y, SHORT width, SHORT height,
			 const std::string& text,
			 JWindow* parent,
			 EchoMode mode,
			 VALIDATOR validator)
	: JWindow(x, y, width, height, parent),
	  text_(text),
	  currIndex_(0),
	  mode_(mode),
	  validator_(validator)
{
	SetCanFocus(true);
}

JEdit::~JEdit()
{

}

//当按键事件到来时
void JEdit::OnKeyEvent(JEvent* e)
{
	int key = e->GetEventCode();
	switch (key)
	{
	//右键，光标向右移动
	case KEY_RIGHT:
		
		if (currIndex_  < static_cast<int>(text_.length()))
		{
			++currIndex_;
			DrawText(0, 0, text_);
			Show();
			e->Done();
		}
		//如果光标移动到等于文本框的长度了，则break循环，该事件则会交给其父窗口Form来处理
		//得到KEY_RIGHT事件，他会把它的焦点移动到下一个可以接受焦点的子窗口之上
		break;
	case KEY_LEFT:
		if (currIndex_ > 0)
		{
			--currIndex_;
			DrawText(0, 0, text_);
			Show();
			e->Done();
		}
		break;
	case KEY_DEL://删除光标所在的字符
		text_.erase(text_.begin()+currIndex_);
		//删除一个字符，先清除文本，再绘制文本
		ClearWindow();
		DrawText(0, 0, text_);
		Show();
		e->Done();

		break;
	case KEY_BACK:
		//KEY_BACK事件处理完毕了，也不会将光标移动到他的父窗口
		if (currIndex_ > 0)
		{
			text_.erase(text_.begin()+currIndex_-1);
			--currIndex_;
		}

		ClearWindow();
		DrawText(0, 0, text_);
		Show();
		e->Done();

		break;

	case KEY_ENTER:
	case KEY_DOWN:
	case KEY_TAB:
	case KEY_UP:
		//说明都是交给From窗口来处理
		break;

	default://判断是否是可接受的字符
		//key > 0 && key < 256 &&
		//	isprint(key) &&判断是否是可打印字符
		//插入的文本长度static_cast<int>(text_.length()) < Width()-1
		//符合校验模式：validator_(text_, (char)e->GetEventCode())
		if (key > 0 && key < 256 &&
			isprint(key) &&
			static_cast<int>(text_.length()) < Width()-1 &&
			validator_(text_, (char)e->GetEventCode()))
		{
			text_.insert(text_.begin()+currIndex_, 1, (char)e->GetEventCode());
			++currIndex_;
			DrawText(0, 0, text_);
			Show();
			e->Done();
		}
		break;
	}


	//如果事件没有处理完毕，就交给父窗口来处理
	if (!e->IsDone())
	{
		if (parent_ != NULL)
			parent_->OnKeyEvent(e);
	}
}
void JEdit::Draw()
{
	//当前窗口的背景色是红
	//非当前窗口的背景色是蓝色的
	if (IsCurrent())
	{
		SetTextColor(FCOLOR_WHITE);
		SetBkColor(BCOLOR_RED);
		jApp->ShowCursor();//显示光标
		SetCursorPos(x_ + currIndex_, y_);//设置光标的位置
	}
	else
	{
		SetTextColor(FCOLOR_WHITE);
		SetBkColor(BCOLOR_BLUE);
	}

	//绘制前景，即文本
	JRECT rect = { 0, 0, Width()-1, Height()-1 };
	FillRect(rect);

	//普通模式直接显示文本
	if (mode_ == JEdit::EM_NORMAL)
		DrawText(0, 0, text_);
	else
	{
		//构造一个与text_一样长度的字符串*用来替换
		std::string s(text_.length(), '*');
		DrawText(0, 0, s);
	}
}


