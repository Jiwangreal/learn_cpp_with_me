#include "OpenAccount.h"

#include "../../Public/Logging.h"
#include "../../Public/JUtil.h"

using namespace PUBLIC;
using namespace CMD;

void OpenAccount::Execute(BankSession& session)
{
	JOutStream jos;

	//�����ͷ��ʼ����ʽ���գ�ABCBank��Ŀ�ֲ��е�2.2.2.1.2�������ͷ��ʽ��cmd+len
	//2.2.2.3.1	��������ʽ��name+pass+id+money
	//
	// ��ͷ����
	uint16 cmd = CMD_OPEN_ACCOUNT;
	jos<<cmd;

	//len��ʼ
	// Ԥ�������ֽڰ�ͷlen(����+��β����)������+��β���Ȳ�֪�����ȣ���Ԥ��2���ֽ�
	size_t lengthPos = jos.Length();
	jos.Skip(2);
	//�������ͷ����

	//��������忪ʼ
	// �ͻ�����
	string name = session.GetAttribute("name");
	jos<<name;
	
	//����������Ҫ���Ǽ��ܵģ�Ҫ���ڣ�ABCBank��Ŀ�ֲ��е�2.2.2.3.1�������
	//ԭʼ�����벻һ���Ƕ����ģ����ܺ�������Ƕ�����
	//�����㷨����MD5+IDEA�㷨
	// �ʺ�����
	string pass = session.GetAttribute("pass");
	unsigned char ideaKey[16];
	unsigned char buf[2];
	buf[0] = (cmd >> 8) & 0xff;
	buf[1] = cmd & 0xff;
	MD5 md5;
	md5.MD5Make(ideaKey, buf, 2);//������MD5����һ��ideaKey
	for (int i=0; i<8; ++i)
	{
		ideaKey[i] = ideaKey[i] ^ ideaKey[i+8];
		ideaKey[i] = ideaKey[i] ^ ((cmd >> (i%2)) & 0xff);
		ideaKey[i+8] = ideaKey[i] ^ ideaKey[i+8];
		ideaKey[i+8] = ideaKey[i+8] ^ ((cmd >> (i%2)) & 0xff);
	}
	char encryptedPass[16];
	Idea idea;
	//����ideaKey����ԭʼ����������pass.c_str()����������encryptedPass
	idea.Crypt(ideaKey,(const unsigned char*)pass.c_str(), (unsigned char *)encryptedPass, 16, true);	// ����
	//�����ȥ
	jos.WriteBytes(encryptedPass, 16);


	// ���֤
	string id = session.GetAttribute("id");
	jos.WriteBytes(id.c_str(), id.length());
	// �������
	jos<<session.GetAttribute("money");

	// ��ͷlen�ֶ�
	size_t tailPos = jos.Length();
	jos.Reposition(lengthPos);
	jos<<(uint16)(tailPos + 8 - sizeof(RequestHead));//���8�ǰ�β��ʽ��Ҫ���ڣ�2.2.2.1.4	��β��ʽ
	//������������

	// ��β
	jos.Reposition(tailPos);//��λ����β
	unsigned char hash[16];
	md5.MD5Make(hash, (unsigned char const*)jos.Data(), jos.Length());//��MD5Make����һ����ϣֵhash������У�����ݰ��Ƿ�����
	for (int i=0; i<8; ++i)
	{
		hash[i] = hash[i] ^ hash[i+8];
		hash[i] = hash[i] ^ ((cmd >> (i%2)) & 0xff);
	}
	jos.WriteBytes(hash, 8);

	session.Send(jos.Data(), jos.Length());	// ������������������ˣ�����������BankSession* bs = new BankSession(socket_);	���ӵ��߳��н��д���
	
	//������������󣬿�ʼ����Ӧ��
	session.Recv();	// ����Ӧ���
	JInStream jis((const char*)session.GetResponsePack(), session.GetResponsePack()->head.len+sizeof(ResponseHead));
	//����Ӧ���
	// ����cmd��len����Ϊ�����������ʱ�򣬰�ͷ��cmd��len�Ѿ��������ˣ����Բ����е���������
	jis.Skip(4);
	uint16 cnt;
	uint16 seq;
	int16 error_code;
	jis>>cnt>>seq>>error_code;

	//����������Ϣ������30�ֽڡ�������ı���Ϣ
	char error_msg[31];
	jis.ReadBytes(error_msg, 30);
	
	//���������õ�session�У������ͻ��˲ű��ڻ�ȡ����
	session.SetErrorCode(error_code);
	session.SetErrorMsg(error_msg);

	//error_code=0˵���ǳɹ���Ӧ��
	if (error_code == 0)
	{
		char account_id[7] = {0};
		jis.ReadBytes(account_id, 6);//��ȡ�˺�id

		string open_date;
		jis>>open_date;//��ȡ��������

		//�����Ļ���OpenAccountForm��form->SetItemText("��������", bs.GetResponse("open_date"));���ܵõ���������
		session.SetResponse("account_id", account_id);
		session.SetResponse("open_date", open_date);
	}
}


