#ifndef _COMMAND_PARSER_H
#define _COMMAND_PARSER_H

#include "Parser.h"
class Scanner;//前向声明
class Calc;
class CommandParser
{
    //解析过程中会有各种各样的命令，定义枚举表示其状态
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
    ECommand cmd_;//当前解析到的命令
    std::string cmdName_;//命令的名称
};



#endif // _COMMAND_PARSER_H