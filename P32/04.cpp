#include <iostream>
using namespace std;

//Bed，Sofa，SofaBed都是家具，都有weight这个属性
class Furniture
{
public:
    Furniture(weight) : weight_(weight)
    {
        cout<<"Furniture ..."<<endl;
    }
    //虚基析构函数
    ~Furniture()
    {
        cout<<"~Furniture ..."<<endl;
    }
    int weight_;
};

//Furniture类是Bed类的虚基类
class Bed : virtual public Furniture
{
public:
    //如果Furniture不是虚基类，会先调用Furniture的构造函数
    Bed(int weight) : Furniture(weight)
    {
        cout<<"Bed ..."<<endl;
    }
    ~Bed()
    {
        cout<<"~Bed ..."<<endl;
    } 
    void sleep()
    {
        cout<<"Sleep..."<<endl;
    }


    int weight_;
};

class Sofa: virtual public Furniture
{
public:
    Sofa(int weight) : Furniture(weight)
    {
        cout<<"Sofa ..."<<endl;
    }
    ~Sofa()
    {
        cout<<"~Sofa ..."<<endl;
    }
    void WatchTV()
    {
        cout<<"Watch TV..."<<endl;
    }
};

//多重继承
//沙发床
//使用SofaBed类来构造对象时，weight_应该在哪里被构造呢？如果在Bed或者Sofa类中
//构造，就会出现weight_被构造2次的情况，所以应该在SofaBed类中构造
//下面是最底层的派生类的构造函数
class SofaBed : public Sofa, public Bed
{
public:
    SofaBed(int weight) : Bed(weight), Sofa(weight), Furniture(weight)
    {
        cout<<"SofaBed ..."<<endl;
        FoldInt();
    }
    ~SofaBed()
    {
        cout<<"~SofaBed ..."<<endl;
    }
    void FoldOut()
    {
        cout<<"FoldOut..."<<endl;
    }
    void FoldInt()
    {
        cout<<"FoldIn..."<<endl;
    }
};

int main(void)
{
    SofaBed sofaBed(5);
    //这样就没有二义性了
    sofaBed.weight_ = 10;

    sofaBed.WatchTV();
    sofaBed.FoldOut();
    sofaBed.sleep();

    return 0;
}