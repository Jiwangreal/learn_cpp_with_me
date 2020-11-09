#include <iostream>
#include <string>
#include "Scanner.h"
#include "Parser.h"

int main(void)
{
    do
    {
        std::cout<<">";
        std::string buffer;
        std::getline(std::cin, buffer);//输入一行表达式放到buf当中
        Scanner scanner(buffer);
        Parser parser(scanner);  
        parser.Parse();//实际上计算表达式的值，就是计算这颗树的根节点的值
        paese.Calculate();
    }while(1);
    return 0;
}