#include <cassert>
#include <cassert>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(void)
{
    /*
    (1)������ı���ʽ���ļ���д���ַ���ʱ������\n����ת����д��\r����ת��
    windowsƽ̨\n��ת��Ϊ \r\n
    linuxƽ̨��������
    macϵͳ\nת��Ϊ\r    

    (2)����Զ����Ʒ�ʽ���ļ�д���ַ���ʱ������\n������ת��

    (3)���ı���ʽ���ļ���Ҳ����д�����������
    �Զ����Ʒ�ʽ���ļ���Ҳ����д���ı�
    д��������Ƕ����ƻ����ı�����򿪷�ʽ�޹أ���д��ʹ�õĺ����й�
    Ҫд����������ݣ�Ӧ����write����Ӧ�Ķ�Ҫ��read
    */
   //�Զ����Ʒ�ʽ��
    ofstream fout1( "test3.txt", ios::out| ios::binary );
    fout1<<"ABC\r\n";
    fout1.close();
    return 0;
}