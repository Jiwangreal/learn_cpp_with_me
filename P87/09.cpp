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
    //weak_ptrͨ��Ҫ��shared_ptr���ʹ��
    boost::weak_ptr<X> p;//����һ����ָ���������
    boost::shared_ptr<X> p3;
    {
        boost::shared_ptr<X> p2( new X);
        cout << p2.use_count() << endl;//=1
        p = p2;
        cout << p2.use_count() << endl;//p2��ǿ���ã����ü���=1

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