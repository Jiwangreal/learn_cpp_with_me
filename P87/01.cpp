#include <boost/scoped_ptr.hpp>
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
    {
        //X�Ѷ���������ָ��ջ����pp������
        //����ָ��ջ����pp���ٵ�ʱ����������ĶѶ���Ҳ�͸���������
        boost::scoped_ptr<X> pp( new X);

         //boost::scoped_ptr<X> p2(pp); //Error:����Ȩ����ת��
    }
    cout <<  "Exiting main ..." << endl;

     return  0;
}