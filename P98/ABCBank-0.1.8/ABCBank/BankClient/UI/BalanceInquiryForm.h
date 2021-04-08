#ifndef _BALANCE_INQUIRY_FORM_H_
#define _BALANCE_INQUIRY_FORM_H_

#include "../JFC/JForm.h"
#include "../JFC/JLabel.h"
#include "../JFC/JEdit.h"
#include "../JFC/JButton.h"

#include <string>

using namespace JFC;

namespace UI
{

class BalanceInquiryForm : public JForm
{
public:
	BalanceInquiryForm();
	~BalanceInquiryForm();
	BalanceInquiryForm(SHORT x, SHORT y, SHORT w, SHORT h,
		const std::string& title);

	virtual void Draw();
	virtual void OnKeyEvent(JEvent* e);

private:
/*
解决DrawBorder函数代码冗余的方法：
不将DrawBorder放到JForm类的原因是，因为他是JFC框架中的form基类，
他并没有假定一个form的boarder是如何绘制的，在这个项目里面所有的基类是这么绘制boarder的

class BankForm : public JForm
{
public:
	void DrawBorder();
};

class ChangePasswordForm ： public BankForm
{

};

继承BankForm中的DrawBorder代码。这样DrawBorder不用在多个派生类中写多份了
*/

	void DrawBorder();

	void Reset();
	void Submit();

	std::string title_;

	JLabel* lblAccountId_;
	JEdit* editAccountId_;
	JLabel* lblAccountIdTip_;

	JLabel* lblPass_;
	JEdit* editPass_;
	JLabel* lblPassTip_;

	JButton* btnSubmit_;
	JButton* btnReset_;
	JButton* btnCancel_;
};

}
#endif // _BALANCE_INQUIRY_FORM_H_
