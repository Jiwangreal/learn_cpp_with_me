#include <iostream>
#include <fstream>
using namespace std;


int main(void)
{
    //����һ���ļ����������
    ofstream fout;

    //open�ĵڶ��͵�����������Ĭ��ֵ
    fout.open("test.txt");

    //�жϴ��Ƿ�ɹ�����ʧ��
    //����1���ж��ļ����������Ƿ��ڴ򿪵�״̬
    if (fout.is_open())
    {
        cout<<"succ"<<endl;
    }
    else
    {
         cout<<"failed"<<endl;
    }
    
    //����2��

    fout.close();
    return 0;
}