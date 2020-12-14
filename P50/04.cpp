#include <iostream>
using namespace std;

class Test
{
public:
    Test();
    {
        cout<<"Test ..."<<endl;
    }
    Test(const Test& other)
    {
        cout<<"Copy Test ..."<<endl;
    }
    ~Test()
    {
        cout<<"Test"<<endl;
    }
};

Test fun()
{
    //局部对象的构造与销毁
    //首先调用构造函数，然后调用析构函数将对象释放掉
    Test t;
    return t;//然后调用拷贝构造函数构造一个对象，然后调用析构函数生命周期结束了
}

int main(void)
{
    fun();//返回的对象没有人能接收就立刻销毁了
    cout<<"......"<<endl;
    return 0;
}