#include <iostream>
using  namespace std;

template < typename T>
class MyClass
{
private:
    /*
    typename T::SubType *ptr_; ���ǰ��û��typename ���Σ���SubType�ᱻ��Ϊ��T�����ڲ��ľ�̬���ݳ�Ա���Ƶ���ȥ��* �Ͳ����� Ϊ��ָ�룬����
    ��Ϊ�ǳ˺ţ������ʱ��ͳ����ˡ��������Σ���֪��SubType ��T �ڲ����Զ������ͣ�ptr��ָ���������͵�ָ �룬����ͨ����
    */
    typename T::SubType *ptr_;//typename����SubType��һ������
};

class Test
{
public:
     typedef  int SubType;
};
int main( void)
{
    MyClass<Test> mc;
     return  0;
}
