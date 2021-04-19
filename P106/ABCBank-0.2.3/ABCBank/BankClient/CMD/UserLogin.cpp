#include "UserLogin.h"

#include "../../Public/Logging.h"
#include "../../Public/JUtil.h"

using namespace PUBLIC;
using namespace CMD;

//���д������������������Ѿ����ݵ�session��
void UserLogin::Execute(BankSession& session)
{
	JOutStream jos;

	//�����
	//�ȼ���uint16 cmd = session.GetCmd();
	uint16 cmd = CMD_LOGIN;
	jos<<cmd;

	size_t lengthPos = jos.Length();
	jos.Skip(2);

	//�ڲ�Э��name��pass
	string name = session.GetAttribute("name");
	jos<<name;

	string pass = session.GetAttribute("pass");
	jos<<pass;

	size_t length = jos.Length();
	jos.Reposition(lengthPos);
	jos<<static_cast<uint16>(length - sizeof(RequestHead));//����


	//session.Send(jos.Data(), jos.Length());����
	session.Send(jos.Data(), length);	// ���������
	session.Recv();	// ����Ӧ�������������쳣������ת��catch (Exception& e)
	JInStream jis((const char*)session.GetResponsePack(), session.GetResponsePack()->head.len+sizeof(ResponseHead));
	
	jis.Skip(4);// ����cmd��len
	uint16 cnt;
	uint16 seq;
	int16 error_code;
	jis>>cnt>>seq>>error_code;//Ӧ����İ�ͷ

	char error_msg[31];
	jis.ReadBytes(error_msg, 30);

	session.SetErrorCode(error_code);
	session.SetErrorMsg(error_msg);
}


