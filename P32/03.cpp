#include <iostream>
using namespace std;

//Bed��Sofa��SofaBed���ǼҾߣ�����weight�������
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

//���ؼ̳�
//ɳ����
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
    //������û�ж�������
    sofaBed.weight_ = 10;

    sofaBed.WatchTV();
    sofaBed.FoldOut();
    sofaBed.sleep();

    return 0;
}