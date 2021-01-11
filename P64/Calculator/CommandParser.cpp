#include "CommandParser.h"
#include "Scanner.h"
#include "Calc.h"

CommandParser::CommandParser(Scanner& scanner, Calc& calc) : scanner_(scanner), calc_(calc)
{

}
STATUS CommandParser::Execute()
{
    STATUS status = STATUS_OK;
    return status;
}