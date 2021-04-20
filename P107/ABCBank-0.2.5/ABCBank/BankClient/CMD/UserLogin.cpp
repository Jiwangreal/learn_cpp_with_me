#include "UserLogin.h"

#include "../../Public/Logging.h"
#include "../../Public/JUtil.h"

using namespace PUBLIC;
using namespace CMD;

void UserLogin::Execute(BankSession& session)
{
	JOutStream jos;
	
	//���ȴ����ͷ����ͷ����+����
	// ��ͷ����
	uint16 cmd = CMD_LOGIN;
	jos<<cmd;

	//Ȼ���ǰ�ͷ���ֵĳ���
	// Ԥ�������ֽڰ�ͷlen������+��β���ȣ�
	size_t lengthPos = jos.Length();
	jos.Skip(2);

	//�������ǰ��岿��
	// ��Ա��¼��
	string name = session.GetAttribute("name");
	jos<<name;

	// ����
	string pass = session.GetAttribute("pass");
	unsigned char ideaKey[16];//ʹ��MD5Make���㣬��ΪIDEA�㷨��key�����key�ǲ��ᴫ�䵽�����ϵ�
							  //�������Ͻ�ȡ�����key���ǿ����ƽ������
	unsigned char buf[2];
	buf[0] = (cmd >> 8) & 0xff;
	buf[1] = cmd & 0xff;
	MD5 md5;
	md5.MD5Make(ideaKey, buf, 2);

	//����������߻�����㣬�õ�ideaKey
	for (int i=0; i<8; ++i)
	{
		ideaKey[i] = ideaKey[i] ^ ideaKey[i+8];
		ideaKey[i] = ideaKey[i] ^ ((cmd >> (i%2)) & 0xff);
		ideaKey[i+8] = ideaKey[i] ^ ideaKey[i+8];
		ideaKey[i+8] = ideaKey[i+8] ^ ((cmd >> (i%2)) & 0xff);
	}
	char encryptedPass[16];
	Idea idea;
	// ����
	//pass��string���͵ģ���Ҫת����c_str
	//ideaKey��IDEA�㷨����Կ��pass.c_str()��ԭʼ�����룬encryptedPass�Ǽ��ܹ������룬true��ʾ����
	idea.Crypt(ideaKey,(const unsigned char*)pass.c_str(), (unsigned char *)encryptedPass, 16, true);

	//�����ȥ���Ƕ�����16���ֽ�
	jos.WriteBytes(encryptedPass, 16);


	//��ͷ�ĳ���tailPos���ǰ�β��λ��
	size_t tailPos = jos.Length();

	//lengthPos�ǰ�ͷlen�ֶ�
	jos.Reposition(lengthPos);
	//tailPos + 8���������ĳ���
	//tailPos + 8 - sizeof(RequestHead)�ǰ���+��β�ĳ���
	jos<<static_cast<uint16>(tailPos + 8 - sizeof(RequestHead)); // ���峤�� + ��β����

	// ��β����λ����β��λ��
	jos.Reposition(tailPos);
	// �����βhash
	unsigned char hash[16];
	md5.MD5Make(hash, (const unsigned char*)jos.Data(), jos.Length());//MD5�ǰ�ͷ+������MD5ֵ��Ȼ��ŵ���β
																	 //��ʱ��jos.Length()�͵���tailPos
	for (int i=0; i<8; ++i)
	{
		hash[i] = hash[i] ^ hash[i+8];
		hash[i] = hash[i] ^ ((cmd >> (i%2)) & 0xff);
	}
	//�����ȥ
	jos.WriteBytes(hash, 8);
	//�����ָ��͵���β��

	session.Send(jos.Data(), jos.Length());	// ���������
	session.Recv();	// ����Ӧ���
	JInStream jis((const char*)session.GetResponsePack(), session.GetResponsePack()->head.len+sizeof(ResponseHead));
	// ����cmd��len
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


