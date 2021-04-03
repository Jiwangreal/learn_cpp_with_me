#include "JLabel.h"

using namespace JFC;

JLabel::JLabel()
	: JWindow(0, 0, 0, 0, 0)
{

}

JLabel::JLabel(SHORT x, SHORT y, SHORT width, SHORT height,
			   const std::string& text,
			   JWindow* parent)
	: JWindow(x, y, width, height, parent),
	  text_(text)
{
}

JLabel::~JLabel()
{

}

//ʵ��label�ؼ���͸���ģ����ı���ɫ�͸����ڵı���ɫ��һ����
void JLabel::Draw()
{
	SetTextColor(FCOLOR_BLUE);//label�ı�Ϊ��ɫ
	if (parent_)//�и����ڵĻ�
	{
		SetBkColor(parent_->GetBkColor());
	}
	else
		SetBkColor(BCOLOR_WHITE);

	JRECT rect = { 0, 0, Width()-1, Height()-1 };
	FillRect(rect);
	DrawText(0, 0, text_);
}