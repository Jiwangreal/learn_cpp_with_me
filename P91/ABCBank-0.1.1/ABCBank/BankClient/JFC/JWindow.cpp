#include "JWindow.h"
#include "JEvent.h"

using namespace JFC;

JWindow::JWindow()
{
}

//���û���JWindowBase�Ĺ��캯����ʼ��
JWindow::JWindow(SHORT x, SHORT y, SHORT width, SHORT height)
	: JWindowBase(x, y, width, height)
{

}
JWindow::~JWindow()
{
}

void JWindow::OnKeyEvent(JEvent* e)
{

}

//����ͨ�İ׵׺���
void JWindow::Draw()
{
	SetTextColor(FCOLOR_BLACK);
	SetBkColor(BCOLOR_WHITE);
	JRECT rect={ 0, 0, Width()-1, Height()-1 };
	FillRect(rect);//���ƾ��Σ�ֻ�Ƿŵ���buffer_��Ļ����������
}

void JWindow::Show()
{
	jApp->SetCurrent(this);
	Draw();//��ͬ�����в�ͬ�Ļ��Ʒ�ʽ������һ���麯��
	Refresh();//ˢ�µ���Ļ
}