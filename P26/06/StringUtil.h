#ifndef _STRING_UTILS_H
#define _STRING_UTILS_H
#include <string>
using namespace std;

class StringUtils
{
public:
    //����Ҫͨ�����������ʵĺ������������ɾ�̬����������ͨ����ֱ�ӷ���
    static void LTrim(string& s);//ȥ����ո�ĺ���
    static void RTrim(string& s);//ȥ���ҿո�ĺ���
    static void Trim(string& s);//ȥ���ո�
};






#endif /* _STRING_UTILS_H */