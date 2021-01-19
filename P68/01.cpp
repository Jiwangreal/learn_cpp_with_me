#include <iostream>
#include <string>
using  namespace std;

#include  "max.h"
// template < typename T>
// const T &max(const T &a, const T &b)
// {
//     return a < b ? b : a;
// }

//������󣬱�������ʵ��������һ��ģ�庯��
//���ɱ������Ƶ��ģ���deduction
// const int& max(const int &a, const int &b)
// {
//     return a < b ? b : a;
// }

// class Test
// {

// };

class Test
{
public:

    friend  bool  operator<(const Test &t1,  const Test &t2)
    {
        return  true;
    }
};

int main( void)
{
    //::max(5.5, 6.6)��ʾ���õ���ȫ�ֵ�max������������std�������ռ��max����
    cout <<::max( 5. 5,  6. 6) << endl;      // �Զ��Ƶ� max(const double&, const double&);
    cout <<::max( 'a',  'c') << endl;      // �Զ��Ƶ� max(const char&, const char&);


    Test t1;
    Test t2;
    ::max(t1, t2);  // Test::operator<(const Test& t1, const Test& t2)
                    //����error����ΪTest�����֧��<����
                    //������Ҫ����<�����

    const  char *str1 =  "aaa";
    const  char *str2 =  "zzz";
    cout <<::max(str1, str2) << endl; //����ѡ���ģ�庯��,���Ҳ������ſ���ģ�庯��

    out <<::max<>(str1, str2) << endl;  //ָ��ʹ��ģ�壬�����ҵ�ģ���ػ�

    cout <<::max( 1,  5,  3) << endl;  // ģ��ƥ�䣬�����Զ��Ƶ�

    cout <<::max( 'a',  100) << endl;  // 'a'��97;ѡ���ģ�庯����char������ʽת����int��

    cout <<::max( 97,  100) << endl;           // ����ѡ���ģ�庯��
                                        //�����ǵ���ģ���Ƶ����ĺ��������ǵ��õ������صķ�ģ�庯��

    cout <<::max<>( 97,  100) << endl;         //����ģ���Ƶ����ĺ���
    //<>��ʾ��ģ���Ƶ�

    cout <<::max< int>( 97,  100) << endl;  // ��ʽָ��ģ�庯��max(const int&, const int&)�������Զ��Ƶ�������ָ����
    cout <<::max< int>( 'a',  100) << endl;  // ��ʽָ��ģ�庯��max(const int&, const int&)
    return 0;
}
