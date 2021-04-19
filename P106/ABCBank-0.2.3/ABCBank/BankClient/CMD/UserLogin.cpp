#include "UserLogin.h"

#include "../../Public/Logging.h"
#include "../../Public/JUtil.h"

using namespace PUBLIC;
using namespace CMD;

//进行打包操作，打包的数据已经传递到session了
void UserLogin::Execute(BankSession& session)
{
	JOutStream jos;

	//请求包
	//等价于uint16 cmd = session.GetCmd();
	uint16 cmd = CMD_LOGIN;
	jos<<cmd;

	size_t lengthPos = jos.Length();
	jos.Skip(2);

	//内部协议name，pass
	string name = session.GetAttribute("name");
	jos<<name;

	string pass = session.GetAttribute("pass");
	jos<<pass;

	size_t length = jos.Length();
	jos.Reposition(lengthPos);
	jos<<static_cast<uint16>(length - sizeof(RequestHead));//包体


	//session.Send(jos.Data(), jos.Length());不对
	session.Send(jos.Data(), length);	// 发送请求包
	session.Recv();	// 接收应答包，如果出现异常，就跳转到catch (Exception& e)
	JInStream jis((const char*)session.GetResponsePack(), session.GetResponsePack()->head.len+sizeof(ResponseHead));
	
	jis.Skip(4);// 跳过cmd、len
	uint16 cnt;
	uint16 seq;
	int16 error_code;
	jis>>cnt>>seq>>error_code;//应答包的包头

	char error_msg[31];
	jis.ReadBytes(error_msg, 30);

	session.SetErrorCode(error_code);
	session.SetErrorMsg(error_msg);
}


