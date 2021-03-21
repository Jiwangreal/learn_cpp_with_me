#ifndef _JEVENT_H_
#define _JEVENT_H_

namespace JFC
{

class JWindow;

//JEvent用到了JWindow，前向声明下
class JEvent
{
public:
	JEvent(int code, JWindow* sender)
		: code_(code),
		  sender_(sender),
		  done_(false)
	{

	}

	JWindow* GetSender() const { return sender_; }
	int GetEventCode() const { return code_; }
	//Done表示这个事件处理完了，消息不再路由给其他窗口了
	void Done() { done_ = true; }
	bool IsDone() const { return done_ == true; }


private:
	int code_;
	//MFC的消息路由：消息会按照一定的目标流动，称之为消息路由，父子类可以流动，横向类也之间也可以流动
	//这里是如果该事件没有被当前窗口处理，会路由给其他窗口来处理
	JWindow* sender_;//事件发送给哪个窗口
	bool done_;//事件是否处理完
};

}

#endif // _JEVENT_H_