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

    //��һ���ļ���д��26����ĸ
    for ( int i =  0; i <  26; i++)
    {
        ch =  'A' + i;
        fout1.put(ch);
    }
    fout1.close();

    ifstream fin1( "test2.txt");
    //��ȡ�ļ�������ʱ���ļ�������EOF״̬������ת��ָ��void*ָ��᷵�ؿ�ָ�룬������ѭ����
     while (fin1.get(ch))
    {
        cout << ch;
    }
    cout << endl;


    return 0;
}