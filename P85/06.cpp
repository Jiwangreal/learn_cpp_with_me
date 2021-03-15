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
    //默认从小到大排列
    //与map区别是：key只有1个，按照key来进行映射的，存储在关键码上面
    // set<int> s;
    set<int, greater<in> > s;//降序排列
    s.insert(3);
    s.insert(1);
    s.insert(2);
    s.insert(3);

    for(set<int,greater<in> >::const_iterator it=s.begin(); it!=s.end();++it)
    // for(set<int>::const_iterator it=s.begin(); it!=s.end();++it)
    {
        cout<<*it<<' ';
    }
    cout<<endl;
    return 0;

}