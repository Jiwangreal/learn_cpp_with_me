#include "StringUtil.h"

void StringUtil::LTrim(string& s)
{
    //erase��������һ��������Ҫȥ���ַ���λ�ã��ڶ�����������ʾҪȥ���ַ��ĸ����������������λ��
    string drop = " \t";//�ո����/t
    s.erase(0, s.find_first_not_od(drop));//��0����һ�����ǿո��ַ�����ǰ��Ŀո������������������Χ������[,)
}

void StringUtil::RTrim(string& s)
{
    string drop = " \t";
    s.erase(s.find_last_not_of(drop) + 1, -1);//���һ�����ǿո��λ��+1�����ǿո��λ�ã�һֱ��ĩβ
}

void StringUtil::Trim(string& s)
{
    LTrim(s);
    RTrim(s);
}