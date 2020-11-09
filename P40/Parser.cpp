#include "Parser.h"
#include "Scanner.h"//因为会使用到Scanner的一些接口进行扫描

//引用的初始化只能才初始化列表中进行初始化
Parser::Parser(Scanner& scanner) : scanner_(scanner)
{

}

void Parser::Parse()
{

}

//注意：带const的成员函数与不带const的成员函数可以构成重载
double Parser::Calculate() const
{
    return 0.0;
}