#ifndef _JLABEL_H_
#define _JLABEL_H_

#include "JWindow.h"

#include <string>

namespace JFC
{

//JLabel类不能停靠焦点的，就是光标不能停靠上文本标签上
//除了Draw()外，与JButton类是类似的
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
	std::string text_;//文本信息
};

}
#endif // _JLABEL_H_
