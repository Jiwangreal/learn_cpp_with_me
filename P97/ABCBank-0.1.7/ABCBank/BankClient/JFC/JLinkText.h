#ifndef _JLINK_TEXT_H_
#define _JLINK_TEXT_H_

#include "JWindow.h"

#include <string>

namespace JFC
{
/*
JLinkTextû�и���OnKeyEvent�ӿڣ��ύ��JLinkText������JWindow������
parent_->OnKeyEvent(e);
��JWindow���ڶ���ĸ�������˭�أ�����MainMenuForm�����Ի����MainMenuForm��OnKeyEvent
*/

//JLinkTextҲ��һ������
class JLinkText : public JWindow
{
public:
	JLinkText();
	virtual ~JLinkText();
	JLinkText(SHORT x, SHORT y, SHORT width, SHORT height,
		const std::string& text = std::string(),
		JWindow* parent = jApp->Root());

	virtual void Draw();//ֻ��Ҫ����Draw��������

private:
	std::string text_;//�ı�
};

}

#endif // _JLINK_TEXT_H_