#include "OpenAccount.h"

#include "../DAL/BankService.h"

#include "../../Public/Logging.h"
#include "../../Public/JUtil.h"
#include "../../Public/JInStream.h"
#include "../../Public/JOutStream.h"

using namespace PUBLIC;
using namespace CMD;
using namespace DAL;

void OpenAccount::Execute(BankSession& session)
{
	//包头已经解析成功
	JInStream jis(session.GetRequestPack()->buf, session.GetRequestPack()->head.len);
	uint16 cmd = session.GetCmd();

	//下面解析包体
	// 客户名称
	string name;
	jis>>name;
	// 密码
	char pass[16];
	unsigned char ideaKey[16];
	unsigned char buf[2];
	buf[0] = (cmd >> 8) & 0xff;
	buf[1] = cmd & 0xff;
	MD5 md5;
	md5.MD5Make(ideaKey, buf, 2);
	for (int i=0; i<8; ++i)
	{
		ideaKey[i] = ideaKey[i] ^ ideaKey[i+8];
		ideaKey[i] = ideaKey[i] ^ ((cmd >> (i%2)) & 0xff);
		ideaKey[i+8] = ideaKey[i] ^ ideaKey[i+8];
		ideaKey[i+8] = ideaKey[i+8] ^ ((cmd >> (i%2)) & 0xff);
	}
	char encryptedPass[16];
	jis.ReadBytes(encryptedPass, 16);//解密出来的是16字节的加密过的密码
	Idea idea;
	// 解密
	idea.Crypt(ideaKey, (const unsigned char*)encryptedPass, (unsigned char *)pass, 16, false);//解密保存在pass中

	// 身份证号码
	char id[19] = {0};
	jis.ReadBytes(id, 18);

	// 开户金额
	string money;
	jis>>money;

	int16 error_code = 0;
	char error_msg[31] = {0};


	// 实际的开户操作，会调用DAL中的OpenAccount函数
	BankService dao;//dao含义是data access operation
	int ret;

	Account acc;
	acc.id = id;//id
	acc.name = name;//客户名称
	acc.pass = pass;//密码
	acc.balance = Convert::StringToDouble(money);//借用余额字段来表示开户金额，也可以多一个字段表示开户金额

	//解包完毕后，进行数据库的实际访问操作；
	//进入到数据访问层DAL
	ret = dao.OpenAccount(acc);//只需要账户信息，访问数据库，调用ABCBank-0.3.1\ABCBank\BankServer\DAL\BankService.cpp
	//开户成功后，得到账户id和开户日期

	if (ret == 0)
	{
		LOG_INFO<<"开户成功";
	}
	else if (ret == 1)
	{
		error_code = 1;
		strcpy_s(error_msg, "用户名或密码错误");
		LOG_INFO<<error_msg;
	}
	else if (ret == -1)
	{
		error_code = -1;
		strcpy_s(error_msg, "数据库错误");
	}

	//开户的应答包
	JOutStream jos;

	//应答包的包头：命令+长度(包体+包尾)，要求见：2.2.2.1.3	应答包包头格式
	// 包头命令
	jos<<cmd;
	size_t lengthPos = jos.Length();//先预留2个字节
	jos.Skip(2);

	// 包头cnt、seq、error_code、error_msg
	//返回0是因为返回的不是明细数据包，明细数据包的cnt表示包里的总行数，明细数据包的seq表示第几行
	//error_code表示错误代码，error_msg错误代码对应的信息
	uint16 cnt = 0;
	uint16 seq = 0;
	jos<<cnt<<seq<<error_code;
	jos.WriteBytes(error_msg, 30);

	//开户应答包的包体，要求见：2.2.2.3.3	应答包体
	//应答时，将客户id以及开户日期应答给客户端
	// 包体account_id + date
	stringstream ss;
	ss<<setw(6)<<setfill('0')<<acc.account_id;
	jos.WriteBytes(ss.str().c_str(), 6);
	jos<<acc.op_date;

	// 包头len
	size_t tailPos = jos.Length();
	jos.Reposition(lengthPos);
	jos<<static_cast<uint16>(tailPos + 8 - sizeof(ResponseHead)); // 包体长度 + 包尾长度

	// 包尾
	jos.Reposition(tailPos);
	// 计算包尾
	unsigned char hash[16];
	md5.MD5Make(hash, (const unsigned char*)jos.Data(), jos.Length());
	for (int i=0; i<8; ++i)
	{
		hash[i] = hash[i] ^ hash[i+8];
		hash[i] = hash[i] ^ ((cmd >> (i%2)) & 0xff);
	}
	jos.WriteBytes(hash, 8);

	session.Send(jos.Data(), jos.Length());
}


