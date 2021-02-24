#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

void print_element(int n)
{
    cout <<n<<' ';
}

bool func(int n)
{
    return n < 10；
}

int main(void)
{
    //容器在构造的时候可以不传递参数，也可以传递2个参数，容器中的区间都是是一个闭开区间[)
    //所有STL区间都是闭开区间
    //end应该指向5后面的位置，那么begin就指向1
    //a，a+5迭代器，这俩迭代器实现的方式是类，其内部持有了int*，所以本质上类型是int*
    int a[] = {1, 2, 3, 4, 3};
    vector<int> v(a, a+5);
    list<int> l(5);

    //把元素为3的替换成13
    replace(v.begin(), v.end(), 3, 13);

    for_each(v.begin(), v.end(), print_element);
    cout<<endl;

    //replace_copy原区间不改，目标区间会更改
    replace_copy(v.begin(), v.end(), l.begin(), 13, 3);
    for_each(v.begin(), v.end(), print_element);
    cout<<endl;
    
    for_each(l.begin(), l.end(), print_element);
    cout<<endl;

    //拷贝的过程中根据某个条件来替换
    //<10的元素都替换为0
    replace_copy_if(v.begin(), v.end(), l.begin(), func, 0);
    for_each(l.begin(), l.end(), print_element);
    cout<<endl;

    return 0;

}
