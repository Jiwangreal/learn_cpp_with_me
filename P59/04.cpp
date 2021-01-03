#include <cassert>
#include <iostream>
#include <fstream>
using namespace std;


int main(void)
{
    //差别1
    //如果同时指定了out与app，不会清空
    ofstream fout("test.txt", ios::out|ios::in|ios::app);

    //差别2，文件会被清空
    ofstream fout("test.txt", ios::out|ios::ate);
    
    //文件不会被清空
    ofstream fout("test.txt", ios::out|ios::in|ios::ate);


    //往文件里写入一些数据，因为输出流对象重载了<<运算符
    ofstream fout1("test3.txt", ios::in | ios::out | ios::ate);
    ofstream fout2("test3.txt", ios::in | ios::out | ios::ate);

    //追加方式1
    //结果发现：输出了Y
    //第一个输出流对象填了一个X，第二个输出流对象填了个Y
    //所以第二次把前面的X给覆盖了，即：一旦打开文件，文件指针就定位到了文件末尾
    //ate是打开文件后，立即将文件定位在文件尾
    fout1 <<  "X";
    fout2 <<  "Y"; 

    //追加方式2
    //结果发现，输出了XY
    //在写入的时候定位到末尾，先定位到末尾，写入X，接着再定位到末尾，再写入Y
    //app是在写之前定位到末尾
    ofstream fout1("test3.txt", ios::in | ios::out | ios::app);
    ofstream fout2("test3.txt", ios::in | ios::out | ios::app);

    fout1 <<  "X";
    fout2 <<  "Y"; 

    fout1.close();
    fout2.close();
    
    // app 与 trunc 不能共存，流状态为fail
    ofstream fout3( "test.txt", ios::out | ios::app | ios::trunc);

    assert(fout3);//会失败

     // app 和 ate 可以共存，以app为准
    ofstream fout1( "test3.txt", ios::in | ios::out | ios::app | ios::ate);
    ofstream fout2( "test3.txt", ios::in | ios::out | ios::app | ios::ate);

    assert(fout1);
    assert(fout2);

    fout1 <<  "X";
    fout2 <<  "Y";  //Y 输出在 X 的后面


    return 0;
}