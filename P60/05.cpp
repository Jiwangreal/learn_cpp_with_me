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

//测试：以文本方式打开文件，也可以写入二进制数据
//写入的数据是二进制还是文本，与打开方式无关，与写入使用的函数有关
int main(void)
{
    Test test = {100, 200};
    //以文本方式打开
    ofstream fout("test4.txt");
    //以二进制方式写入8个字节（将100在机器中的内存表示写入文件中），转化成char*
    fout.write(reinterpret_cast<char*>(&test), sizeof(Test));
    fout.close();

    //如何知道写入成功？可以读取出来
    Test test2;
    ifstream fin("test4.txt");
    fin.read(reinterpret_cast<char*>(&test2), sizeof(Test));
    cout<<test2.a<<" "<<test2.b<<endl;

    return 0;
}