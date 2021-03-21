#ifndef _JEVENT_H_
#define _JEVENT_H_

namespace JFC
{

class JWindow;

//JEvent�õ���JWindow��ǰ��������
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
	//Done��ʾ����¼��������ˣ���Ϣ����·�ɸ�����������
	void Done() { done_ = true; }
	bool IsDone() const { return done_ == true; }


private:
	int code_;
	//MFC����Ϣ·�ɣ���Ϣ�ᰴ��һ����Ŀ����������֮Ϊ��Ϣ·�ɣ����������������������Ҳ֮��Ҳ��������
	//������������¼�û�б���ǰ���ڴ�����·�ɸ���������������
	JWindow* sender_;//�¼����͸��ĸ�����
	bool done_;//�¼��Ƿ�����
};

}

#endif // _JEVENT_H_