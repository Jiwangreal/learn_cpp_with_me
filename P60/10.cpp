#include <cassert>
#include <cassert>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(void)
{
    ifstream fin("test7.txt");//�ļ����������ᴴ���ļ�
    //����ļ������ڣ��򿪻�ʧ��
    assert(fin);
    fin.seekg(2);//��λ���ַ�c

    char ch;
    fin.get(ch);
    cout<<ch<<endl;

    //������һ���ַ�
    //��λ���ļ���β������ǰ-1

    //�ļ���ָ��ָ����ĩβ�ĵط�
    fin.seekg(-1, ios::end);
    fin.get(ch);
    cout<<ch<<endl;

    //�����·������Ի�ȡ�ļ��Ĵ�С
    //��ȡ�ļ���ָ���λ��
    //0�ǽ�������λ��
    fin.seekg(0, ios::end);
    streampos pos = fin.tellg();
    cout<<pos<<endl;

    return 0;
}