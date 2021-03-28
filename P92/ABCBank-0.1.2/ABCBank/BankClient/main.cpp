#include "JFC/JApplication.h"
#include "JFC/JButton.h"

using namespace JFC;

int main()
{
	JApplication app;

	//(11,2)，宽度10，高度3，父窗口默认是root窗口
	JButton btn(11, 2, 10, 3, "test");
	btn.Show();

	JButton btn2(25, 2, 10, 3, "test2");
	btn2.Show();

	btn.Draw();		// 将窗口绘制到窗口所对应的逻辑屏幕buffer_，将btn所占用的缓冲区绘制到buffer_
	btn.Refresh();	// 从逻辑屏幕buffer_映射到物理屏幕，将数据刷新到屏幕上来
	return app.Exec();	// 消息循环
}