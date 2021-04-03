#include "JEdit.h"
#include "JEvent.h"

using namespace JFC;

JEdit::JEdit()
	: currIndex_(0),
	  mode_(EM_NORMAL),
	  validator_(DefaultValidator)
{
	SetCanFocus(true);//�༭���ǿ��Խ��ܽ����
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

//�������¼�����ʱ
void JEdit::OnKeyEvent(JEvent* e)
{
	int key = e->GetEventCode();
	switch (key)
	{
	//�Ҽ�����������ƶ�
	case KEY_RIGHT:
		
		if (currIndex_  < static_cast<int>(text_.length()))
		{
			++currIndex_;
			DrawText(0, 0, text_);
			Show();
			e->Done();
		}
		//�������ƶ��������ı���ĳ����ˣ���breakѭ�������¼���ύ���丸����Form������
		//�õ�KEY_RIGHT�¼�����������Ľ����ƶ�����һ�����Խ��ܽ�����Ӵ���֮��
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
	case KEY_DEL://ɾ��������ڵ��ַ�
		text_.erase(text_.begin()+currIndex_);
		//ɾ��һ���ַ���������ı����ٻ����ı�
		ClearWindow();
		DrawText(0, 0, text_);
		Show();
		e->Done();

		break;
	case KEY_BACK:
		//KEY_BACK�¼���������ˣ�Ҳ���Ὣ����ƶ������ĸ�����
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
		//˵�����ǽ���From����������
		break;

	default://�ж��Ƿ��ǿɽ��ܵ��ַ�
		//key > 0 && key < 256 &&
		//	isprint(key) &&�ж��Ƿ��ǿɴ�ӡ�ַ�
		//������ı�����static_cast<int>(text_.length()) < Width()-1
		//����У��ģʽ��validator_(text_, (char)e->GetEventCode())
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


	//����¼�û�д�����ϣ��ͽ���������������
	if (!e->IsDone())
	{
		if (parent_ != NULL)
			parent_->OnKeyEvent(e);
	}
}
void JEdit::Draw()
{
	//��ǰ���ڵı���ɫ�Ǻ�
	//�ǵ�ǰ���ڵı���ɫ����ɫ��
	if (IsCurrent())
	{
		SetTextColor(FCOLOR_WHITE);
		SetBkColor(BCOLOR_RED);
		jApp->ShowCursor();//��ʾ���
		SetCursorPos(x_ + currIndex_, y_);//���ù���λ��
	}
	else
	{
		SetTextColor(FCOLOR_WHITE);
		SetBkColor(BCOLOR_BLUE);
	}

	//����ǰ�������ı�
	JRECT rect = { 0, 0, Width()-1, Height()-1 };
	FillRect(rect);

	//��ͨģʽֱ����ʾ�ı�
	if (mode_ == JEdit::EM_NORMAL)
		DrawText(0, 0, text_);
	else
	{
		//����һ����text_һ�����ȵ��ַ���*�����滻
		std::string s(text_.length(), '*');
		DrawText(0, 0, s);
	}
}


