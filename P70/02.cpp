#include <iostream>
using  namespace std;


template < typename T>
class MyClass
{
private:
    T value;
public:
     void Assign( const MyClass<T> &x)
    {
        value = x.value;
    }
};

int main( void)
{
    MyClass< double> d;
    MyClass< int> i;

    d.Assign(d);         // OK
    d.Assign(i);         // Error
        					//��Ϊi �� d �����Ͳ�ͬ���ʻ������������ó�Աģ�壨��Ա���������ģ�壩�ķ������
    					//��Ȼ��ͬһ����ģ��ʵ����������ģ���࣬���ǻ��ǲ�һ��
                        //һ��T��double��һ��T��int
     return  0;
}
