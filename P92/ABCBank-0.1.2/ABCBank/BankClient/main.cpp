#include "JFC/JApplication.h"
#include "JFC/JButton.h"

using namespace JFC;

int main()
{
	JApplication app;

	//(11,2)�����10���߶�3��������Ĭ����root����
	JButton btn(11, 2, 10, 3, "test");
	btn.Show();

	JButton btn2(25, 2, 10, 3, "test2");
	btn2.Show();

	btn.Draw();		// �����ڻ��Ƶ���������Ӧ���߼���Ļbuffer_����btn��ռ�õĻ��������Ƶ�buffer_
	btn.Refresh();	// ���߼���Ļbuffer_ӳ�䵽������Ļ��������ˢ�µ���Ļ����
	return app.Exec();	// ��Ϣѭ��
}