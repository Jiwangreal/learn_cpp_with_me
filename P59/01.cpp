#include <cassert>
#include <iostream>
#include <fstream>
using namespace std;


int main(void)
{
    //定义一个文件输出流对象
    ofstream fout;

    //open的第二和第三参数都有默认值
    fout.open("test.txt");

    //这2行等价于下面的1行
    //ofstream fout;
    //fout.open("test.txt");
    ofstream fout("test.txt");//通过构造函数的方式打开

    //判断打开是否成功或者失败
    //方法1：判断文件流缓冲区是否处于打开的状态
    //ofstream文件流对象，子对象：filebuf
    if (fout.is_open())
    {
        cout<<"succ"<<endl;
    }
    else
    {
         cout<<"failed"<<endl;
    }
    
    //方法2：判断文件流状态是否处于正常状态
    //good方法判断流状态是否正常
    if (fout.good()) 
    {
        cout<<"succ"<<endl;
    }
    else
    {
        cout<<"failed"<<endl;
    }
    
    //方法3：对象作为条件
    //重载了类型转换运算符void *
    if (fout) 
    {
        cout<<"succ"<<endl;
    }
    else
    {
        cout<<"failed"<<endl;
    }

    //方法4，重载!的运算符
    if (!fout) 
    {
        cout<<"failed"<<endl;
    }
    else
    {
        cout<<"succ"<<endl;
    }

    //方法5，推荐使用断言的方式判断文件是否打开成功
    assert(fout);
    fout.close();
    return 0;
}