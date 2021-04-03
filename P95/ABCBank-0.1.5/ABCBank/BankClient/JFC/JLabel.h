#ifndef _JLABEL_H_
#define _JLABEL_H_

#include "JWindow.h"

#include <string>

namespace JFC
{

//JLabel�಻��ͣ������ģ����ǹ�겻��ͣ�����ı���ǩ��
//����Draw()�⣬��JButton�������Ƶ�
class JLabel : public JWindow
{
public:
	JLabel();

	JLabel(SHORT x, SHORT y, SHORT width, SHORT height,
		const std::string& text = std::string(),
		JWindow* parent = jApp->Root());

	virtual ~JLabel();

	virtual void Draw();

	void SetText(const std::string& text)
	{
		text_ = text;
	}

private:
	std::string text_;//�ı���Ϣ
};

}
#endif // _JLABEL_H_
