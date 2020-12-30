#include <iostream>

using namespace std;

int main(void)
{
    // int n;
    // char ch;

    // cin>>n>>ch;
    // cout<<"n="<<n<<" "<<"ch="<<ch<<endl;

    int ch = cin.get();
    cout<<ch<<endl;

    char ch;
    cin.get(ch);
    cout<<ch<<endl;

    char ch1;
    char ch2;
    cin.get(ch1).get(ch2);
    cout<<ch1<<" "<<ch2<<endl;


    return 0;
}