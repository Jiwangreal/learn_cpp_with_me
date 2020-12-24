#include <iostream>
#include <string>
#include "Scanner.h"
#include "Parser.h"
#include "Calc.h"
#include "Exception.h"

int main(void)
{
    Calc calc;
    STATUS status = STATUS_OK;
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
            //Parser是局部对象
            Parser parser(scanner, calc);  
            //try catch写法可以将程序的正常处理流程与错误处理流程隔离开来
            //解析的时候可能会抛出异常
            try
            {
                status = parser.Parse();//实际上计算表达式的值，就是计算这颗树的根节点的值
                //解决1+1=2的bug
                if (status == STATUS_OK)//这里不判断返回值也是可以的，因为又错误就抛出异常了。没有错误就进入正常流程
                {                       //即正常流程不需要通过返回值来判断它是否是正常，C语言才是通过返回值来判断是否是正常的
                    std::cout<<paese.Calculate()<<std::endl;
                }
            }
            catch (SyntaxError& se)//派生类的异常
            {
                status = STATUS_QUIT;//为了检查内存泄漏
                std::cout<<se.what()<<std::endl;
                // std::cout<<se.StackTrace()<<std::endl;//发生异常时，可以将栈的调用关系给打印出来，只做演示说明，所以加上了注释
            }
            catch (Exception& se)//基类的异常
            {
                status = STATUS_QUIT;//为了检查内存泄漏
                std::cout<<e.what()<<std::endl;
            }
            //内存分配失败的异常
            //比较少见：因为虚拟内存的存在，即使超过了物理内存，还是可以分配内存的，但是不饿能认为分配一定成功
            catch(std::bad_alloc& e)
            {
                status = STATUS_QUIT;
                std::cout<<e.what()<<std::endl;
            }
            catch (...)//其他异常，...表示任意类型的异常
            {
                status = STATUS_QUIT;//为了检查内存泄漏
                std::cout<<"Internal error."<<std::endl;
            }
        }
        else
        {
            status = STATUS_QUIT;//为了检查内存泄漏，就会退出程序，就会打印内存泄漏的信息
            std::cout<<"Expression is empty."<<std::endl;
        }
        

    }while(status != STATUS_QUIT);//status=STATUS_QUIT才会跳出循环
    return 0;
}