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
    boost::shared_ptr<X> p3;
    {
        boost::shared_ptr<X> p2( new X);
        cout << p2.use_count() << endl;//=1
        p = p2;
        cout << p2.use_count() << endl;//p2是强引用，引用计数=1

         /*boost::shared_ptr<X> */
        p3 = p.lock();
        cout << p3.use_count() << endl;
         if (!p3)
            cout <<  "object is destroyed" << endl;
         else
            p3->Fun();
    }
     /*boost::shared_ptr<X> p4 = p.lock();
    if (!p4)
        cout<<"object is destroyed"<<endl;
    else
        p4->Fun();*/

     if (p.expired())
        cout <<  "object is destroyed" << endl;
     else
        cout <<  "object is alived" << endl;

     return  0;
}