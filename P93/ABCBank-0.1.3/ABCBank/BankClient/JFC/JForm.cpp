#include "JForm.h"

using namespace JFC;

JForm::JForm()
	: JWindow(0, 0, 0, 0, 0)
{
}

JForm::JForm(SHORT x, SHORT y, SHORT width, SHORT height,
				 JWindow* parent)
	: JWindow(x, y, width, height, parent)
{

}

JForm::~JForm()
{
}

//容器窗口的绘制：不仅绘制JForm对象的窗口界面（派生类继承至JForm，他决定JForm对象如何绘制），还要绘制各个子窗口
void JForm::Draw()
{
	// 遍历子窗口列表std::vector<JWindow*> childs_;，对各个子窗口进行绘制
	std::vector<JWindow*>::const_iterator it;
	for (it=childs_.begin(); it!=childs_.end(); ++it)
	{
		(*it)->Draw();
	}
}