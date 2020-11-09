#include <iostream>
using namespace std;

class Base 
{
public:
    static int b_;
};
int Base::b_ = 100;
class Derived : public Base
{

};


int main()
{
    Base b;
    Base d;
    cout<<Base::b_<<endl;//推荐使用的方法，因为静态成员无所谓继承，因为它只有1份拷贝
    //不推荐下面的这种写法
    cout<<b.b_<<endl;

    cout<<Derived::b_<<endl;
    cout<<d.b_<<endl;
    return 0;
}