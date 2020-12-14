#include <iostream>
#include <string>
using namespace std;

//�׳��쳣��
class MyExceptions
{
public:
    MyExceptions(const char* message)
        : message_(message)
    {
        cout<<"MyExceptions ..."<<endl;
    }
    //�������캯��
    MyExceptions(const MyExceptions& other) : message_(other.message)
    {
        cout<<"Copy MyExceptions ..."<<endl;
    }
    ~MyExceptions()
    {
        cout<<"~MyExceptions"<<endl;
    }

    const char* what() const
    {
        return message_.c_str();//�����쳣��Ϣ
    }

private:
    string message_;
};

//�׳��Զ������͵��쳣
 double Divide(double a, double b)
 {
     //ջչ����
     //�ڵ�����֮�ϣ�Divide���ܻ����ܵ������������������������������оֲ�����Ҫ���ͷţ���һ���̳�֮Ϊջչ��
     //����ֻ��һ����MyExceptions e("division by zero");�����������ֵ����˺��������������ִ����˾ֲ�������ô��Щ�ֲ�����ᱻ
     //����ͷŵ�
     if (b == 0.0)
     {
        //  MyExceptions e("division by zero");
        //  throw e;//�����׳��Զ������͵��쳣,throw e����ÿ������캯������������һ������
        //         //���žֲ�����MyException e("division by zero");�������ˣ��׳���һ���쳣������catch����
        throw 1.5;
     }
     else
     {
         return a / b;
     }
     
 }

 int main(void)
 {
     try
     {
         cout<<Divide(5.0, 0.0)<<endl;
     }
     catch (MyExceptions& e)//���쳣���󴫵ݹ������������׳����쳣�������������Ҳ�����ˣ�����������
     {
         //����쳣��Ϣ
         cout<<e.what()<<endl;
     }
     catch (int)
     {
            cout<<"int exception ..."<<endl;
     }
     catch (...)//...��ʾ���Բ����κ��쳣
     {
            cout<<"catch a exception ..."<<endl;
     }
 }