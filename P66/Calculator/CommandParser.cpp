#include <cassert>
#include <iostream>
#include "CommandParser.h"
#include "Scanner.h"
#include "Calc.h"

CommandParser::CommandParser(Scanner& scanner, Calc& calc) : scanner_(scanner), calc_(calc)
{
    //不适用assert(scanner.IsCommand());原因是若Scanner& scanner是智能指针
    //所有权已经转移了，还使用它的化，就有可能出错
    assert(scanner_.IsCommand());
    //扫描到整个标识符，保存到string变量中
    scanner_.Accept();
    cmdName_ = scanner_.GetSymbol();//获取整个string变量
    //当前的switch语句可扩展性不高，可以配置到表格当中，表格中所支持的命令可以从配置文件中加载，这样扩展性就高
    //这就是表驱动编程，表驱动编程需要动态创建的功能，命令所对应的类的处理必须动态创建类对象，思想要直到
    switch (cmdName_[0])
    {
        case 'h':
            cmd_ = CMD_HELP;
            break;
        case 'q':
            cmd_ = CMD_QUIT;
            break;
        case 'v':
            cmd_ = CMD_VAR;
            break;
        case 'f':
            cmd_ = CMD_FUN;
            break;
        case 'l':
            cmd_ = CMD_LOAD;
        case 's':
            cmd_ = CMD_SAVE;
        default:
            cmd_ = CMD_ERROR;
            break;
    }
}
STATUS CommandParser::Execute()
{
    STATUS status = STATUS_OK;
    //获取参数文件名的方法
    //eg：!s filename
    scanner_.AcceptCommand();
    std::string fileName;
    switch (cmd_)
    {
        case CMD_HELP:
            Help();
            break;
        case CMD_QUIT:
            std::cout<<"Good Bye!"<<std::endl;
            status = STATUS_QUIT;
            break;
        case CMD_VAR:
            ListVar();
            break;
        case CMD_FUN:
            ListFun();
            break;
        case CMD_LOAD:
            fileName = scanner_.GetSymbol();
            status = Load(fileName);
            break;
        case CMD_SAVE:
            fileName = scanner_.GetSymbol();
            status = Save(fileName);
            break;
        default:
            std::cout<<"Unknow Command \"<<cmdName_<<"\"."<<std::endl;
            status = STATUS_ERROR;
            break;
    }
    return status;
}

void CommandParser::Help() const
{
    std::cout<<"Recognized commands:"<<std::endl;
    std::cout<<"!help"<<std::endl;
    std::cout<<"!quit"<<std::endl;
    std::cout<<"!v"<<std::endl;
    std::cout<<"!f"<<std::endl;
    std::cout<<"!load filename"<<std::endl;
    std::cout<<"!save filename"<<std::endl;

}

void CommandParser::ListVar() const
{
    std::cout<<"variable list:"<<std::endl;
    calc_.ListVar();
}

void CommandParser::ListFun() const
{
    std::cout<<"function list:"<<std::endl;
    calc_.ListFun();
}

STATUS CommandParser::load(const std::string& filename)
{
    std::cout<<"load \""<<filename<<"\"."<<std::endl;
    return STATUS_OK;
}

STATUS CommandParser::Save(const std::string& filename)
{
    std::cout<<"save \""<<filename<<"\"."<<std::endl;
    return STATUS_OK;
}
