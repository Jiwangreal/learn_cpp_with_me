#ifndef _JEDIT_H_
#define _JEDIT_H_

#include "JWindow.h"

#include <string>

namespace JFC
{

class JEvent;

//str表示文本
//ch表示新输入的字符
typedef bool (*VALIDATOR)(const std::string& str, char ch);

//默认校验器，表示任何数据都可以接受
//不同的框有不同的校验器，所以不同的框替换掉DefaultValidator就可以
static bool DefaultValidator(const std::string& str, char ch)
{
	return true;
}

class JEdit : public JWindow
{
public:
	enum EchoMode
	{
		EM_NORMAL,//普通模式
		EM_PASSWORD//密码模式
	};

	JEdit();

	JEdit(SHORT x, SHORT y, SHORT width, SHORT height, 
		const std::string& text = std::string(),
		JWindow* parent = jApp->Root(),
		EchoMode mode = JEdit::EM_NORMAL,
		VALIDATOR validator = DefaultValidator);

	virtual ~JEdit();

	virtual void Draw();
	virtual void OnKeyEvent(JEvent* e);

	const std::string& GetText() const
	{
		return text_;
	}

	//设置文本
	void SetText(const std::string& text)
	{
		text_ = text;
		currIndex_ = static_cast<int>(text_.length());//置于最后
	}

	void SetValidator(VALIDATOR validator)
	{
		//在文本处输入一堆字符，str就是能表示文本，ch就是能表示逐个输入的字符
		validator_ = validator;
	}
private:
	std::string text_;			// 文本
	int currIndex_;				// 当前位置，在USERNAME旁的文本控件处输入abc*，*表示光标位置，位置是3，
								//光标到别的控件去，回来USERNAME旁的文本控件处，光标位置还是在老地方
	EchoMode mode_;				// 显示模式
	VALIDATOR validator_;		// 校验器，比如：USERNAME旁的文本控件只能接收长度3-10位的字母或者数字
};

}
#endif // _JEDIT_H_