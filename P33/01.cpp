#include <iostream>
using namespace std;

class BB
{
public:
    int bb_;
};

//B1虚继承至B
class B1 : virtual public BB
{
public:
    int b1_;
};

class B2 : virtual public BB
{
public:
    int b2_;
};

//DD多重继承至B1和B2
class DD : public B1, public B2
{
public:
    int dd_;
};


int main(void)
{
    cout<<sizeof(BB)<<endl;
    cout<<sizeof(B1)<<endl;
    cout<<sizeof(DD)<<endl;

    //推导B1的内存模型
    B1 b1;
    long** p;
    cout<<&b1<<endl;//类对象的首地址
    cout<<&b1.bb_<<endl;//bb_成员的地址
    cout<<&b1.b1_<<endl;//b1_成员的地址

    p = (long**)&b1;//指向对象b1
    cout<<p[0][0]<<endl;
    cout<<p[0][1]<<endl;
    
    //推导DD的内存模型
    DD dd;
    cout<<&dd<<endl;
    cout<<dd.bb_<<endl;
    cout<<dd.b1_<<endl;
    cout<<dd.b2_<<endl;
    cout<<dd.dd_<<endl;

    p = (long**)&dd;
    cout<<p[0][0]<<endl;
    cout<<p[0][1]<<endl;
    cout<<endl;
    cout<<p[2][0]<<endl;
    cout<<p[2][1]<<endl;

    //dd.bb_是直接访问，因为这里面的内存模型在编译的时候已经决定了，因为dd对象在创建的时候需要分配内存，在编译时已经决定了
    BB* pp;
    pp = &dd;
    pp->bb_;//通过指针来访问虚基类里面的数据成员，是间接访问的，这需要运行时的支持
            //这需要vbptr指针找到虚基类表里面的第二项（虚基类地址与虚基类表指针地址的差），从而找到BB对象的地址

    return 0;
}