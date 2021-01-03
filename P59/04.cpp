#include <cassert>
#include <iostream>
#include <fstream>
using namespace std;


int main(void)
{
    //���1
    //���ͬʱָ����out��app���������
    ofstream fout("test.txt", ios::out|ios::in|ios::app);

    //���2���ļ��ᱻ���
    ofstream fout("test.txt", ios::out|ios::ate);
    
    //�ļ����ᱻ���
    ofstream fout("test.txt", ios::out|ios::in|ios::ate);


    //���ļ���д��һЩ���ݣ���Ϊ���������������<<�����
    ofstream fout1("test3.txt", ios::in | ios::out | ios::ate);
    ofstream fout2("test3.txt", ios::in | ios::out | ios::ate);

    //׷�ӷ�ʽ1
    //������֣������Y
    //��һ���������������һ��X���ڶ���������������˸�Y
    //���Եڶ��ΰ�ǰ���X�������ˣ�����һ�����ļ����ļ�ָ��Ͷ�λ�����ļ�ĩβ
    //ate�Ǵ��ļ����������ļ���λ���ļ�β
    fout1 <<  "X";
    fout2 <<  "Y"; 

    //׷�ӷ�ʽ2
    //������֣������XY
    //��д���ʱ��λ��ĩβ���ȶ�λ��ĩβ��д��X�������ٶ�λ��ĩβ����д��Y
    //app����д֮ǰ��λ��ĩβ
    ofstream fout1("test3.txt", ios::in | ios::out | ios::app);
    ofstream fout2("test3.txt", ios::in | ios::out | ios::app);

    fout1 <<  "X";
    fout2 <<  "Y"; 

    fout1.close();
    fout2.close();
    
    // app �� trunc ���ܹ��棬��״̬Ϊfail
    ofstream fout3( "test.txt", ios::out | ios::app | ios::trunc);

    assert(fout3);//��ʧ��

     // app �� ate ���Թ��棬��appΪ׼
    ofstream fout1( "test3.txt", ios::in | ios::out | ios::app | ios::ate);
    ofstream fout2( "test3.txt", ios::in | ios::out | ios::app | ios::ate);

    assert(fout1);
    assert(fout2);

    fout1 <<  "X";
    fout2 <<  "Y";  //Y ����� X �ĺ���


    return 0;
}