#include <iostream>
#include <functional>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>

using  namespace std;

int main( void)
{
    int a[]={3, 1, 2, 3, 4};
    vector<int> v(a, a+5);
    
    //把值=3的元素删除
    //error,it已经删除，何来++it呢？运行会报错
    //第一个遇到的元素是3，it指针指向他，删除他，导致it成为空悬指针，在对其++会出错，因为
    //他指向的元素都不在了
    // for(vector<int>::iterator it =v.begin(); it !=v.end();++it)
    // {
    //     if(*it == 3)
    //         v.erase(it);//
    //     else
    //         cout<<*it<<' ';
    // }
    // cout<<endl;

    //改进如下：
    for(vector<int>::iterator it =v.begin(); it !=v.end();)
    {
        if(*it == 3)
            it = v.erase(it);//返回的it是3的指向下一个元素，下一个it指向1
        else
        {
            cout<<*it<<' ';
            ++it;
        }
            
    }
    cout<<endl; 

    return 0;
}