#include <iostream>
using namespace std;

class Test
{
public:
    Test();
    {
        cout<<"Test ..."<<endl;
    }
    Test(const Test& other)
    {
        cout<<"Copy Test ..."<<endl;
    }
    ~Test()
    {
        cout<<"Test"<<endl;
    }
};


Test fun()
{
    //�ֲ�����Ĺ���������
    //���ȵ��ù��캯����Ȼ��������������������ͷŵ�
    // Test t;
    // return t;//Ȼ����ÿ������캯������һ������Ȼ��������������������ڽ�����
    return Test();//���캯��������һ������ֱ����Ϊ����ֵ����ֻ�����һ�ι��캯����������ÿ������캯����
}

int main(void)
{
    fun();//���صĶ���û�����ܽ��վ�����������
    cout<<"......"<<endl;
    return 0;
}