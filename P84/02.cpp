#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using  namespace std;

void ShowList( const list< int> &v)
{
     for (list< int>::const_iterator it = v.begin(); it != v.end(); ++it)
    {
        cout << *it <<  ' ';
    }
    cout << endl;
}

int main( void)
{
     int a[] = { 1,  2,  3,  4,  5};
    list< int> l(a, a +  5);
    list< int> ll;

    front_insert_iterator<list< int> > fii(l);
    fii =  0;
    ShowList(l);

    copy(l.begin(), l.end(), front_inserter(ll));
    ShowList(ll);
    return  0;
}