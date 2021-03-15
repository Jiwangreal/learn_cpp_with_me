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
    //multisetÔÊĞí¹Ø¼üÂë³åÍ»
    multiset<int, greater<in> > s;//½µĞòÅÅÁĞ
    s.insert(3);
    s.insert(1);
    s.insert(2);
    s.insert(3);

    for(multiset<int,greater<in> >::const_iterator it=s.begin(); it!=s.end();++it)
    // for(set<int>::const_iterator it=s.begin(); it!=s.end();++it)
    {
        cout<<*it<<' ';
    }
    cout<<endl;
    return 0;

}