#include <string>
#include <iostream>
using namespace std;


int main(void)
{
    string s1("abcdefdg");
    cout<<s1.size()<<endl;
    //�ȼ���
     cout<<s1.length()<<endl;

    cout<<s1.empty()<<endl;//�մ�����Ϊtrue

    cout<<s1.substr(1,2)<<endl;//�������s1
    cout<<s1.substr(1)<<endl;//�ȼ���cout<<s1.substr(1,-1)<<endl;-1��Ĭ�ϵģ�ʵ������string::npos
                            //cout<<s1.substr(1, string::npos)<<endl

    string::size_type pos = s1.find('A', 1);//��1��λ�ÿ�ʼ�ң����������0λ�ÿ�ʼ��
    if (pos == string::npos)
        cout<<"not found"<<endl;
    else
        cout<<"pos="<<pos<<endl;

    //�������
    pos = s1.rfind('A');//�ȼ���pos = s1.find('A', -1)
    if (pos == string::npos)
        cout<<"not found"<<endl;
    else
        cout<<"pos="<<pos<<endl;
    
    return 0;
}