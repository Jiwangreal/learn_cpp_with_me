#ifndef _PARSER_H
#define _PARSER_H

//ʹ��ǰ�����������ǰ���Scanner��ͷ�ļ���ԭ���ǣ������cpp�ļ��ж�ΰ�����������ͷ�ļ���ʹ�����ɵĿ�ִ���ļ�����
class Scanner;
class Node;//����� Node* Expr();��û�ж���Node

enum STATUS
{
    STATUS_OK;
    STATUS_ERROR;
    STATUS_QUIT;
};


//Parser�ࣺ����ɨ����������ɨ�裬�ݹ��½�������ֱ������һ����
//Parser����Scanner��֮��Ĺ�ϵ��ʲô��
//������ϵ��һ������Ϊ��һ�����Ա�����Ĳ����������ڲ��ľֲ�����������ĳ����ľ�̬��Ա����
//��Scanner��ΪParser��ĳ�Ա�����������ã� Scanner& scanner_;
//˵����Scanner����Parser�����һ���Ĺ̶���ϵ����Parser������������ڶ�Ҫ��scanner_�����ù̶���ϵ
//���԰����ǿ��ɹ�����ϵ
class Parser
{
public:
    Parser(Scanner& scanner);
    void Parse();
    Node* Expr();
    Node* Term();
    Node* Factor();
    double Calculate() const;
private:
    Scanner& scanner_;//���������ã���ʹParser�������ˣ�Scanner��Ҳ����һ�����٣�Parser�಻����Scanner�����������
                    //�����ﲻ�����ã�Parser�������٣�Scanner����Ҳ�������٣��������Ϲ�ϵ��
                    //����Ҳ���������ã����ǻ´��һ��Scanner����󿽱���Parser���ڲ�����ϵķ�ʽЧ�ʵ�һЩ��û��Ҫ����
    Node* tree_;
    STATUS status_;
};



#endif /* _PARSER_H */