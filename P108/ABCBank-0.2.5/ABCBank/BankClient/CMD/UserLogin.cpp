#include "UserLogin.h"

#include "../../Public/Logging.h"
#include "../../Public/JUtil.h"

using namespace PUBLIC;
using namespace CMD;

void UserLogin::Execute(BankSession& session)
{
	JOutStream jos;
	
	//首先打包包头：包头命令+长度
	// 包头命令
	uint16 cmd = CMD_LOGIN;
	jos<<cmd;

	//然后是包头部分的长度
	// 预留两个字节包头len（包体+包尾长度）
	size_t lengthPos = jos.Length();
	jos.Skip(2);

	//接下来是包体部分
	// 柜员登录名
	string name = session.GetAttribute("name");
	jos<<name;

	// 密码
	string pass = session.GetAttribute("pass");
	unsigned char ideaKey[16];//使用MD5Make计算，作为IDEA算法的key，这个key是不会传输到网络上的
							  //若网络上截取到这个key，是可以破解密码的
	unsigned char buf[2];
	buf[0] = (cmd >> 8) & 0xff;
	buf[1] = cmd & 0xff;
	MD5 md5;
	md5.MD5Make(ideaKey, buf, 2);

	//搅拌运算或者混合运算，得到ideaKey
	for (int i=0; i<8; ++i)
	{
		ideaKey[i] = ideaKey[i] ^ ideaKey[i+8];
		ideaKey[i] = ideaKey[i] ^ ((cmd >> (i%2)) & 0xff);
		ideaKey[i+8] = ideaKey[i] ^ ideaKey[i+8];
		ideaKey[i+8] = ideaKey[i+8] ^ ((cmd >> (i%2)) & 0xff);
	}
	char encryptedPass[16];
	Idea idea;
	// 加密
	//pass是string类型的，需要转化成c_str
	//ideaKey是IDEA算法的密钥，pass.c_str()是原始的密码，encryptedPass是加密过的密码，true表示加密
	idea.Crypt(ideaKey,(const unsigned char*)pass.c_str(), (unsigned char *)encryptedPass, 16, true);

	//打包进去，是定长的16个字节
	jos.WriteBytes(encryptedPass, 16);


	//包头的长度tailPos就是包尾的位置
	size_t tailPos = jos.Length();

	//lengthPos是包头len字段
	jos.Reposition(lengthPos);
	//tailPos + 8是整个包的长度
	//tailPos + 8 - sizeof(RequestHead)是包体+包尾的长度
	jos<<static_cast<uint16>(tailPos + 8 - sizeof(RequestHead)); // 包体长度 + 包尾长度

	// 包尾，定位到包尾的位置
	jos.Reposition(tailPos);
	// 计算包尾hash
	unsigned char hash[16];
	md5.MD5Make(hash, (const unsigned char*)jos.Data(), jos.Length());//MD5是包头+包体做MD5值，然后放到包尾
																	 //此时的jos.Length()就等于tailPos
	for (int i=0; i<8; ++i)
	{
		hash[i] = hash[i] ^ hash[i+8];
		hash[i] = hash[i] ^ ((cmd >> (i%2)) & 0xff);
	}
	//打包进去
	jos.WriteBytes(hash, 8);
	//打包后，指针就到包尾了

	session.Send(jos.Data(), jos.Length());	// 发送请求包
	session.Recv();	// 接收应答包
	JInStream jis((const char*)session.GetResponsePack(), session.GetResponsePack()->head.len+sizeof(ResponseHead));
	// 跳过cmd、len
	jis.Skip(4);
	uint16 cnt;
	uint16 seq;
	int16 error_code;
	jis>>cnt>>seq>>error_code;

	char error_msg[31];
	jis.ReadBytes(error_msg, 30);

	session.SetErrorCode(error_code);
	session.SetErrorMsg(error_msg);
}


