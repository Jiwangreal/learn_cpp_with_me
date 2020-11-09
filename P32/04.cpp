#include <iostream>
using namespace std;

//Bed��Sofa��SofaBed���ǼҾߣ�����weight�������
class Furniture
{
public:
    Furniture(weight) : weight_(weight)
    {
        cout<<"Furniture ..."<<endl;
    }
    //�����������
    ~Furniture()
    {
        cout<<"~Furniture ..."<<endl;
    }
    int weight_;
};

//Furniture����Bed��������
class Bed : virtual public Furniture
{
public:
    //���Furniture��������࣬���ȵ���Furniture�Ĺ��캯��
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

//���ؼ̳�
//ɳ����
//ʹ��SofaBed�����������ʱ��weight_Ӧ�������ﱻ�����أ������Bed����Sofa����
//���죬�ͻ����weight_������2�ε����������Ӧ����SofaBed���й���
//��������ײ��������Ĺ��캯��
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
    //������û�ж�������
    sofaBed.weight_ = 10;

    sofaBed.WatchTV();
    sofaBed.FoldOut();
    sofaBed.sleep();

    return 0;
}