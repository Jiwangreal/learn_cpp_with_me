#ifndef _MAX_H_
#define _MAX_H_
#include <iostream>
using namespace std;

//模板的定义通常放在头文件中
//不要将模板的声明放在头文件中，实现放在cpp文件中，一般不要分开放
template < typename T>
const T &max(const T &a, const T &b)
{
    return a < b ? b : a;
}


// 函数模板重载
//参数不同，构成重载
template < typename T>
const T &max( const T &a,  const T &b,  const T &c)
{
    return ::max(a, b) < c ? c : ::max(a, b);
     // ::max表示调用的是全局的，而不是标准库的
}

// 非模板函数重载
//与模板const T &max(const T &a, const T &b)构成了重载
const  int &max( const  int &a,  const  int &b)
{
    cout <<  "non template function" << endl;
    cout<<"BBBBBBBBBBBBBBB"<<endl;
     return a < b ? b : a;
}

//函数模板特化
template <>
const  char * const &max( const  char * const &a,  const  char * const &b)
{
    //return a < b ? b : a;
    cout<<"AAAAAAAAAAAAA"<<endl;
    return strcmp(a, b) <  0 ? b : a;//比较的是内容，而不是指针本身
}

/*
模板特化与模板函数的区别：
模板特化本质上属于模板函数，非模板函数重载不算是模板函数，他是全局函数

*/
#endif  // _MAX_H_