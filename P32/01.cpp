#include <iostream>
using namespace std;

class Bed
{
public:
    Bed(int weight) : weight_(weight)
    {

    } 
    void sleep()
    {
        cout<<"Sleep..."<<endl;
    }


    int weight_;
};

class Sofa
{
public:
    Sofa(int weight) : weight_(weight)
    {

    }
    void WatchTV()
    {
        cout<<"Watch TV..."<<endl;
    }
    int weight_;
};

//多重继承
//沙发床
class SofaBed : public Sofa, public Bed
{
public:
    SofaBed() : Bed(0), Sofa(0)
    {
        FoldInt();
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
    SofaBed sofaBed;
    //error，指定不明确，是Bed的weight_还是Sofa的weight_？
    // sofaBed.weight_ = 10;
    // sofaBed.weight_ = 10;

    sofaBed.Bed::weight_ = 10;
    sofaBed.Sofa::weight_ = 20;
    sofaBed.WatchTV();
    sofaBed.FoldOut();
    sofaBed.sleep();

    return 0;
}