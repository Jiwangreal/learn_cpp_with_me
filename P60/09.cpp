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

    // //�����д�뷽ʽ�ǲ��е�
    // //��Ϊÿ��д���ʱ�򣬲����ǽ��ַ���b��c����������д�뵽�ļ��У�����д����68�ֽڶ��ѣ�struct Test��4+32+32��
    // ofstream fout("test6.txt", ios::out|ios::binary);
    // fout.write((char*)&t1, sizeof(t1));
    // fout.close();

    // ifstream fin("test6.txt", ios::out|ios:binary);
    // Test t2;
    // fin.read((char*)&t2, sizeof(Test));
    // cout<<t2.a<<" "<<t2.b<<" "<<t2.c<<endl;
    // fin.close();

    // //string���͵Ĵ�С����32�ֽ�
    // //����һ�����ͻ���˵һ����������Ӧ����Ĵ�С�����ַ��������޹�
    // cout<<sizeof(Test)<<endl;
    // string a = "dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd";
    // cout<<sizeof(string)<<endl;
    // cout<<sizeof(a)<<endl;


    //��ȷ��д�뷽ʽ��һ��һ��д��
    ofstream fout("test6.txt", ios::out|ios::binary);
    //д���ַ�����ʱ�������д���ַ����ĳ��ȣ�Ȼ��д���ַ���ʵ������
    fout.write((char*)&t1.a, sizeof(int));
    int len;
    len = t1.b.length();
    fout.write((char*)&len, sizeof(int));
    fout.write((char*)&t1.b.data(), t1.b.length());

    len = t1.c.length();
    fout.write((char*)&len, sizeof(int));
    fout.write((char*)&t1.c.data(), t1.c.length());//data()ʵ���ϵ��õ���c_str()����
    fout.close();

   
    ifstream fin("test6.txt", ios::out|ios:binary);
    Test t2;
    fin.read((char*)&t2.a, sizeof(int));
    fin.read((char*)&len, sizeof(int)); //���ڶ����ַ����ĳ���
    t2.b.resize(len);
    fin.read((char*)&t2.b[0], len);
    fin.read((char*)&len, sizeof(int));
    t2.b.resize(len);
    fin.read((char*)&t2.c[0], len);


    cout<<t2.a<<" "<<t2.b<<" "<<t2.c<<endl;
    fin.close();

    return 0;
}