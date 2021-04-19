#include "UserLogin.h"

#include "../../Public/Logging.h"
#include "../../Public/JUtil.h"
#include "../../Public/JInStream.h"
#include "../../Public/JOutStream.h"

using namespace PUBLIC;
using namespace CMD;

void UserLogin::Execute(BankSession& session)
{
	JInStream jis(session.GetRequestPack()->buf, session.GetRequestPack()->head.len);
	uint16 cmd = session.GetCmd();
	string name;
	string pass;
	jis>>name>>pass;

	int16 error_code = 0;
	char error_msg[31] = {0};
	if (name != "admin" || pass != "123456")
	{
		error_code = 1;
		strcpy_s(error_msg, "用户名或密码错误");
		LOG_INFO<<error_msg;
	}

	JOutStream jos;
	jos<<cmd;
	size_t lengthPos = jos.Length();
	jos.Skip(2);
	uint16 cnt = 0;
	uint16 seq = 0;
	jos<<cnt<<seq<<error_code;
	jos.WriteBytes(error_msg, 30);
	size_t length = jos.Length();
	jos.Reposition(lengthPos);
	jos<<static_cast<uint16>(length-sizeof(ResponseHead));

	session.Send(jos.Data(), length);
}


