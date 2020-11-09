#include <iostream>
using namespace std;

class BB
{
public:
    int bb_;
};

//B1��̳���B
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

//DD���ؼ̳���B1��B2
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

    //�Ƶ�B1���ڴ�ģ��
    B1 b1;
    long** p;
    cout<<&b1<<endl;//�������׵�ַ
    cout<<&b1.bb_<<endl;//bb_��Ա�ĵ�ַ
    cout<<&b1.b1_<<endl;//b1_��Ա�ĵ�ַ

    p = (long**)&b1;//ָ�����b1
    cout<<p[0][0]<<endl;
    cout<<p[0][1]<<endl;
    
    //�Ƶ�DD���ڴ�ģ��
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

    //dd.bb_��ֱ�ӷ��ʣ���Ϊ��������ڴ�ģ���ڱ����ʱ���Ѿ������ˣ���Ϊdd�����ڴ�����ʱ����Ҫ�����ڴ棬�ڱ���ʱ�Ѿ�������
    BB* pp;
    pp = &dd;
    pp->bb_;//ͨ��ָ���������������������ݳ�Ա���Ǽ�ӷ��ʵģ�����Ҫ����ʱ��֧��
            //����Ҫvbptrָ���ҵ�����������ĵڶ��������ַ��������ָ���ַ�Ĳ���Ӷ��ҵ�BB����ĵ�ַ

    return 0;
}