#include <iostream>
#include <algorithm>
#include <vector>

void print_element(int n)
{
    cout <<n<<' ';
}

int main(void)
{
    int a[] = {1,2,3,4};
    vector<int> v(a,a+4);
    for_each(v.begin(), v.end(), print_element);
    cout <<endl;

    //±àÐòÐÍËã·¨
    while (next_premutation(v.begin(), v.end()))
    {
        for_each(v.begin(), v.end(), print_element);
        cout<<endl;

    }
    
}

