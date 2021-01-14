#include <cassert>
#include <iostream>
#include "CommandParser.h"
#include "Scanner.h"
#include "Calc.h"

CommandParser::CommandParser(Scanner& scanner, Calc& calc) : scanner_(scanner), calc_(calc)
{
    //������assert(scanner.IsCommand());ԭ������Scanner& scanner������ָ��
    //����Ȩ�Ѿ�ת���ˣ���ʹ�����Ļ������п��ܳ���
    assert(scanner_.IsCommand());
    //ɨ�赽������ʶ�������浽string������
    scanner_.Accept();
    cmdName_ = scanner_.GetSymbol();//��ȡ����string����
    //��ǰ��switch������չ�Բ��ߣ��������õ�����У��������֧�ֵ�������Դ������ļ��м��أ�������չ�Ծ͸�
    //����Ǳ�������̣������������Ҫ��̬�����Ĺ��ܣ���������Ӧ����Ĵ�����붯̬���������˼��Ҫֱ��
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
    //��ȡ�����ļ����ķ���
    //eg��!s filename
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
