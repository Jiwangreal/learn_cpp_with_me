#include <iostream>
using namespace std;

//���캯���������麯��
//���������������麯������һ�����ж�̬�еĻ��࣬Ӧ�ý�������������Ϊ����������

// class Base
// {
// public:
//     void Test() = 0;//���Ǵ��麯��void Test() = 0;��Base���ǳ�����
// };

//����һ��û���κνӿڵ���,�����Ҫ��������ɳ�����,ֻ�ܽ���������������Ϊ�����
//ͨ�������,�ڻ����д��麯����Ҫʵ��
//�����Ǵ�����������Ҫ����ʵ��(����һ���յ�ʵ�ּ���)
class Base
{
public:
    virtual ~Test() = 0;//ӵ�д�����������������ǳ�����
    {

    }
};

class Derived : public Base
{

};


int main(void)
{
    Derived d;
    return 0;
}
