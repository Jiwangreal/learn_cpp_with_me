#include <vector>
#include<list>
#include <iostream>

using namespace std;

int main(void)
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    vector<int>::iterator it;//���öϵ�
    for(it=v.begin(); it!=v.end();++it)
    {
        cout<<*it<<' ';
    }

    cout<<endl;
    vector<int>::reverse_iterator ri;
    for(ri=v.rbegin(); ri!=v.rend(); ++ri)
    {
        cout<<*ri<<' ';
    }
    cout<<endl;

    //˫������
    list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);

    list<int>::iterator it2;

    for(it2=l.begin(); it2!=l.end();++it2)
    {
        cout<<*it2<<' ';
    }
    
    return 0;
}