#ifndef _JWINDOW_H_
#define _JWINDOW_H_

namespace JFC
{

//JWindow�õ���JEvent������ǰ��������
class JEvent;

class JWindow
{
public:
	JWindow();
	~JWindow();

	virtual void OnKeyEvent(JEvent* e);
};

}

#endif // _JWINDOW_H_