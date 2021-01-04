#include <cassert>
#include <cassert>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Test
{
    int a;
    string b;//string对象
    string c;
};

//MyString类大小总是4字节，与字符串str无关
//同样string只与其成员有关，他里面的成员就是一些指针，不同平台不一样，当前平台是32字节，其他平台可能是16字节，因为持有的数据成员不同
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

    // //下面的写入方式是不行的
    // //因为每次写入的时候，并不是将字符串b和c的所有内容写入到文件中，总是写入了68字节而已（struct Test：4+32+32）
    // ofstream fout("test6.txt", ios::out|ios::binary);
    // fout.write((char*)&t1, sizeof(t1));
    // fout.close();

    // ifstream fin("test6.txt", ios::out|ios:binary);
    // Test t2;
    // fin.read((char*)&t2, sizeof(Test));
    // cout<<t2.a<<" "<<t2.b<<" "<<t2.c<<endl;
    // fin.close();

    // //string类型的大小总是32字节
    // //计算一个类型或者说一个类型所对应对象的大小，与字符串内容无关
    // cout<<sizeof(Test)<<endl;
    // string a = "dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd";
    // cout<<sizeof(string)<<endl;
    // cout<<sizeof(a)<<endl;


    //正确的写入方式：一个一个写入
    ofstream fout("test6.txt", ios::out|ios::binary);
    //写入字符串的时候，最好先写入字符串的长度，然后写入字符串实际数据
    fout.write((char*)&t1.a, sizeof(int));
    int len;
    len = t1.b.length();
    fout.write((char*)&len, sizeof(int));
    fout.write((char*)&t1.b.data(), t1.b.length());

    len = t1.c.length();
    fout.write((char*)&len, sizeof(int));
    fout.write((char*)&t1.c.data(), t1.c.length());//data()实际上调用的是c_str()方法
    fout.close();

   
    ifstream fin("test6.txt", ios::out|ios:binary);
    Test t2;
    fin.read((char*)&t2.a, sizeof(int));
    fin.read((char*)&len, sizeof(int)); //读第二个字符串的长度
    t2.b.resize(len);
    fin.read((char*)&t2.b[0], len);
    fin.read((char*)&len, sizeof(int));
    t2.b.resize(len);
    fin.read((char*)&t2.c[0], len);


    cout<<t2.a<<" "<<t2.b<<" "<<t2.c<<endl;
    fin.close();

    return 0;
}