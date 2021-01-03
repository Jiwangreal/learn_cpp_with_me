#include <cassert>
#include <iostream>
#include <fstream>
using namespace std;


int main(void)
{
    //文件输出流ofstream默认打开模式是ios::out（没有指任何模式时）
    //输入流ifstream默认打开模式是ios::in
    ofstream fout("test.txt", ios::out);//等价于指定了ios::out|ios::trunc模式

    //当文件同时以in和out打开时不会清空
    ofstream fout("test.txt", ios::out|ios::in);

    //如果打开文件时指定了trunc模式，则无论是否同时指定了in模式，文件同样会被清空
    ofstream fout("test.txt", ios::out|ios::in|ios::trunc);

    //如果同时指定了out与app，不会清空
    ofstream fout("test.txt", ios::out|ios::in|ios::app);

    assert(fin);

    fout.close();
    return 0;
}