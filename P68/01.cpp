#include <iostream>
#include <string>
using  namespace std;

#include  "max.h"
// template < typename T>
// const T &max(const T &a, const T &b)
// {
//     return a < b ? b : a;
// }

//编译完后，编译器会实例化这样一个模板函数
//是由编译器推导的，叫deduction
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
    //::max(5.5, 6.6)表示调用的是全局的max函数，而不是std中命名空间的max函数
    cout <<::max( 5. 5,  6. 6) << endl;      // 自动推导 max(const double&, const double&);
    cout <<::max( 'a',  'c') << endl;      // 自动推导 max(const char&, const char&);


    Test t1;
    Test t2;
    ::max(t1, t2);  // Test::operator<(const Test& t1, const Test& t2)
                    //编译error，因为Test类对象不支持<运算
                    //所以需要重载<运算符

    const  char *str1 =  "aaa";
    const  char *str2 =  "zzz";
    cout <<::max(str1, str2) << endl; //优先选择非模板函数,若找不到，才考虑模板函数

    out <<::max<>(str1, str2) << endl;  //指定使用模板，进而找到模板特化

    cout <<::max( 1,  5,  3) << endl;  // 模板匹配，进而自动推导

    cout <<::max( 'a',  100) << endl;  // 'a'即97;选择非模板函数（char可以隐式转换成int）

    cout <<::max( 97,  100) << endl;           // 优先选择非模板函数
                                        //并不是调用模板推导出的函数，而是调用的是重载的非模板函数

    cout <<::max<>( 97,  100) << endl;         //调用模板推导出的函数
    //<>表示让模板推导

    cout <<::max< int>( 97,  100) << endl;  // 显式指定模板函数max(const int&, const int&)，不是自动推导，而是指定的
    cout <<::max< int>( 'a',  100) << endl;  // 显式指定模板函数max(const int&, const int&)
    return 0;
}
