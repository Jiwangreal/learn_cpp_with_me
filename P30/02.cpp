#include <iostream>
using namespace std;

class Base 
{
public:
    static int b_;
};
int Base::b_ = 100;
class Derived : public Base
{

};


int main()
{
    Base b;
    Base d;
    cout<<Base::b_<<endl;//�Ƽ�ʹ�õķ�������Ϊ��̬��Ա����ν�̳У���Ϊ��ֻ��1�ݿ���
    //���Ƽ����������д��
    cout<<b.b_<<endl;

    cout<<Derived::b_<<endl;
    cout<<d.b_<<endl;
    return 0;
}