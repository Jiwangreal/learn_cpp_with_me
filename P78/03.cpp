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
    int a[] = {1, 2, 3, 4, 5};
    vector<int> v(a, a+5);
    vector<int>::iterator it;
    for (it = v.begin(); it != v.end(); ++it)
        cout<<*it<<' ';
    cout<<endl;

    //使用算法
    for_each(v.begin(), v.end(), print_element);
    cout<<endl;

    for(it = v.begin(); it != v.end(); ++it)
        cout<<*it<<' ';
    cout<<endl;

    //min_element是全局函数，在区间范围内求最小元素的位置
    it = min_element(v.begin(),v.end());
    //如果区间为空，可能找不到，所以要判定
    if (it != v.end())
    {
        cout << *it <<endl;
    }
    
    it = max_element(v.begin(),v.end());
    if (it != v.end())
    {
        cout << *it <<endl;
    }

    //查找3这个元素所在的位置
    //输出相对位置
    it = find(iv.begin(), v.end(), 3);
    if (it != v.end())
        cout <<it-v.begin()<<endl;
    else
        cout<<"not found"<<endl;

    return 0;


}
