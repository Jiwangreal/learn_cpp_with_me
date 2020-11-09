#include <isotream>
using namespace std;

//const_cast用来移除常量性
//const_cast一般来说，用于指针或者引用
//const_cast去除常量性目的：不是为了修改它的内容
//const_cast去除常量性是为了函数能接受实参

void fun(int& val)
{
    cout<<"fun"<<val<<endl;
}

int main(void)
{
    const int val=100;
    // int n=const_cast<int>(&val);//n和val没啥关系，也就是没啥意义，所以会报错
    int n=val;

    // int *p=&val;error,无法从const int*转换为int*
    int *p=const_cast<int *>(&val);//去掉了常量性
    *p=200;//改变的是临时空间的内容

    
    cout<<&val<<endl;//输出地址一样
    cout<<p<<endl;//输出地址一样，更就说明：使用const_cast去除const限定的目的不是为了修改它的内容
    count<<"val="<<val<<endl;//就算为变量重新赋值了，输出还为100

    const int val2=200;
    // int & refval2=val2;//非const引用不能指向const变量
    int& refval2=const_cast<int &>(val2);

    refval2=300;
    
    fun(const_cast<int&>(val2));//输出：fun 300，输出的是临时对象的值，要知道反正不会改变val2的值！！！

    cout<<"val2="<<val2<<endl;//输出为200，对引用所作的改动，不会影响原来的常量
    return 0;    
}







