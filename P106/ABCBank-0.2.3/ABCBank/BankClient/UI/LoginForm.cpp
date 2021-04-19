#include "LoginForm.h"

#include "FormManager.h"
#include "Validator.h"

#include "../BankSession.h"
#include "../TransactionManager.h"

#include "../JFC/JMessageBox.h"

#include "../../Public/Socket.h"
#include "../../Public/Exception.h"


using namespace UI;
using namespace PUBLIC;

LoginForm::LoginForm(SHORT x, SHORT y, SHORT width, SHORT height,
					 JWindow* parent)
	: JForm(x, y, width, height, parent)
{
	lblUser_ = new JLabel(16, 8, 9, 1, "USERNAME:", this);
	editUser_ = new JEdit(26, 8, 21, 1, "", this);
	lblUserTip_ = new JLabel(50, 8, 22, 1, "长度3-10位，字母或数字", this);

	lblPass_ = new JLabel(16, 12, 9, 1, "PASSWORD:", this);
	editPass_ = new JEdit(26, 12, 21, 1, "", this, JEdit::EM_PASSWORD);
	lblPassTip_ = new JLabel(50, 12, 9, 1, "长度6-8位", this);

	btnLogin_ = new JButton(22, 17, 11, 3, "LOGIN", this);
	btnExit_ = new JButton(48, 17, 10, 3, "EXIT", this);

	editUser_->SetValidator(ValidateName);
	editPass_->SetValidator(ValidatePass);
}

LoginForm::~LoginForm()
{
	delete lblUser_;
	delete editUser_;
	delete lblUserTip_;

	delete lblPass_;
	delete editPass_;
	delete lblPassTip_;


	delete btnLogin_;
	delete btnExit_;
}

void LoginForm::Draw()
{
	DrawBorder();

	SetTextColor(FCOLOR_BLUE);
	SetBkColor(BCOLOR_WHITE);

	DrawText(28, 3, "Login To The Bank System");
	DrawHLine(4, 25, 54, '-');

	DrawText(2, 23, "Bank System, Author: www.cppcourse.com");

	JForm::Draw();
}

void LoginForm::DrawBorder()
{
	SetTextColor(FCOLOR_YELLO);
	SetBkColor(BCOLOR_RED);

	DrawHLine(0, 0, Width()-1, '-');
	DrawHLine(Height()-1, 0, Width()-1, '-');

	DrawVLine(0, 1, Height()-2, ' ');
	DrawVLine(Width()-1, 1, Height()-2, ' ');


}

void LoginForm::OnKeyEvent(JEvent* e)
{
	JWindow* win = e->GetSender();
	int key = e->GetEventCode();

	if (win == btnLogin_ && key == KEY_ENTER)
	{
		// 事件处理
		e->Done();		// 说明事件处理完毕，不再进一步分发
		Login();
	}

	if (win == btnExit_ && key == KEY_ENTER)
	{
		// 事件处理
		e->Done();		// 说明事件处理完毕，不再进一步分发
		Exit();
	}
	JForm::OnKeyEvent(e);
}

void LoginForm::Login()
{
	if (editUser_->GetText().length() < 3)
	{
		std::vector<std::string> v;
		v.push_back(" YES ");
		std::string msg = "用户名小于3位";

		int result = JMessageBox::Show("-ERROR-", msg,v);

		JWindow* win = jApp->GetCurrent();
		editUser_->Show();
		win->Draw();
		win->Refresh();
		return;
	}
	if (editPass_->GetText().length() < 6)
	{
		std::vector<std::string> v;
		v.push_back(" YES ");
		std::string msg = "密码小于6位";

		JMessageBox::Show("-ERROR-", msg, v);

		JWindow* win = jApp->GetCurrent();
		editPass_->Show();
		win->Draw();
		win->Refresh();
		return;
	}

	// TODO:以下为实际的登录操作
/*
	Socket sock;
	sock.Create();
	sock.Connect("127.0.0.1", 8888);
	std::string str;
	str.append(editUser_->GetText());
	str.append("#");
	str.append(editPass_->GetText());
	sock.Send(str.c_str(), str.length());

	char buffer[1024] = {0};
	sock.Recv(buffer, sizeof(buffer));

	std::vector<std::string> v;
	v.push_back(" YES ");

	JMessageBox::Show("-MESSAGE-", buffer, v);



	Reset();
	JForm* form = Singleton<FormManager>::Instance().Get("MainMenuForm");
	form->ClearWindow();
	form->Show();
	*/

	try
	{
		//收集到数据
		BankSession bs;
		bs.SetCmd(CMD_LOGIN);
		
		//内部协议name，pass
		bs.SetAttribute("name", editUser_->GetText());
		bs.SetAttribute("pass", editPass_->GetText());

		//将数据交给TransactionManager命令管理器DoAction来处理命令
		//DoAction依据cmd会找到对应的UserLogin类对象来处理，调用其Execute函数来处理
		Singleton<TransactionManager>::Instance().DoAction(bs);
		//返回后，BankSession的状态已经改变了，应答的状态已经保存到BankSession中了

		//接下来，判断应答状态
		if (bs.GetErrorCode() == 0)
		{
			std::vector<std::string> v;
			v.push_back(" YES ");
			JMessageBox::Show("-MESSAGE-", "登录成功", v);

			//登录成功，界面转到MainMenuForm
			Reset();
			JForm* form = Singleton<FormManager>::Instance().Get("MainMenuForm");
			form->ClearWindow();
			form->Show();
		}
		else
		{
			//若登录是被，则界面还是处于当前的LoginForm界面
			std::vector<std::string> v;
			v.push_back(" YES ");
			JMessageBox::Show("-ERROR-", bs.GetErrorMsg(), v);

			ClearWindow();
			Show();
		}
	}
	catch (Exception& e)
	{
		//消息框打印异常
		std::vector<std::string> v;
		v.push_back(" YES ");
		JMessageBox::Show("-ERROR-", e.what(), v);

		ClearWindow();
		Show();
	}

}

void LoginForm::Exit()
{
	std::vector<std::string> v;
	v.push_back(" YES ");
	v.push_back(" NO ");
	v.push_back(" 1 ");
	v.push_back(" 2 ");
	v.push_back(" 3 ");
	v.push_back(" 4 ");
	v.push_back(" 5 ");
	std::string msg = "Do you want to exit?????????????????????????????????????????????????????????????????????????????";

	int result = JMessageBox::Show("-MESSAGE-", msg,v);
	if (result == 0)
	{
		system("cls");
		exit(0);
	}

	ClearWindow();
	Show();
}

void LoginForm::Reset()
{
	editUser_->SetText("");
	editPass_->SetText("");

}