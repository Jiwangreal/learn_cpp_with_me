#include "Complex.h"

int main(void)
{
    Complex c1(3, 5);
    Complex c2(4, 6);

    // c1.Add(c2);
    // c1.Display();

    //����Ա����������Ԫ�������У�VS2008�������г�Ա�������صĺ�����������VC6�У��������ܹ���
    //����Գ�Ա�����ķ�ʽ���أ��ȼ���c1.operator+(c2)
    //�������Ԫ�����ķ�ʽ���أ��ȼ���operator+(c1+c2),��operator+����������ȫ�ֵģ�������������
    Complex c3 = c1 + c2;   
    c1.Display();
    c2.Display();
    c3.Display(); 


}