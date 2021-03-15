#include <boost/shared_ptr.hpp>
#include <iostream>
#include <memory>
#include <vector>
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
    //编译失败
    // vector<auto_ptr<X> > v;
    // auto_ptr<X> p(new X);
    // v.push_back(p);

    //boost::shared_ptr<X>是可以放到vector中的
    vector<boost::shared_ptr<X> > v;
    boost::shared_ptr<X> p(new X);
    v.push_back(p);//push_back内部会构造一个shared_ptr对象，与p一样，所以输出为2
    cout<<v.use_count<<endl;//2个对象都引用了X
    //当p对象销毁，向量v中的对象也被销毁的时候，引用计数减为0，则堆对象X自动被销毁

    

    return  0;
}
