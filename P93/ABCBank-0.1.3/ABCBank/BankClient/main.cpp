#include "JFC/JApplication.h"
#include "JFC/JButton.h"

#include "UI/LoginForm.h"

using namespace JFC;
using namespace UI;

int main()
{
	JApplication app;

	//JButton btn(11, 2, 10, 3, "test");
	//btn.Show();

	//JButton btn2(25, 2, 10, 3, "test2");
	//btn2.Show();

	//btn.Draw();		// 将窗口绘制到逻辑屏幕
	//btn.Refresh();	// 从逻辑屏幕映射到物理屏幕


	LoginForm login(0, 0, 80, 25);//父窗口是根窗口，最后一个参数可以缺省
	login.Show();

	return app.Exec();	// 消息循环
}