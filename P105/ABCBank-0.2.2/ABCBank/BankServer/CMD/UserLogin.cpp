#include "UserLogin.h"

#include "../../Public/Logging.h"
#include "../../Public/JUtil.h"
#include "../../Public/JInStream.h"
#include "../../Public/JOutStream.h"

using namespace PUBLIC;
using namespace CMD;

void UserLogin::Execute(BankSession& session)
{
	//JInStream����������ο����������ͷ��ʽ
	//session.GetRequestPack()->buf�ǰ��岿�֣����ǵ�5���ֽڵ�λ�ã�Ҳ����buffer_�±�Ϊ4��λ��
	JInStream jis(session.GetRequestPack()->buf, session.GetRequestPack()->head.len);//ֻ�а���
	uint16 cmd = session.GetCmd();
	string name;//�û���
	string pass;//����
	jis>>name>>pass;//��������

	int16 error_code = 0;
	char error_msg[31] = {0};
	if (name != "admin" || pass != "123456")
	{
		error_code = 1;//����������ֲ᣺2.2.2.1.6	��������������Ϣ���ձ�
		strcpy_s(error_msg, "�û������������");//strcpy_s���̰߳�ȫ��
		LOG_INFO<<error_msg;
	}

	//���ͻ���һ��Ӧ��������գ�Ӧ�����ͷ��ʽ
	JOutStream jos;
	jos<<cmd;
	size_t lengthPos = jos.Length();
	jos.Skip(2);//���峤��δ֪��������skip
	uint16 cnt = 0;
	uint16 seq = 0;
	jos<<cnt<<seq<<error_code;
	jos.WriteBytes(error_msg, 30);//������30���ֽ�
	size_t length = jos.Length();

	//ʵ���Ϲ�Ա��¼��Ӧ������ǿյģ�ʵ���ϴ��ȥ����0
	//�����峤�ȣ�ʵ����������0
	jos.Reposition(lengthPos);//ָ���ƶ�����Ҫ����峤��len��λ��
	jos<<static_cast<uint16>(length-sizeof(ResponseHead));//size_t length����4���ֽ�
															//����ʵ�����ʱ����ǿתΪ2���ֽ�����ȥ

	session.Send(jos.Data(), jos.Length());
}


