#include <iostream>
#include <sstream>

using namespace std;


int main( void)
{
    //��192,168,0,100�ַ���ת��Ϊ192.168.0.100
    //sscanf�൱��������,sprintf�൱�������;

    //�ַ���������+�ַ��������
    //istringstream iss("192,168,0,100");
    //int v1;
    //int v2;
    //int v3;
    //int v4;
    //char ch;
    //iss>>v1>>ch>>v2>>ch>>v3>>ch>>v4;//192��ȡ��v1�����ţ���ȡ��ch�������Դ�����

    //ch = '.';
    //ostringstream oss;//�ڲ��ṹ�컺�������൱��sprintf
    //oss<<v1<<ch<<v2<<ch<<v3<<ch<<v4;
    //cout<<oss.str()<<endl;


    //�ַ������������
    string buf( "192,168,0,100");
    stringstream ss(buf);//stringstream ss("192,168,0,100");����û�л��������������������
    int v1;
    int v2;
    int v3;
    int v4;
    char ch;
    ss >> v1 >> ch >> v2 >> ch >> v3 >> ch >> v4;//�൱������������

    ch =  '.';
    stringstream ss2;
    ss2 << v1 << ch << v2 << ch << v3 << ch << v4;//�൱�����������

    cout << ss2.str() << endl;

    return  0;
}