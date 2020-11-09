#include <iostream>
#include <string>
#include "Scanner.h"
#include "Parser.h"
#include "Calc.h"

int main(void)
{
    Calc calc;
    STATUS status= STATUS_OK;
    do
    {
        std::cout<<">";
        std::string buffer;
        std::getline(std::cin, buffer);//����һ�б��ʽ�ŵ�buf����
        // std::cout<<buffer<<std::endl;
        Scanner scanner(buffer);
        Parser parser(scanner, calc);  
        parser.Parse();//ʵ���ϼ�����ʽ��ֵ�����Ǽ���������ĸ��ڵ��ֵ
        std::cout<<paese.Calculate()<<std::endl;
    }while(status != STATUS_QUIT);
    return 0;
}