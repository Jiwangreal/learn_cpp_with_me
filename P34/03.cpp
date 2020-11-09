#include <iostream>
using namespace std;

class Base
{
public:
    virtual void Fun1()
    {
        cout<<"Base::Fun1 ..."<<endl;
    }

    virtual void Fun2()
    {
        cout<<"Base::Fun2 ..."<<endl;
    }

    int data1_;
};

//��������3���麯��
class Derived : public Base
{
    //�Ḳ�ǻ�����麯��Fun2()
    void Fun2()
    {
        cout<<"Derived::Fun2 ..."<<endl;
    }
    virtual void Fun3()
    {
        cout<<"Derived::Fun3 ..."<<endl;
    }
    int data2_;
};

//ʹ��typedef������һ������
typedef void (*FUNC)();
int main(void)
{
    cout<<sizeof(Base)<<endl;
    cout<<sizeof(Derived)<<endl;
    Base b;
    long** p = (long**)&b;//p[0][0]ָ�������麯��Base::Func1
    FUNC fun = (FUNC)p[0][0];//��p[0][0]ָ��ǿ��ת��Ϊfunc��ǿ��ת��Ϊ����ָ������
    fun();//����õ�������麯��

    Derived d;
    p = long(**)&d;
    fun = (FUNC)p[0][0];
    fun();
    fun = (FUNC)p[0][1];
    fun();
    fun = (FUNC)p[0][2];
    fun();

    //ֻ��ͨ������ָ����߻������ã����ж�̬��
    //����ָ��ppָ����������󣬻�ȡ������d��ͷ4���ֽڣ�ָ�����Ȼ���������ҵ���Ӧ��Func2��ʵʩ��̬��
    //����Func2����ƫ�ƣ�ƫ�Ƶ�Derived::Fun2,������Base::Fun2,����������ڴ�ͼȥ��
    //pp��Ȼ�ǻ���ָ�����ͣ����ǵ��õ�����������麯��
    Base* pp = &d;
    pp->Fun2();//Func2���麯��������ʱ�ڲŻ�ȥȷ��Func2����ڵ�ַ

    //�麯������ֱ��ʹ�ã������Ƕ�̬�󶨣���ڵ�ַ�ڱ����ھ;�����
    //ֱ�ӵ����Ǿ�̬��
    d.fun2();

    return 0;
}