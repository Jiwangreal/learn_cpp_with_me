#include "Parser.h"
#include "Scanner.h"//��Ϊ��ʹ�õ�Scanner��һЩ�ӿڽ���ɨ��

//���õĳ�ʼ��ֻ�ܲų�ʼ���б��н��г�ʼ��
Parser::Parser(Scanner& scanner) : scanner_(scanner)
{

}

void Parser::Parse()
{

}

//ע�⣺��const�ĳ�Ա�����벻��const�ĳ�Ա�������Թ�������
double Parser::Calculate() const
{
    return 0.0;
}