#include "JLinkText.h"

using namespace JFC;

JLinkText::JLinkText()
	: JWindow(0, 0, 0, 0, 0)
{
	SetCanFocus(true);//���Խ��ս���
}

JLinkText::JLinkText(SHORT x, SHORT y, SHORT width, SHORT height,
					 const std::string& text,
					 JWindow* parent)
	: JWindow(x, y, width, height, parent),
	  text_(text)
{
	SetCanFocus(true);
}

JLinkText::~JLinkText()
{

}

//�����Լ��Ļ��Ʒ�ʽ
void JLinkText::Draw()
{
	if (IsCurrent())
	{
		//COMMON_LVB_UNDERSCORE��ʾ�ı���ʾ��ʱ������»���
		SetTextColor(FCOLOR_RED | COMMON_LVB_UNDERSCORE);
		jApp->HideCursor();
		DrawText(0, 0, "-> "+text_);//�ı�ǰ����ϼ�ͷ
	}
	else
	{
		SetTextColor(FCOLOR_BLUE);
		//���н���ת��Ϊû�н���ʱ�������û�������ַ�
		DrawText(0, 0, text_+"   ");
	}
}


