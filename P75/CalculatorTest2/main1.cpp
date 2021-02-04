#include <iostream>
#include <memory>
#include <vector>

using namespace std;
#include "DebugNew.h"
#include "Node.h"

class Test
{
public:
    Test()
    {
        cout<<"Test ..."<<endl;
    }
    Test(const Test& other)
    {
        cout <<"Copy Test ..."<<endl;
    }
    ~Test()
    {
        cout <<"~Test() ..."<<endl;
    }
};



int main(void)
{
    vector<Test*> v;
    Test* t1 = new Test;
    Test* t2 = new Test;
    Test* t3 = new Test;

    v.push_back(t1);
    v.push_back(t2);
    v.push_back(t3);        

    return 0;
}