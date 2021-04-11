#include "JFC/JApplication.h"
#include "JFC/JButton.h"

#include "UI/LoginForm.h"
#include "UI/MainMenuForm.h"

#include "UI/FormManager.h"

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

	//MainMenuForm mmf(0, 0, 80, 25);
	//mmf.Show();

	//�Ƚ����¼����
	//Singleton<FormManager>::Instance()���ص���FormManager����
	//��ȡ��¼���ڽ���
	JForm* form = Singleton<FormManager>::Instance().Get("LoginForm");
	form->Show();

	return app.Exec();	// ��Ϣѭ��
}