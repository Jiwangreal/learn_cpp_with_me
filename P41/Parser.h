#ifndef _PARSER_H
#define _PARSER_H

//ʹ��ǰ�����������ǰ���Scanner��ͷ�ļ���ԭ���ǣ������cpp�ļ��ж�ΰ�����������ͷ�ļ���ʹ�����ɵĿ�ִ���ļ�����
class Scanner;

//Parser�ࣺ����ɨ����������ɨ�裬�ݹ��½�������ֱ������һ����
class Parser
{
public:
    Parser(Scanner& scanner);
    void Parse();
    double Calculate() const;
private:
    Scanner& scanner_;
};



#endif /* _PARSER_H */