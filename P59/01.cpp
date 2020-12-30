#include <iostream>
#include <fstream>
using namespace std;


int main(void)
{
    //定义一个文件输出流对象
    ofstream fout;

    //open的第二和第三参数都有默认值
    fout.open("test.txt");

    //判断打开是否成功或者失败
    //方法1：判断文件流缓冲区是否处于打开的状态
    if (fout.is_open())
    {
        cout<<"succ"<<endl;
    }
    else
    {
         cout<<"failed"<<endl;
    }
    
    //方法2：

    fout.close();
    return 0;
}