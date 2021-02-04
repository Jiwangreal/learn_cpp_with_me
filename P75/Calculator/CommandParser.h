#ifndef _COMMAND_PARSER_H
#define _COMMAND_PARSER_H

#include "Parser.h"
class Scanner;//ǰ������
class Calc;
class CommandParser
{
    //���������л��и��ָ������������ö�ٱ�ʾ��״̬
    enum ECommand
    {
        CMD_HELP,
        CMD_QUIT,
        CMD_VAR,
        CMD_FUN,
        CMD_LOAD,
        CMD_SAVE,
        CMD_ERROR
    }
public:
    CommandParser(Scanner& scanner, Calc& calc);
    STATUS Execute();
private:
    void Help() const;
    void ListVar() const;
    void ListFun() const;
    STATUS load(const std::string& filename);
    STATUS Save(const std::string& filename);
    Scanner& scanner_;
    Calc& calc_;
    ECommand cmd_;//��ǰ������������
    std::string cmdName_;//���������
};



#endif // _COMMAND_PARSER_H