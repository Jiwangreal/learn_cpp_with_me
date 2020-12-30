#include <iostream>

using namespace std;

int main(void)
{
    // int n;
    // char ch;

    // cin>>n>>ch;
    // cout<<"n="<<n<<" "<<"ch="<<ch<<endl;

    // int ch = cin.get();
    // cout<<ch<<endl;

    // char ch;
    // cin.get(ch);
    // cout<<ch<<endl;

    // char ch1;
    // char ch2;
    // cin.get(ch1).get(ch2);
    // cout<<ch1<<" "<<ch2<<endl;

    //getline按行获取，即使遇到空白字符，也会提取到buf中
    //最多获取9个字符，还有1个是换行符
    //getline不接收换行符
    // char buf[10] = {0};
    // cin.getline(buf, 10);
    // cout<<buf<<endl;

    // //提取运算符>>遇到空白字符就停止
    // char buf[10] = {0};
    // cin>>buf;
    // cout<<buf<<endl;

    //read对空白字符照读不误
    char buf[10] = {0};
    cin.read(buf, 5);
    cout<<buf<<endl;

    return 0;
}