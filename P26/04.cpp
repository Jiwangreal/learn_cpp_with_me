#include <string>
#include <iostream>
using namespace std;

void fun(char *str)
{
    cout<<str<<endl;
}

int main(void)
{
    string s1 = "abc";

    s1[1] = 'B';//����[]�����������ָ���ַ�������

    cout<<s1<<endl;

    //error, ���ܸ�������ֵ
    const string s2 = "xyz";
    //s2[1] = 'Y';//error s2[1]���ص���const char&

    //�ַ����ӷ����㣺ǰ2��������һ����string����
    string s3 = "111" + s1 + "222";
    cout<<s3<<endl;

    s3.c_str();//���Խ��ַ���stringת��Ϊconst char *

    //const_cast<char*>����ȥ��s3.c_str()�ĳ�����const������ת��Ϊchar *
    fun(const_cast<char*>(s3.c_str()));
    return 0;

}
