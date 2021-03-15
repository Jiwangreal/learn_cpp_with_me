#include <boost/shared_ptr.hpp>
#include <iostream>
using  namespace std;

class X
{
public:
    X()
    {
        cout <<  "X ..." << endl;
    }
    ~X()
    {
        cout <<  "~X ..." << endl;
    }
};

int main( void)
{
    cout <<  "Entering main ..." << endl;
    boost::shared_ptr<X> p1( new X);
    cout << p1.use_count() << endl;//输出引用计数
    boost::shared_ptr<X> p2 = p1;//用p1对象初始化p2对象，调用拷贝构造函数，相当于共享一个对象
     //boost::shared_ptr<X> p3;
     //p3 = p1;

    cout << p2.use_count() << endl;//其值等于p1.use_count()
    p1.reset();//表示置空，显式的将引用计数-1，也可以不用，等程序结束的时候会进行的，因为是智能指针是栈对象嘛
    cout << p2.use_count() << endl;
    p2.reset();
    cout <<  "Exiting main ..." << endl;
     return  0;
}
