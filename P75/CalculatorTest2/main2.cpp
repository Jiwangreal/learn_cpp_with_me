#include <iostream>
#include <memory>
#include <vector>

using namespace std;
#include "DebugNew.h"
#include "Node.h"
#include "ptr_vector.h"

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
    // vector<Test*> v;
    ptr_vector<Test> v;
    
    Test* t1 = new Test;
    Test* t2 = new Test;
    Test* t3 = new Test;

    //动态内存的所有权转移到了ptr_vector向量中，由向量来负责释放
    v.push_back(t1);
    v.push_back(t2);
    v.push_back(t3);        

    return 0;
}