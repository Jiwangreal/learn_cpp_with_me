#include <iostream>
using namespace std;

class Base
{
public:
    int x_;
protected:
    int y_;
private:
    int z_;
};

//���м̳еķ���Ȩ���ǲ����
//���еĳ�Ա���������л��ǹ��еģ������ĳ�Ա���������л��Ǳ�����
class PublicInherit : public Base
{
public:
    void Test()
    {
        x_  = 10;//���������п��Է��ʻ����public��Ա
        y_ = 20;//���������п��Է��ʻ����protected��Ա
        // z_ = 30;//���������в��ܷ��ʻ����private��Ա����Ȼ�����private��Ա���������һ����
    }
private:
};

//˽�м̳У������Ĺ��г�Ա�ͱ�����Ա���������ж���˽�еģ�������ĳ�Ա�������ǿ��Է��ʵ�
class PrivateInherit : private Base
{
public:
    void Test()
    {
        x_ = 10;
        y_ = 20;
        // z_ = 30;//˽�м̳л����޷����ʻ����˽�г�Ա
    }
};

//���ౣ����Ա�ڼ̳�֮���Ƿ��Ǳ����ģ����Ǳ����ģ�
//������������Ӧ���ǿ��Է��ʵ�
class PublicPublicInherit : public PublicInherit
{
public:
    void test()
    {
        y_ = 20;//���ǿ��Է��ʣ�˵�����Ǳ�����
    }
};



int main(void)
{
    Base b;
    b.x_ = 20;//���ⲿ���Է���public��Ա
    b.z_ = 30;//���ⲿ���ܷ���protected��Ա
    
    //���м̳еķ���Ȩ�޲��䣬���е����������л��ǹ��еģ�������Ա���������л��Ǳ�����
    PublicInherit pub;
    pub.x_ = 20;

    //˽�м̳в��ܷ���˽�г�Ա
    // PrivateInherit pi;
    // pi.x_ = 10;

    return 0;
}
