#include "StringUtil.h"

void StringUtil::LTrim(string& s)
{
    //erase函数：第一个参数：要去除字符的位置，第二个参数：表示要去除字符的个数，这个个数就是位置
    string drop = " \t";//空格或者/t
    s.erase(0, s.find_first_not_od(drop));//从0到第一个不是空格字符，它前面的空格数，将其清除掉，范围好像是[,)
}

void StringUtil::RTrim(string& s)
{
    string drop = " \t";
    s.erase(s.find_last_not_of(drop) + 1, -1);//最后一个不是空格的位置+1，就是空格的位置，一直到末尾
}

void StringUtil::Trim(string& s)
{
    LTrim(s);
    RTrim(s);
}