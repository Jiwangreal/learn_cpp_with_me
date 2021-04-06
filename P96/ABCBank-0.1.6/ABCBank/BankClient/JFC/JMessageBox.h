#ifndef _JMESSAGE_BOX_H_
#define _JMESSAGE_BOX_H_

#include "JWindow.h"

#include <string>
#include <vector>

namespace JFC
{

//只有一个静态成员函数
class JMessageBox
{
public:
	//（标题，消息文本，按钮的文本vector向量：可以指定多个按钮）
	//std::vector<std::string>& buttons返回值不同来确定是哪些按钮
	static int Show(const std::string& title,
		const std::string& text,
		std::vector<std::string>& buttons);
};

//JMessageBoxImpl是一个窗口类
class JMessageBoxImpl : public JWindow
{
public:
	JMessageBoxImpl(SHORT x, SHORT y, SHORT width, SHORT height,
		const std::string& title, const std::string& text,
		std::vector<std::string>& buttons, SHORT btn_distance,
		int lines, JWindow* parent = jApp->Root());

	~JMessageBoxImpl() {}

	virtual void Draw();

	int Exec();

	
private:
	std::string title_;
	std::string text_;

	short btnDistance_;
	int lines_;		// 文本显示行数
};

}

#endif // _JMESSAGE_BOX_H_
