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
    vector<Test> v;
    Test t1;
    Test t2;
    Test t3;
    //��3��������ͷ�

    //�����е�3������Ҳ���ͷţ��ܹ�����6������
    v.push_back(t1);
    v.push_back(t2);
    v.push_back(t3);        

    return 0;
}