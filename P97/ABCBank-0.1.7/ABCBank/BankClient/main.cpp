#include "JFC/JApplication.h"
#include "JFC/JButton.h"

#include "UI/LoginForm.h"
#include "UI/MainMenuForm.h"

using namespace JFC;
using namespace UI;

int main()
{
	JApplication app;

	//JButton btn(11, 2, 10, 3, "test");
	//btn.Show();

	//JButton btn2(25, 2, 10, 3, "test2");
	//btn2.Show();

	//btn.Draw();		// �����ڻ��Ƶ��߼���Ļ
	//btn.Refresh();	// ���߼���Ļӳ�䵽������Ļ


	//LoginForm login(0, 0, 80, 25);
	//login.Show();

	//����MainMenuForm�Ƿ���ȷ
	MainMenuForm mmf(0, 0, 80, 25);
	mmf.Show();

	return app.Exec();	// ��Ϣѭ��
}