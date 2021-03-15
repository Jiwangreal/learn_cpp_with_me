#include  <iostream>
#include  <algorithm>
#include  <functional>
#include  <vector>
#include  <string>

using   namespace  std;

bool  check( int  elem)
{
         return  elem  <   3;
}

int  main( void)
{
    int  a[]  =  { 1,   2,   3,   4,   5};
    vector< int>  v(a,  a  +   5);

    vector< int>::iterator  it;
    // not1中的no说明是>=3，取反
    // not1也是一个一元函数对象
    it  =  find_if(v.begin(),  v.end(),  not1(ptr_fun(check)));//返回第一个>=3的元素

    //不能这么写的原因是：因为类型不匹配，  not1需要有argument_type，而check函数没有
    //ptr_fun是一个函数适配器，将普通函数转换成一元函数对象，这样与not1的接口能匹配了
    // it  =  find_if(v.begin(),  v.end(),  not1(check);
         if  (it  !=  v.end())
                cout  <<  *it  <<  endl;
         return   0;
}
