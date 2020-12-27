#include <iostream>
using namespace std;


//用宏来实现计算某个变量的大小
//sizeof_v

//使用宏来计算某个类型的大小
//sizeof_t

class Empty
{

};

int main(void)
{

    cout<<sizeof(Empty)<<endl;//空类的大小是一个字节
    return 0;
}