#ifndef _JWINDOW_H_
#define _JWINDOW_H_

namespace JFC
{

//JWindow用到了JEvent，这里前向声明下
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