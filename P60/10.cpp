#include <cassert>
#include <cassert>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(void)
{
    ifstream fin("test7.txt");//文件输入流不会创建文件
    //如果文件不存在，打开会失败
    assert(fin);
    fin.seekg(2);//定位到字符c

    char ch;
    fin.get(ch);
    cout<<ch<<endl;

    //输出最后一个字符
    //定位到文件结尾处，向前-1

    //文件流指针指向了末尾的地方
    fin.seekg(-1, ios::end);
    fin.get(ch);
    cout<<ch<<endl;

    //用以下方法可以获取文件的大小
    //获取文件流指针的位置
    //0是结束符的位置
    fin.seekg(0, ios::end);
    streampos pos = fin.tellg();
    cout<<pos<<endl;

    return 0;
}