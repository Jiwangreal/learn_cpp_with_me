#ifndef _JWINDOW_H_
#define _JWINDOW_H_

#include "JApplication.h"
#include "JWindowBase.h"

#include <vector>

namespace JFC
{

class JEvent;

class JWindow : public JWindowBase
{
public:
	JWindow();
	JWindow(SHORT x, SHORT y, SHORT width, SHORT height,
		JWindow* parent = jApp->Root());//������Ĭ���Ǹ����ڣ�ÿ��Ӧ�ó�����һ��root����
	virtual ~JWindow();

	void AddChild(JWindow* win);
	void DelChild(JWindow* win);

	virtual void OnKeyEvent(JEvent* e);
	virtual void Draw();
	void Show();

	void SetCurrent();//��JWindow��������Ϊ��ǰ���ڣ���ǰ������JApplication�е�JWindow* current_;��ά��
	
	//�Ƿ��ǵ�ǰ����
	//this����JWindow����
	//����ȣ�˵���Ǹ�JWindow����������Ӧ�ó���ĵ�ǰ����
	bool IsCurrent() { return this == jApp->GetCurrent(); }

protected:
	JWindow* parent_;//ÿһ�����ڳ���root���ڶ���һ��������
	std::vector<JWindow*> childs_;//�Ӵ����б�һ�����ڿ����ж���Ӵ���
};

}

#endif // _JWINDOW_H_