#include <iostream>
#include <string>
#include "Scanner.h"
#include "Parser.h"
#include "Calc.h"

int main(void)
{
    Calc calc;
    STATUS status;
    do
    {
        std::cout<<">";
        std::string buffer;
        std::getline(std::cin, buffer);//输入一行表达式放到buf当中
        // std::cout<<buffer<<std::endl;
        Scanner scanner(buffer);
        //解决：直接按回车会出错的bug：在扫描器scanner类中增加IsEmpty方法
        if (!scanner.IsEmpty())
        {
            Parser parser(scanner, calc);  
            status = parser.Parse();//实际上计算表达式的值，就是计算这颗树的根节点的值
             //解决1+1=2的bug
            if (status == STATUS_OK)
            {
                std::cout<<paese.Calculate()<<std::endl;
            }
            else
            {
                std::cout<<"Syntax Error. "<<std::endl;
            }
            
        }
        else
        {
            std::cout<<"Expression is empty."<<std::endl;
        }
        

    }while(status != STATUS_QUIT);//status=STATUS_QUIT才会跳出循环
    return 0;
}