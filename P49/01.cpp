#include <stdio.h>
#include <setjmp.h>

//jmp_buf这实际上是一个数组类型
jmp_buf buf;

double Divide(double a, double b)
{
    if (b == 0.0)
    {
        //抛出异常
        longjmp(buf, 1);//这里进行了一次长跳转，它可以跳转到另外的函数，而go to只能在函数内部跳转，
                        //这里长跳转会跳转到buf保存点的位置： ret = setjmp(buf);，然后继续执行
                        //然而这次的返回值是1（返回值根据longjmp的第二个参数来决定），所以会输出：divisiong by zero
                        //相当于C++中的异常的抛出点throw
    }
    else
    {
        return a / b;
    }
    
}

int main(void)
{
    int ret;
    //栈stack环境保存在buf中
    //设置一个保存点buf，保存成功返回0
    ret = setjmp(buf);//首先保存程序的运行环境到buf缓冲区中
    if (ret == 0)//第一次保存总是成功的，所以进入到=0，输出：division...    
    {             //相当于C++的try
        printf("division...\n");
        printf("%f\n", Divide(5.0, 0.0));//接着执行Divide函数
    }
    else if(ret == 1)//相当于C++中的catch，对抛出的异常进行处理
    {
        printf("divisiong by zero\n");
    }

    return 0;
}




