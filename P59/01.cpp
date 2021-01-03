#include <cassert>
#include <iostream>
#include <fstream>
using namespace std;


int main(void)
{
    //����һ���ļ����������
    ofstream fout;

    //open�ĵڶ��͵�����������Ĭ��ֵ
    fout.open("test.txt");

    //��2�еȼ��������1��
    //ofstream fout;
    //fout.open("test.txt");
    ofstream fout("test.txt");//ͨ�����캯���ķ�ʽ��

    //�жϴ��Ƿ�ɹ�����ʧ��
    //����1���ж��ļ����������Ƿ��ڴ򿪵�״̬
    //ofstream�ļ��������Ӷ���filebuf
    if (fout.is_open())
    {
        cout<<"succ"<<endl;
    }
    else
    {
         cout<<"failed"<<endl;
    }
    
    //����2���ж��ļ���״̬�Ƿ�������״̬
    //good�����ж���״̬�Ƿ�����
    if (fout.good()) 
    {
        cout<<"succ"<<endl;
    }
    else
    {
        cout<<"failed"<<endl;
    }
    
    //����3��������Ϊ����
    //����������ת�������void *
    if (fout) 
    {
        cout<<"succ"<<endl;
    }
    else
    {
        cout<<"failed"<<endl;
    }

    //����4������!�������
    if (!fout) 
    {
        cout<<"failed"<<endl;
    }
    else
    {
        cout<<"succ"<<endl;
    }

    //����5���Ƽ�ʹ�ö��Եķ�ʽ�ж��ļ��Ƿ�򿪳ɹ�
    assert(fout);
    fout.close();
    return 0;
}