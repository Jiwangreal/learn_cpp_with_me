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

int main(void)
{
    Test test = {100, 200};
    //以二进制方式打开
    //ios::binary仅仅影响\n字符的转化，但是最好加上
    ofstream fout("test4.txt", ios::out|ios::binary);
    //以二进制方式写入8个字节（将100在机器中的内存表示写入文件中），转化成char*
    fout.write(reinterpret_cast<char*>(&test), sizeof(Test));
    fout.close();

    //如何知道写入成功？可以读取出来
    Test test2;
    ifstream fin("test4.txt", ios::in|ios::binary);
    fin.read(reinterpret_cast<char*>(&test2), sizeof(Test));
    cout<<test2.a<<" "<<test2.b<<endl;

    return 0;
}