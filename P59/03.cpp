#include <cassert>
#include <iostream>
#include <fstream>
using namespace std;


int main(void)
{
    //�ļ������ofstreamĬ�ϴ�ģʽ��ios::out��û��ָ�κ�ģʽʱ��
    //������ifstreamĬ�ϴ�ģʽ��ios::in
    ofstream fout("test.txt", ios::out);//�ȼ���ָ����ios::out|ios::truncģʽ

    //���ļ�ͬʱ��in��out��ʱ�������
    ofstream fout("test.txt", ios::out|ios::in);

    //������ļ�ʱָ����truncģʽ���������Ƿ�ͬʱָ����inģʽ���ļ�ͬ���ᱻ���
    ofstream fout("test.txt", ios::out|ios::in|ios::trunc);

    //���ͬʱָ����out��app���������
    ofstream fout("test.txt", ios::out|ios::in|ios::app);

    assert(fin);

    fout.close();
    return 0;
}