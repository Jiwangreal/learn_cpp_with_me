#include <cassert>
#include <iostream>
#include <fstream>
using namespace std;


int main(void)
{
     // app �� trunc ���ܹ��棬��״̬Ϊfail
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

    //�������bad���������ܼ���ʹ����
    //��״̬���ִ��󣬵��ǻ������ʹ�ã���Ҫclear
    fout3.clear();
    fout3.open( "test.txt");  // clear֮���ܹ�����open
     if (fout3)
    {
        cout <<  "open succ" << endl;
    }
     else
        cout <<  "open failed" << endl;

    fout3.close();

    return 0;
}