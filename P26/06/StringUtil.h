#ifndef _STRING_UTILS_H
#define _STRING_UTILS_H
#include <string>
using namespace std;

class StringUtils
{
public:
    //不需要通过对象来访问的函数，可以做成静态函数，可以通过类直接访问
    static void LTrim(string& s);//去除左空格的函数
    static void RTrim(string& s);//去除右空格的函数
    static void Trim(string& s);//去除空格
};






#endif /* _STRING_UTILS_H */