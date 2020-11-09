#include <isotream>
using namespace std;


//jmp_buf这实际上是一个数组类型
jmp_buf buf;

double Divide(double a, double b)
{
    if (b == 0.0)
    {
        //抛出异常
        throw 1;        //throw
    }
    else
    {
        return a / b;
    }
    
}

int main(void)
{
    try     //try  
    {             
        
        cout<<"division..."<<endl;
        //多次调用Divide，也没必要多次对Divide的返回值进行判断，因为现在是通过try。。。catch的
        //方式捕获异常，如果用返回值来判断错误的话，每次调用Divide都要判断它的错误而进行错误处理
        cout<<Divide(3.0, 0.0)<<endl;//只要其中一个出现了错误就会被捕捉到
        cout<<Divide(5.0, 0.0)<<endl;
    }
    //异常发生的地点与异常处理的地点可以相隔很远
    catch(int)//catch捕获整型异常
    {
        cout<<"divisiong by zero\n"<<endl;
    }

    return 0;
}




