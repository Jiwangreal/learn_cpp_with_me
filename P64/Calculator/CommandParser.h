#ifndef _COMMAND_PARSER_H
#define _COMMAND_PARSER_H

#include "Parser.h"
class Scanner;//ǰ������
class Calc;
class CommandParser
{
public:
    CommandParser(Scanner& scanner, Calc& calc);
    STATUS Execute();
private:
    Scanner& scanner_;
    Calc& calc_;

};



#endif // _COMMAND_PARSER_H