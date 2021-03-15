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
};

int main( void)
{
    cout <<  "Entering main ..." << endl;
    {
        //X堆对象，由智能指针栈对象pp来管理
        //智能指针栈对象pp销毁的时候，他所管理的堆对象也就跟着销毁了
        boost::scoped_ptr<X> pp( new X);

         //boost::scoped_ptr<X> p2(pp); //Error:所有权不能转移
    }
    cout <<  "Exiting main ..." << endl;

     return  0;
}