#ifndef _JFORM_H_
#define _JFORM_H_

#include "JWindow.h"

namespace JFC
{

//JForm������JButton
class JForm : public JWindow
{
public:
	JForm();
	JForm(SHORT x, SHORT y, SHORT width, SHORT height,
		JWindow* parent = jApp->Root());
	virtual ~JForm();

	virtual void Draw();//�������麯����������Ҳ���麯������������virtual�Ӳ�������ν
};

}

#endif // _JFORM_H_