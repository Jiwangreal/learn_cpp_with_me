#include <string>
#include <iostream>
using namespace std;

int main()
{
    string strinfo = " //*---Hello World!...------";
    string strset = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    //strinfo�е�H��strset�ַ����г��ֹ������ص�λ�þ���strinfo��H��λ��
    string::size_type fist = strinfo.find_first_of(strset);//��strinfo�ַ����У�������strset�г��ֹ����ַ��ĵ�һ��λ��

    //��һ������strset�е��ַ������ǿո�
    // string::size_type fist = strinfo.find_first_not_of(strset);

    if(first == string::npos)//����string::npos��ʾû���ҵ�
        cout<<"not find any characters"<<endl;

    //���һ������strset�е��ַ�������-
    // string::size_type last = strinfo.find_last_not_of(strset);

    string::size_type last = strinfo.find_last_of(strset);//���һ��d��strset���ֵ��ַ�
    if (last == string::npos)
        cout<<"not find any characters"<<endl;
    
    cout<<strinfo.substr(first, last-first+1)<<endl;//fisrt����H��last-first+1����d-H+1�����ȡ���ǣ�Hello World
    return 0;
}