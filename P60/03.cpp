#include <cassert>
#include <cassert>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(void)
{
    /*
    如果以文本方式打开文件，写入字符的时候，遇到\n会做转换，写入\r不做转换
    如果以二进制方式打开文件写入字符的时候，遇到\n不会做转换

    windows平台\n会转换为 \r\n
    linux平台保留不变
    mac系统\n转换为\r    
    */
    //默认以文本方式打开文件
    ofstream fout1( "test3.txt");
    fout1<<"ABC\r\n";
    fout1.close();
    return 0;
}