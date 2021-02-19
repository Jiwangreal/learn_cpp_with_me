#include <vector>
#include <iostream>

using namespace std;

int main(void)
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    vector<int>::iterator it;//…Ë÷√∂œµ„
    for(it=v.begin(); it!=v.end();++it)
    {
        cout<<*it<<' ';
    }

    cout<<endl;

    return 0;
}