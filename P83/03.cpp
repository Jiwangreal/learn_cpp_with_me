
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
bool is_odd(int n)
{
    return n % 2 == 1;
}

int main(void)
{
    int a[] = {1,2,3,4,5};
    vector<int> v(a, a+5);

    //算法可以适用于容器的
    //统计向量中奇数的个数
    count<<count_if(v.begin(), v.end, is_odd)<<endl;


    //计算奇数元素的个数
    //这里的bind2nd将二元函数对象modulus转换为一元函数对象。
    //modulus本来的参数接收2个参数：m%n，
    //bind2nd只需要接受一个参数了，因为他绑定了第2个参数，m%2，此时一元函数对象有状态了，保存的是2的状态
    //而m的参数从v.begin(),v.end()中来
    //bind2nd(op,value)(param)相当于op(param,value)
    //bind2nd(二元函数对象，是要绑定的值)，返回一元函数对象，返回一个参数param
    //param是v.begin(),v.end(),遍历过程中，将值传递到param里面的

    //bind2nd是一个函数模板
    cout<<count_if(v.begin(),v.end(),
    bind2nd(modulus< int>(), 2))<<endl;


    //这里的bind1st将二元函数对象modulus转换为一元函数对象。
    //二元函数对象less<int>()表示m < n,
    //bind1st表示绑定的是第一个参数，，即：2<n，n的值是遍历的时候传进来
        //bind1st(op,  value)(param)相当于op(value,  param);
        cout  <<  count_if(v.begin(),  v.end(),
                bind1st(less< int>(),   4))  <<  endl;//>4的元素个数有几个

    return 0;
}





