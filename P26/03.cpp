#include <string>
#include <iostream>
using namespace std;


int main(void)
{
    string s1("abcdefghijkl");
    s1.replace(2, 2, "AAAAAA");//会改变s1
    cout<<s1<<end;
    
    s1 = "abcdefg";
    s1.replace(s1.begin()+1, s1.end()+4, "AAAAAA");
    cout<<s1<<end;

    string s2 = "xyzabc";
    s2.insert(2, "MMMM");//插入到z的前面
    cout<<s2<<endl;

    s2.append("6666");
    cout<<s2<<endl;

    string s3 = "111";
    s3.replace(s2)；

    cout<<s2<<endl;
    cout<<s3<<endl;
    return 0;
}