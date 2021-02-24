#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

void print_element(int n)
{
    cout <<n<<' ';
}

void add_3(int& n)
{
    n += 3;
}

int main(void)
{
    //容器在构造的时候可以不传递参数，也可以传递2个参数，容器中的区间都是是一个闭开区间[)
    //所有STL区间都是闭开区间
    //end应该指向5后面的位置，那么begin就指向1
    //a，a+5迭代器，这俩迭代器实现的方式是类，其内部持有了int*，所以本质上类型是int*
    int a[] = {1, 2, 3, 4, 5};
    vector<int> v(a, a+5);
    list<int> l(10);//list<int> l;错误，copy要求目标的空间已经存在

    //使用算法
    for_each(v.begin(), v.end(), print_element);
    cout<<endl;

    //for_each是变动性还是非变动性算法，取决于第3个参数：是否更改容器中的元素
    for_each(v.begin(), v.end(), add_3);

    for_each(v.begin(), v.end(), print_element);
    cout<<endl;

    for_each(l.begin(), l.end(), print_element);
    cout<<endl;

    //copy要求目标的空间已经存在
    copy(v.begin(),v.end(), l.begin());
    for_each(l.begin(), l.end(), print_element);
    cout<<endl;

    copy_backward(v.begin(),v.end(), l.end());
    for_each(l.begin(), l.end(), print_element);
    cout<<endl;

    return 0;

}
