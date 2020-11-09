#include <string>
#include <iostream>
using namespace std;


int main(void)
{
    string s1("abcdefdg");
    cout<<s1.size()<<endl;
    //等价于
     cout<<s1.length()<<endl;

    cout<<s1.empty()<<endl;//空串返回为true

    cout<<s1.substr(1,2)<<endl;//不会更改s1
    cout<<s1.substr(1)<<endl;//等价于cout<<s1.substr(1,-1)<<endl;-1是默认的，实际上是string::npos
                            //cout<<s1.substr(1, string::npos)<<endl

    string::size_type pos = s1.find('A', 1);//从1的位置开始找，若不填则从0位置开始找
    if (pos == string::npos)
        cout<<"not found"<<endl;
    else
        cout<<"pos="<<pos<<endl;

    //反向查找
    pos = s1.rfind('A');//等价于pos = s1.find('A', -1)
    if (pos == string::npos)
        cout<<"not found"<<endl;
    else
        cout<<"pos="<<pos<<endl;
    
    return 0;
}