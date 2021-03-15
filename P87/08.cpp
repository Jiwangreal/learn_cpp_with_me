#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/scoped_array.hpp>
#include <boost/scoped_ptr.hpp>
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

     void Fun()
    {
        cout <<  "Fun ..." << endl;
    }
};
int main( void)
{
    //weak_ptr通常要与shared_ptr配合使用
    boost::weak_ptr<X> p;//定义一个若指针对象引用
    {
        boost::shared_ptr<X> p2( new X);
        cout << p2.use_count() << endl;//=1
        p = p2;
        cout << p2.use_count() << endl;//p2是强引用，引用计数=1


    //要访问X中的数据成员，首先要将弱引用p提升为shared_ptr
    //弱引用没有重载->指针运算符，强引用有的
        boost::shared_ptr<X> p3 = p.lock();
        if (!p3)
            cout<<"object is destroyed"<<endl;//p.lock()看下能否提升，lock()表示提升，也表示锁定对象，防止被销毁
        else
            p3->Fun();
    }
    //p2引用的对象会被销毁，因为引用计数=1

     boost::shared_ptr<X> p4 = p.lock();
    if (!p4)
        cout<<"object is destroyed"<<endl;
    else
        p4->Fun();

     return  0;
}