#include <cassert>
#include <cassert>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Test
{
    int a;
    string b;//string����
    string c;
};

//MyString���С����4�ֽڣ����ַ���str�޹�
//ͬ��stringֻ�����Ա�йأ�������ĳ�Ա����һЩָ�룬��ͬƽ̨��һ������ǰƽ̨��32�ֽڣ�����ƽ̨������16�ֽڣ���Ϊ���е����ݳ�Ա��ͬ
class MyString
{
    char* str;
}

int main(void)
{
    Test t1;
    t1.a = 100;
    t1.b = "xxxabcdddddddddddddddddddddddddddddddddddddddddddddddffffffffffffffffffffffffff";
    t1.c = "yyyffffffffffffffffffffffffffffffffddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd";

    //�����д�뷽ʽ�ǲ��е�
    //��Ϊÿ��д���ʱ�򣬲����ǽ��ַ���b��c����������д�뵽�ļ��У�����д����68�ֽڶ��ѣ�struct Test��4+32+32��
    //ֻ��д��string�еĳ�Աָ��д��ȥ�ˣ���û�н�ָ����ָ����ڴ�д���ȥ
    ofstream fout("test6.txt", ios::out|ios::binary);
    fout.write((char*)&t1, sizeof(t1));
    fout.close();

    ifstream fin("test6.txt", ios::out|ios:binary);
    Test t2;
    fin.read((char*)&t2, sizeof(Test));
    cout<<t2.a<<" "<<t2.b<<" "<<t2.c<<endl;
    fin.close();

    //string���͵Ĵ�С����32�ֽ�
    //����һ�����ͻ���˵һ����������Ӧ����Ĵ�С�����ַ��������޹�
    cout<<sizeof(Test)<<endl;
    string a = "dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd";
    cout<<sizeof(string)<<endl;
    cout<<sizeof(a)<<endl;

    return 0;
}