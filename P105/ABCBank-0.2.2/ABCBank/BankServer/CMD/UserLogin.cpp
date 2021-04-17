#include "UserLogin.h"

#include "../../Public/Logging.h"
#include "../../Public/JUtil.h"
#include "../../Public/JInStream.h"
#include "../../Public/JOutStream.h"

using namespace PUBLIC;
using namespace CMD;

void UserLogin::Execute(BankSession& session)
{
	//JInStream用来解包，参考：请求包包头格式
	//session.GetRequestPack()->buf是包体部分，就是第5个字节的位置，也就是buffer_下标为4的位置
	JInStream jis(session.GetRequestPack()->buf, session.GetRequestPack()->head.len);//只有包体
	uint16 cmd = session.GetCmd();
	string name;//用户名
	string pass;//密码
	jis>>name>>pass;//解析出来

	int16 error_code = 0;
	char error_msg[31] = {0};
	if (name != "admin" || pass != "123456")
	{
		error_code = 1;//错误码对照手册：2.2.2.1.6	错误代码与错误信息对照表
		strcpy_s(error_msg, "用户名或密码错误");//strcpy_s是线程安全的
		LOG_INFO<<error_msg;
	}

	//给客户端一个应答包，参照：应答包包头格式
	JOutStream jos;
	jos<<cmd;
	size_t lengthPos = jos.Length();
	jos.Skip(2);//包体长度未知，所以先skip
	uint16 cnt = 0;
	uint16 seq = 0;
	jos<<cnt<<seq<<error_code;
	jos.WriteBytes(error_msg, 30);//定长的30个字节
	size_t length = jos.Length();

	//实际上柜员登录的应答包体是空的，实际上打进去的是0
	//填充包体长度，实际上填充的是0
	jos.Reposition(lengthPos);//指针移动到需要填包体长度len的位置
	jos<<static_cast<uint16>(length-sizeof(ResponseHead));//size_t length，是4个字节
															//但是实际填的时候，又强转为2个字节填充进去

	session.Send(jos.Data(), jos.Length());
}


