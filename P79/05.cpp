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

int fun(int n)
{
    return 2 * a;
}

int fun2(int a, int b)
{
    return a + b;
}

int main(void)
{
    //容器在构造的时候可以不传递参数，也可以传递2个参数，容器中的区间都是是一个闭开区间[)
    //所有STL区间都是闭开区间
    //end应该指向5后面的位置，那么begin就指向1
    //a，a+5迭代器，这俩迭代器实现的方式是类，其内部持有了int*，所以本质上类型是int*
    int a[] = {1, 2, 3, 4, 5};
    vector<int> v(a, a+5);
    list<int> l(5);
    list<int> l2(2);

    //原区间不变，目标区间会变
    transform(v.begin(), v.end(), l.begin(), fun);
    for_each(l.begin(), l.end(), print_element);
    cout<<endl;

    //第一个区间元素：1，2
    //第二个区间元素：4，5
    transform(v.begin(), v.begin()+2 v.begin() + 3, l2.begin(), fun2);
    for_each(l.begin(), l.end(), print_element);
    cout<<endl;

    return 0;

}
