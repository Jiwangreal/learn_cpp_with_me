#include <iostream>
#include <string>
#include "Scanner.h"
#include "Parser.h"

int main(void)
{
    STATUS status= STATUS_OK;
    do
    {
        std::cout<<">";
        std::string buffer;
        std::getline(std::cin, buffer);//输入一行表达式放到buf当中
        // std::cout<<buffer<<std::endl;
        Scanner scanner(buffer);
        Parser parser(scanner);  
        parser.Parse();//实际上计算表达式的值，就是计算这颗树的根节点的值
        std::cout<<paese.Calculate()<<std::endl;
    }while(status != STATUS_QUIT);
    return 0;
}