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

    //getline���л�ȡ����ʹ�����հ��ַ���Ҳ����ȡ��buf��
    //����ȡ9���ַ�������1���ǻ��з�
    //getline�����ջ��з�
    // char buf[10] = {0};
    // cin.getline(buf, 10);
    // cout<<buf<<endl;

    // //��ȡ�����>>�����հ��ַ���ֹͣ
    // char buf[10] = {0};
    // cin>>buf;
    // cout<<buf<<endl;

    //read�Կհ��ַ��ն�����
    char buf[10] = {0};
    cin.read(buf, 5);
    cout<<buf<<endl;

    return 0;
}