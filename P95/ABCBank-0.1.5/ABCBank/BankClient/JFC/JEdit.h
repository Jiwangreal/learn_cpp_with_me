#ifndef _JEDIT_H_
#define _JEDIT_H_

#include "JWindow.h"

#include <string>

namespace JFC
{

class JEvent;

//str��ʾ�ı�
//ch��ʾ��������ַ�
typedef bool (*VALIDATOR)(const std::string& str, char ch);

//Ĭ��У��������ʾ�κ����ݶ����Խ���
//��ͬ�Ŀ��в�ͬ��У���������Բ�ͬ�Ŀ��滻��DefaultValidator�Ϳ���
static bool DefaultValidator(const std::string& str, char ch)
{
	return true;
}

class JEdit : public JWindow
{
public:
	enum EchoMode
	{
		EM_NORMAL,//��ͨģʽ
		EM_PASSWORD//����ģʽ
	};

	JEdit();

	JEdit(SHORT x, SHORT y, SHORT width, SHORT height, 
		const std::string& text = std::string(),
		JWindow* parent = jApp->Root(),
		EchoMode mode = JEdit::EM_NORMAL,
		VALIDATOR validator = DefaultValidator);

	virtual ~JEdit();

	virtual void Draw();
	virtual void OnKeyEvent(JEvent* e);

	const std::string& GetText() const
	{
		return text_;
	}

	//�����ı�
	void SetText(const std::string& text)
	{
		text_ = text;
		currIndex_ = static_cast<int>(text_.length());//�������
	}

	void SetValidator(VALIDATOR validator)
	{
		//���ı�������һ���ַ���str�����ܱ�ʾ�ı���ch�����ܱ�ʾ���������ַ�
		validator_ = validator;
	}
private:
	std::string text_;			// �ı�
	int currIndex_;				// ��ǰλ�ã���USERNAME�Ե��ı��ؼ�������abc*��*��ʾ���λ�ã�λ����3��
								//��굽��Ŀؼ�ȥ������USERNAME�Ե��ı��ؼ��������λ�û������ϵط�
	EchoMode mode_;				// ��ʾģʽ
	VALIDATOR validator_;		// У���������磺USERNAME�Ե��ı��ؼ�ֻ�ܽ��ճ���3-10λ����ĸ��������
};

}
#endif // _JEDIT_H_