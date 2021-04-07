#ifndef _MAIN_MENU_FORM_H_
#define _MAIN_MENU_FORM_H_

#include "../JFC/JForm.h"
#include "../JFC/JLinkText.h"
#include "../JFC/JEvent.h"

#include <vector>

using namespace JFC;

namespace UI
{

class MainMenuForm : public JForm
{
public:
	MainMenuForm();
	~MainMenuForm();
	MainMenuForm(SHORT x, SHORT y, SHORT w, SHORT h);

	virtual void Draw();
	virtual void OnKeyEvent(JEvent* e);

	//9个操作对应9个成员函数
	void OpenAccount();
	void Deposit();
	void Withdraw();
	void Transfer();
	void BalanceInquiry();
	void ChangePassword();
	void DetailStatement();
	void CloseAccount();
	void Quit();

	std::vector<JLinkText*>& GetItems() { return items_; }


private:
	void DrawBorder();

	std::vector<JLinkText*> items_;//具有9个JLinkText列表

};

}
#endif // _MAIN_MENU_FORM_H_