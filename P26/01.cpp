#include <string>
#include <iostream>
using namespace std;


int main(void)
{
    //������ͨ���༴�ɣ�ʵ���ϻ���basic_stringģ���������¶����string����
    string s1;
    string s2("abcdefghijkl");
    cout<<s2<<endl;

    basic_string<char> s3("xxx");//�ȼ���string s3("xxx");
    cout<<s3<<endl;

    string s4("abcdefg", 4);//���ݽ�ȥ�����ĸ��ַ�
    cout<<s4<<endl;

    //������s2��2��λ�ÿ�ʼ���죬����3��
    string s5(s2, 2, 3);
    cout<<s5<<endl;

    //iterator��������ֱ�ӿ���char*�Ϳ�����
    string::iterator first = s2.begin() + 1; //��b��ʼ
    // string::iterator first = s2.begin() + 3; //���bc

    string::iterator last = s2.end();//��l����һ��
    string s6(first, last);//����ʵ���ǣ�[first, last)
    cout<<s6<<endl;

    return 0;
}
