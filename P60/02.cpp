#include <cassert>
#include <cassert>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(void)
{
    ofstream fout1( "test2.txt");
    assert(fout1);
    char ch;

    //往一个文件中写入26个字母
    for ( int i =  0; i <  26; i++)
    {
        ch =  'A' + i;
        fout1.put(ch);
    }
    fout1.close();

    ifstream fin1( "test2.txt");
    //读取文件到结束时，文件流处于EOF状态，类型转换指针void*指针会返回空指针，就跳出循环了
     while (fin1.get(ch))
    {
        cout << ch;
    }
    cout << endl;


    return 0;
}