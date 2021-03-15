#include <boost/shared_ptr.hpp>
#include <iostream>
using  namespace std;

class X
{
public:
    X()
    {
        cout <<  "X ..." << endl;
    }
    ~X()
    {
        cout <<  "~X ..." << endl;
    }
};

int main( void)
{
    cout <<  "Entering main ..." << endl;
    boost::shared_ptr<X> p1( new X);
    cout << p1.use_count() << endl;//������ü���
    boost::shared_ptr<X> p2 = p1;//��p1�����ʼ��p2���󣬵��ÿ������캯�����൱�ڹ���һ������
     //boost::shared_ptr<X> p3;
     //p3 = p1;

    cout << p2.use_count() << endl;//��ֵ����p1.use_count()
    p1.reset();//��ʾ�ÿգ���ʽ�Ľ����ü���-1��Ҳ���Բ��ã��ȳ��������ʱ�����еģ���Ϊ������ָ����ջ������
    cout << p2.use_count() << endl;
    p2.reset();
    cout <<  "Exiting main ..." << endl;
     return  0;
}
