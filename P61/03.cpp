#include <iostream>
#include <sstream>

using namespace std;


int main( void)
{
    //将192,168,0,100字符串转化为192.168.0.100
    //sscanf相当于输入流,sprintf相当于输出流;

    //字符串输入流+字符串输出流
    //istringstream iss("192,168,0,100");
    //int v1;
    //int v2;
    //int v3;
    //int v4;
    //char ch;
    //iss>>v1>>ch>>v2>>ch>>v3>>ch>>v4;//192提取到v1，逗号，提取到ch。。。以此类推

    //ch = '.';
    //ostringstream oss;//内部会构造缓冲区，相当于sprintf
    //oss<<v1<<ch<<v2<<ch<<v3<<ch<<v4;
    //cout<<oss.str()<<endl;


    //字符串输入输出流
    string buf( "192,168,0,100");
    stringstream ss(buf);//stringstream ss("192,168,0,100");这是没有缓冲区的输入输出流对象
    int v1;
    int v2;
    int v3;
    int v4;
    char ch;
    ss >> v1 >> ch >> v2 >> ch >> v3 >> ch >> v4;//相当于输入流对象

    ch =  '.';
    stringstream ss2;
    ss2 << v1 << ch << v2 << ch << v3 << ch << v4;//相当于输出流对象

    cout << ss2.str() << endl;

    return  0;
}