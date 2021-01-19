#ifndef _PARSER_H
#define _PARSER_H

#include <memory>
//ʹ��ǰ�����������ǰ���Scanner��ͷ�ļ���ԭ���ǣ������cpp�ļ��ж�ΰ�����������ͷ�ļ���ʹ�����ɵĿ�ִ���ļ�����
class Scanner;
class Node;//����� Node* Expr();��û�ж���Node
class Calc;

enum STATUS
{
    STATUS_OK,
    STATUS_ERROR,
    STATUS_QUIT
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
    Parser(Scanner& scanner, Calc& calc);

    //û���ṩ������������������ṩ�����������������ṩ�Ĺ��캯���������ģ�����ͷ�ļ�����ֱ�Ӹ�����������
    //����������Ҫ����std::auto_ptr<Node> tree_;auto_ptr������ͷţ������ͷ�ʱ��������������еĶ���Node*������ͷ�
    //����������class Node;��Node�ǲ���ȫ������ǰ����������������~Parser() {}������֪��Node������������������������������־���
    // ~Parser() {}//��ͷ�ļ���߸�������������������ṩ�Ŀյ�����������һ���ģ���������ͷ�ļ���ֱ�Ӹ�������������
                //����취������cpp�ļ��и��������������������û��ʵ��
    ~Parser();//�澯�Ľ���취
    // ~Parser();
    STATUS Parse();
    std::auto_ptr<Node> Expr();//��Node*��Ϊ����ָ�룺 std::auto_ptr<Node>
    std::auto_ptr<Node> Term();
    std::auto_ptr<Node> Factor();
    double Calculate() const;
private:
    Scanner& scanner_;//���������ã���ʹParser�������ˣ�Scanner��Ҳ����һ�����٣�Parser�಻����Scanner�����������
                    //�����ﲻ�����ã�Parser�������٣�Scanner����Ҳ�������٣��������Ϲ�ϵ��
                    //����Ҳ���������ã����ǻ´��һ��Scanner����󿽱���Parser���ڲ�����ϵķ�ʽЧ�ʵ�һЩ��û��Ҫ����
    std::auto_ptr<Node> tree_;
    STATUS status_;
    Calc& calc_;
};


#endif /* _PARSER_H */