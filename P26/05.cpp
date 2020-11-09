#include <string>
#include <iostream>
using namespace std;

int main()
{
    string strinfo = " //*---Hello World!...------";
    string strset = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    //strinfo中的H在strset字符串中出现过，返回的位置就是strinfo中H的位置
    string::size_type fist = strinfo.find_first_of(strset);//在strinfo字符串中，查找在strset中出现过的字符的第一个位置

    //第一个不在strset中的字符，就是空格
    // string::size_type fist = strinfo.find_first_not_of(strset);

    if(first == string::npos)//等于string::npos表示没有找到
        cout<<"not find any characters"<<endl;

    //最后一个不在strset中的字符，就是-
    // string::size_type last = strinfo.find_last_not_of(strset);

    string::size_type last = strinfo.find_last_of(strset);//最后一个d在strset出现的字符
    if (last == string::npos)
        cout<<"not find any characters"<<endl;
    
    cout<<strinfo.substr(first, last-first+1)<<endl;//fisrt就是H，last-first+1就是d-H+1，最后取得是：Hello World
    return 0;
}