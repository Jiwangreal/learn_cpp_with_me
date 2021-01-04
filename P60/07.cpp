#include <cassert>
#include <cassert>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Test
{
    int a;
    int b;
};

//测试：以二进制方式打开文件，也可以写入文本
int main(void)
{
    Test test = {100, 200};
    //以二进制方式打开
    
    ofstream fout("test4.txt", ios::out|ios::binary);

    //c插入运算符<<是以文本方式写入数据的
    //虽然以二进制方式打开，但是写入的方式是文本的方式
    fout<<"abc"<<200;

    return 0;
}