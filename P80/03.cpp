#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print_element(int n)
{
    cout <<n<<' ';
}

int main(void)
{
    //容器在构造的时候可以不传递参数，也可以传递2个参数，容器中的区间都是是一个闭开区间[)
    //所有STL区间都是闭开区间
    //end应该指向5后面的位置，那么begin就指向1
    //a，a+5迭代器，这俩迭代器实现的方式是类，其内部持有了int*，所以本质上类型是int*
    int a[] = {1, 2， 3, 4, 5, 6};
    vector<int> v(a, a+6);
    
    for_each(v.begin(), v.end(), print_element);
    cout<<endl;

    //将1，2元素反转到末尾
    rotate(v.begin(), v.begin()+2, v.end());
    // rotate(v.begin(), v.begin()+2, v.end() - 1);支持，vector内部的迭代器是随机迭代器
    for_each(v.begin(), v.end(), print_element);
    cout<<endl;

    /*
    list<int> l;
    l.end() - 1;不能这么做的原因是：list用链表实现，不支持随机访问，list的迭代器
    不是随机迭代器，是一个双向迭代器，不支持+，- += -=运算，但是支持++，--运算
    */

    return 0;

}
