#include <cassert>
#include <iostream>
#include <fstream>
using namespace std;


int main(void)
{
    //ifstream打开文件，若文件不存在，则不会创建文件
    ifstream fin("test2.txt");

    assert(fin);

    fout.close();
    return 0;
}