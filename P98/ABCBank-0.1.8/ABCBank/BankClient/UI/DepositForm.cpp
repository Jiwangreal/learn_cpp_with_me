#include "DepositForm.h"

#include "FormManager.h"
#include "MainMenuForm.h"
#include "Validator.h"

#include "../JFC/JMessageBox.h"

using namespace UI;

DepositForm::DepositForm()
	: JForm(0, 0, 0, 0, 0)
{
}

DepositForm::~DepositForm()
{
}

DepositForm::DepositForm(SHORT x, SHORT y, SHORT w, SHORT h,
						 const std::string& title)
	: JForm(x, y, w, h),
	  title_(title)
{
	lblAccountId_ = new JLabel(14, 5, 11, 1, "ACCOUNT ID:", this);
	editAccountId_ = new JEdit(26, 5, 21, 1, "", this);
	lblAccountIdTip_ = new JLabel(50, 5, 11, 1, "长度6位，数字", this);

	lblMoney_ = new JLabel(19, 8, 12, 1, "MONEY:", this);
	editMoney_ = new JEdit(26, 8, 21, 1, "", this);
	lblMoneyTip_ = new JLabel(50, 8, 15, 1, "小数最多两位", this);


	btnSubmit_ = new JButton(5, 20, 10, 3, "SUBMIT", this);
	btnReset_ =	new JButton(50, 20, 10, 3,"RESET", this);
	btnCancel_ = new JButton(65, 20, 10, 3,"CANCEL", this);

	editAccountId_->SetValidator(ValidateAccountId);
	editMoney_->SetValidator(ValidateMoney);


}

void DepositForm::Draw()
{
	DrawBorder();
	SetTextColor(FCOLOR_BLUE);
	SetBkColor(BCOLOR_WHITE);
	JRECT rect = { 1, 1, Width()-2, Height()-2 };
	FillRect(rect);

	DrawText(5, 2, title_);
	DrawHLine(3, 2, Width()-3, '-');

	JForm::Draw();
}

void DepositForm::DrawBorder()
{
	SetTextColor(FCOLOR_YELLO);
	SetBkColor(BCOLOR_RED);
	DrawHLine(0, 0, Width()-1, '-');
	DrawHLine(Height()-1, 0, Width()-1, '-');
	DrawVLine(0, 1, Height()-2, ' ');
	DrawVLine(Width()-1, 1, Height()-2, ' ');
}

void DepositForm::OnKeyEvent(JEvent* e)
{
	int key = e->GetEventCode();
	if (key == KEY_ESC)
	{
		Reset();//清除edit控件里面的内容
		JForm* form;
		form = Singleton<FormManager>::Instance().Get("MainMenuForm");
		
		//将form动态转型为MainMenuForm*
		//目的是从主菜单的选项2返回时，返回到选项1
		dynamic_cast<MainMenuForm*>(form)->GetItems()[1]->SetCurrent();
		form->ClearWindow();
		form->Show();
		e->Done();
	}
	else if (key == KEY_ENTER)
	{
		if (e->GetSender() == btnCancel_)
		{
			Reset();
			JForm* form;
			form = Singleton<FormManager>::Instance().Get("MainMenuForm");
			dynamic_cast<MainMenuForm*>(form)->GetItems()[1]->SetCurrent();
			form->ClearWindow();
			form->Show();
			e->Done();
		}
		else if (e->GetSender() == btnReset_)
		{
			Reset();
			editAccountId_->SetCurrent();
			Show();
			e->Done();
		}
		else if (e->GetSender() == btnSubmit_)
		{
			Submit();
			e->Done();
		}
	}

	JForm::OnKeyEvent(e);
}

void DepositForm::Reset()
{
	editAccountId_->SetText("");
	editMoney_->SetText("");
}

void DepositForm::Submit()
{
	if (editAccountId_->GetText().length() < 6)
	{
		std::vector<std::string> v;
		v.push_back(" YES ");
		std::string msg = "帐号小于6位";

		JMessageBox::Show("-ERROR-", msg,v);
		ClearWindow();
		Show();
		editAccountId_->Show();
		return;
	}
	if (editMoney_->GetText().empty())
	{
		std::vector<std::string> v;
		v.push_back(" YES ");
		std::string msg = "金额不能为空";

		JMessageBox::Show("-ERROR-", msg, v);
		ClearWindow();
		Show();
		editAccountId_->Show();
		return;
	}

	// 以下为实际的存款操作
}