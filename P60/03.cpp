#include <cassert>
#include <cassert>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(void)
{
    /*
    ������ı���ʽ���ļ���д���ַ���ʱ������\n����ת����д��\r����ת��
    ����Զ����Ʒ�ʽ���ļ�д���ַ���ʱ������\n������ת��

    windowsƽ̨\n��ת��Ϊ \r\n
    linuxƽ̨��������
    macϵͳ\nת��Ϊ\r    
    */
    //Ĭ�����ı���ʽ���ļ�
    ofstream fout1( "test3.txt");
    fout1<<"ABC\r\n";
    fout1.close();
    return 0;
}