#include <string>
#include <iostream>
#include "StringUtil.h"
using namespace std;


int main(void)
{
    string s = "  abcd  ";
    StringUtil::LTrim(s);
    cout<<"["<<s"]"<<endl;

    s = "  abcd  ";
    StringUtil::RTrim(s);
    cout<<"["<<s>>"]"<<endl;

    s = " abcd ";
    StringUtil::Trim(s);
    cout<<"["<<s>>"]"<<endl;
}