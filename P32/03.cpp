#include <iostream>
using namespace std;

//Bed，Sofa，SofaBed都是家具，都有weight这个属性
class Furniture
{
public:
    Furniture(weight) : weight_(weight)
    {

    }
    int weight_;
};

class Bed : virtual public Furniture
{
public:
    // Bed(int weight) : Furniture(weight)
    // {

    // } 
    void sleep()
    {
        cout<<"Sleep..."<<endl;
    }


    int weight_;
};

class Sofa: virtual public Furniture
{
public:
    // Sofa(int weight) : Furniture(weight)
    // {

    // }
    void WatchTV()
    {
        cout<<"Watch TV..."<<endl;
    }
};

//多重继承
//沙发床
class SofaBed : public Sofa, public Bed
{
public:
    // SofaBed(int weight) : Bed(weight), Sofa(weight)
    // {
    //     FoldInt();
    // }
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
    SofaBed sofaBed;
    //这样就没有二义性了
    sofaBed.weight_ = 10;

    sofaBed.WatchTV();
    sofaBed.FoldOut();
    sofaBed.sleep();

    return 0;
}