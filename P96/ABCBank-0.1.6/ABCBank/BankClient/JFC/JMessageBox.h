#ifndef _JMESSAGE_BOX_H_
#define _JMESSAGE_BOX_H_

#include "JWindow.h"

#include <string>
#include <vector>

namespace JFC
{

//ֻ��һ����̬��Ա����
class JMessageBox
{
public:
	//�����⣬��Ϣ�ı�����ť���ı�vector����������ָ�������ť��
	//std::vector<std::string>& buttons����ֵ��ͬ��ȷ������Щ��ť
	static int Show(const std::string& title,
		const std::string& text,
		std::vector<std::string>& buttons);
};

//JMessageBoxImpl��һ��������
class JMessageBoxImpl : public JWindow
{
public:
	JMessageBoxImpl(SHORT x, SHORT y, SHORT width, SHORT height,
		const std::string& title, const std::string& text,
		std::vector<std::string>& buttons, SHORT btn_distance,
		int lines, JWindow* parent = jApp->Root());

	~JMessageBoxImpl() {}

	virtual void Draw();

	int Exec();

	
private:
	std::string title_;
	std::string text_;

	short btnDistance_;
	int lines_;		// �ı���ʾ����
};

}

#endif // _JMESSAGE_BOX_H_
