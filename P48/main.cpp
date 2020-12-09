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
        std::getline(std::cin, buffer);//����һ�б��ʽ�ŵ�buf����
        // std::cout<<buffer<<std::endl;
        Scanner scanner(buffer);
        //�����ֱ�Ӱ��س�������bug����ɨ����scanner��������IsEmpty����
        if (!scanner.IsEmpty())
        {
            Parser parser(scanner, calc);  
            status = parser.Parse();//ʵ���ϼ�����ʽ��ֵ�����Ǽ���������ĸ��ڵ��ֵ
             //���1+1=2��bug
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
        

    }while(status != STATUS_QUIT);//status=STATUS_QUIT�Ż�����ѭ��
    return 0;
}