#include "OpenAccount.h"

#include "../../Public/Logging.h"
#include "../../Public/JUtil.h"

using namespace PUBLIC;
using namespace CMD;

void OpenAccount::Execute(BankSession& session)
{
	JOutStream jos;

	//请求包头开始：格式参照：ABCBank项目手册中的2.2.2.1.2请求包包头格式：cmd+len
	//2.2.2.3.1	请求包体格式：name+pass+id+money
	//
	// 包头命令
	uint16 cmd = CMD_OPEN_ACCOUNT;
	jos<<cmd;

	//len开始
	// 预留两个字节包头len(包体+包尾长度)，包体+包尾长度不知道长度，先预留2个字节
	size_t lengthPos = jos.Length();
	jos.Skip(2);
	//请求包包头结束

	//请求包包体开始
	// 客户姓名
	string name = session.GetAttribute("name");
	jos<<name;
	
	//开户的密码要求是加密的，要求在：ABCBank项目手册中的2.2.2.3.1请求包体
	//原始的密码不一定是定长的，加密后的密码是定长的
	//加密算法采用MD5+IDEA算法
	// 帐号密码
	string pass = session.GetAttribute("pass");
	unsigned char ideaKey[16];
	unsigned char buf[2];
	buf[0] = (cmd >> 8) & 0xff;
	buf[1] = cmd & 0xff;
	MD5 md5;
	md5.MD5Make(ideaKey, buf, 2);//首先用MD5生成一个ideaKey
	for (int i=0; i<8; ++i)
	{
		ideaKey[i] = ideaKey[i] ^ ideaKey[i+8];
		ideaKey[i] = ideaKey[i] ^ ((cmd >> (i%2)) & 0xff);
		ideaKey[i+8] = ideaKey[i] ^ ideaKey[i+8];
		ideaKey[i+8] = ideaKey[i+8] ^ ((cmd >> (i%2)) & 0xff);
	}
	char encryptedPass[16];
	Idea idea;
	//根据ideaKey，将原始的明文密码pass.c_str()，生成密文encryptedPass
	idea.Crypt(ideaKey,(const unsigned char*)pass.c_str(), (unsigned char *)encryptedPass, 16, true);	// 加密
	//打包进去
	jos.WriteBytes(encryptedPass, 16);


	// 身份证
	string id = session.GetAttribute("id");
	jos.WriteBytes(id.c_str(), id.length());
	// 开户金额
	jos<<session.GetAttribute("money");

	// 包头len字段
	size_t tailPos = jos.Length();
	jos.Reposition(lengthPos);
	jos<<(uint16)(tailPos + 8 - sizeof(RequestHead));//这个8是包尾格式，要求在：2.2.2.1.4	包尾格式
	//请求包包体结束

	// 包尾
	jos.Reposition(tailPos);//定位到包尾
	unsigned char hash[16];
	md5.MD5Make(hash, (unsigned char const*)jos.Data(), jos.Length());//用MD5Make生成一个哈希值hash，用来校验数据包是否完整
	for (int i=0; i<8; ++i)
	{
		hash[i] = hash[i] ^ hash[i+8];
		hash[i] = hash[i] ^ ((cmd >> (i%2)) & 0xff);
	}
	jos.WriteBytes(hash, 8);

	session.Send(jos.Data(), jos.Length());	// 发送请求包到服务器端，服务器端在BankSession* bs = new BankSession(socket_);	连接的线程中进行处理
	
	//发送完请求包后，开始接收应答
	session.Recv();	// 接收应答包
	JInStream jis((const char*)session.GetResponsePack(), session.GetResponsePack()->head.len+sizeof(ResponseHead));
	//解析应答包
	// 跳过cmd、len，因为这里面解析的时候，包头的cmd和len已经解析过了，所以才运行到这里来啦
	jis.Skip(4);
	uint16 cnt;
	uint16 seq;
	int16 error_code;
	jis>>cnt>>seq>>error_code;

	//解析错误信息，定长30字节。错误的文本信息
	char error_msg[31];
	jis.ReadBytes(error_msg, 30);
	
	//将数据设置到session中，这样客户端才便于获取数据
	session.SetErrorCode(error_code);
	session.SetErrorMsg(error_msg);

	//error_code=0说明是成功的应答
	if (error_code == 0)
	{
		char account_id[7] = {0};
		jis.ReadBytes(account_id, 6);//读取账号id

		string open_date;
		jis>>open_date;//读取开户日期

		//这样的话，OpenAccountForm的form->SetItemText("开户日期", bs.GetResponse("open_date"));就能得到开户日期
		session.SetResponse("account_id", account_id);
		session.SetResponse("open_date", open_date);
	}
}


