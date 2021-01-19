#ifndef _MAX_H_
#define _MAX_H_
#include <iostream>
using namespace std;

//ģ��Ķ���ͨ������ͷ�ļ���
//��Ҫ��ģ�����������ͷ�ļ��У�ʵ�ַ���cpp�ļ��У�һ�㲻Ҫ�ֿ���
template < typename T>
const T &max(const T &a, const T &b)
{
    return a < b ? b : a;
}


// ����ģ������
//������ͬ����������
template < typename T>
const T &max( const T &a,  const T &b,  const T &c)
{
    return ::max(a, b) < c ? c : ::max(a, b);
     // ::max��ʾ���õ���ȫ�ֵģ������Ǳ�׼���
}

// ��ģ�庯������
//��ģ��const T &max(const T &a, const T &b)����������
const  int &max( const  int &a,  const  int &b)
{
    cout <<  "non template function" << endl;
    cout<<"BBBBBBBBBBBBBBB"<<endl;
     return a < b ? b : a;
}

//����ģ���ػ�
template <>
const  char * const &max( const  char * const &a,  const  char * const &b)
{
    //return a < b ? b : a;
    cout<<"AAAAAAAAAAAAA"<<endl;
    return strcmp(a, b) <  0 ? b : a;//�Ƚϵ������ݣ�������ָ�뱾��
}

/*
ģ���ػ���ģ�庯��������
ģ���ػ�����������ģ�庯������ģ�庯�����ز�����ģ�庯��������ȫ�ֺ���

*/
#endif  // _MAX_H_