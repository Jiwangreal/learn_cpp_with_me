#include "JButton.h"

using namespace JFC;

JButton::JButton()
	: JWindow(0, 0, 0, 0, 0)
{
}

JButton::JButton(SHORT x, SHORT y, SHORT width, SHORT height,
				 const std::string& text,
				 JWindow* parent)
	: JWindow(x, y, width, height, parent),
	  text_(text)
{

}

JButton::~JButton()
{
}

void JButton::Draw()
{
	//????
	if (IsCurrent())
	{
		SetTextColor(FCOLOR_WHITE);
		SetBkColor(BCOLOR_RED);
	}//?????
	else
	{
		SetTextColor(FCOLOR_BLUE);
		SetBkColor(BCOLOR_GRAY);
	}

	//??????????????
	JRECT rect = { 0, 0, Width()-1, Height()-1 };
	FillRect(rect);		//??????
	DrawText(text_);

}
