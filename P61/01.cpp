#include <iostream>
#include <sstream>

using namespace std;

int main(void)
{
    string line;
    string word;
    // cin.getline();//������char*��������string

    //ʹ��getline��������Ϊ����ȫ�ֵģ����Ա�׼���������ļ������ַ���������
    //����ֵ��cin����ȡ��������ʱ������ѭ��
    while (getline(cin, line))//��ȡһ�����ݵ�line
    {
        istringstream iss(line);//�����ַ�������������

        //�൱��C�е�sscanf
        //�ַ�����iss�������ַ���line
        //�൱�ڴ��ַ���line��ȡ���ݵ�word����
         while (iss >> word)//��ȡ���ݵ�word����һ���ж������
            cout << word <<  "#";
        cout << endl;
    }
     return  0;

}