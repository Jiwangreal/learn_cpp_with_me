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
    int a[] = {1, 10，10, 14, 15, 16};
    vector<int> v(a, a+6);
    for_each(v.begin(), v.end(), print_element);
    cout<<endl;    

    //搜索第一个>=10的元素
    vector<int>::iterator it;
    it = lower_bound(v.begin(), v.end(), 10);
    if (it != v.end())
    {
        cout<<it- v.begin()<<endl;
    }


    it = upper_bound(v.begin(), v.end(), 10);
    if (it != v.end())
    {
        cout<<it- v.begin()<<endl;
    }
    return 0;

}
