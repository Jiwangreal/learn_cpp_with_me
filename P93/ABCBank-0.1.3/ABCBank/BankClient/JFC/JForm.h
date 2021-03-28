#ifndef _JFORM_H_
#define _JFORM_H_

#include "JWindow.h"

namespace JFC
{

//JForm类似于JButton
class JForm : public JWindow
{
public:
	JForm();
	JForm(SHORT x, SHORT y, SHORT width, SHORT height,
		JWindow* parent = jApp->Root());
	virtual ~JForm();

	virtual void Draw();//基类是虚函数，派生类也是虚函数，所以这里virtual加不加无所谓
};

}

#endif // _JFORM_H_