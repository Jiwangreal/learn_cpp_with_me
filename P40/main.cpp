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
        std::getline(std::cin, buffer);//����һ�б��ʽ�ŵ�buf����
        Scanner scanner(buffer);
        Parser parser(scanner);  
        parser.Parse();//ʵ���ϼ�����ʽ��ֵ�����Ǽ���������ĸ��ڵ��ֵ
        paese.Calculate();
    }while(1);
    return 0;
}