#include <cassert>
#include <cassert>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(void)
{
    /*
    (1)如果以文本方式打开文件，写入字符的时候，遇到\n会做转换，写入\r不做转换
    windows平台\n会转换为 \r\n
    linux平台保留不变
    mac系统\n转换为\r    

    (2)如果以二进制方式打开文件写入字符的时候，遇到\n不会做转换

    (3)以文本方式打开文件，也可以写入二进制数据
    以二进制方式打开文件，也可以写入文本
    写入的数据是二进制还是文本，与打开方式无关，与写入使用的函数有关
    要写入二进制数据，应该用write，相应的读要用read
    */
   //以二进制方式打开
    ofstream fout1( "test3.txt", ios::out| ios::binary );
    fout1<<"ABC\r\n";
    fout1.close();
    return 0;
}