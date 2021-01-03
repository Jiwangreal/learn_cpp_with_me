#include <cassert>
#include <iostream>
#include <fstream>
using namespace std;


int main(void)
{
     // app 与 trunc 不能共存，流状态为fail
    ofstream fout3( "test.txt", ios::out | ios::app | ios::trunc);
     if (fout3.good())
    {
        cout <<  "good" << endl;
    }
     if (fout3.bad())
    {
        cout <<  "bad" << endl;
    }
     if (fout3.fail())
    {
        cout <<  "fail" << endl;
    }
     if (fout3.eof())
    {
        cout <<  "eof" << endl;
    }

    //如果出现bad错误，流不能继续使用了
    //流状态出现错误，但是还想继续使用，需要clear
    fout3.clear();
    fout3.open( "test.txt");  // clear之后能够重新open
     if (fout3)
    {
        cout <<  "open succ" << endl;
    }
     else
        cout <<  "open failed" << endl;

    fout3.close();

    return 0;
}