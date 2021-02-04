#include <vector>
#include <iostrem>
using namespace std;


int main(void)
{
    //vector<int> 是一个模板类，定义一个对象v会引发模板类的构造函数的调用
    vector<int> v;
    v.push_back(1);//在这打个断点
    cout<<v.capacity()<<endl;

    v.push_back(1);
    cout<<v.capacity()<<endl;

    v.push_back(1);
    cout<<v.capacity()<<endl;

    v.push_back(1);
    cout<<v.capacity()<<endl;


    v.push_back(1);
    cout<<v.capacity()<<endl;

    v.push_back(1);
    cout<<v.capacity()<<endl;

    v.push_back(1);
    cout<<v.capacity()<<endl;

    return 0;
}
