#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print_element(int n)
{
    cout <<n<<' ';
}

bool my_greater(int a, int b)
{
    return a > b;
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
    rotate(v.begin(), v.begin()+2, v.end()-1);
    for_each(v.begin(), v.end(), print_element);
    cout<<endl;

    //sort，2个参数默认是从小到大排序的
    sort(v.begin(), v.begin());
    for_each(v.begin(), v.end(), print_element);
    cout<<endl;

    //从大到小排序
    sort(v.begin(), v.begin()，my_greater);
    for_each(v.begin(), v.end(), print_element);
    cout<<endl;
    return 0;

}
