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

//���û���κ�һ���쳣�ܹ�����Ļ������׳�������ע�����ֹ�����У��������ֹ���̣��ٵ���һ��abort������abort�����
//�����Ǹ��Ի���
void MyTerminate()
{
    cout<<"MyTerminate ..."<<endl;
}

int main(void)
{
    // abort();
    set_terminate(MyTerminate);
    try 
    {
        try
        {
            cout<<"Inner ..."<<endl;
            throw MyExceptions("test exception");//�׳�MyException�쳣��û�к��ʵ��쳣�����������⴫��Ҳû�У����ͻ����terminte������ֹ
                                                //terminte����Ĭ�ϵ��õ���abort�������쳣��ֹ����
        }
        catch (int)//����catch�������int�����쳣���޷�����throw������쳣�������������catch������
        {
            cout<<"Inner ..."<<endl;
            cout<<"catch a int exception"<<endl;
        }
        // catch (MyExceptions& e)//������쳣����e��throw MyExceptions("test exception");�����׳����쳣���������������ڽ����ˣ���������������
        // {
        //     cout<<"Inner ..."<<endl;
        //     cout<<e.what()<<endl;
        //     throw e;//�����׳��쳣����ÿ������캯�������ݵ����
        // }
    }
    catch (int)//����catch�������int�����쳣���޷�����throw������쳣�������������catch������
    {
        cout<<"Outer ..."<<endl;
        cout<<"catch a int exception"<<endl;
    }
    // catch (MyExceptions& e)//������Ϻ�������쳣����eҲ�͸��������ˣ�������������
    // {
    //     cout<<"Outer ..."<<endl;
    //     cout<<e.what()<<endl;
    // }

    return 0;
}