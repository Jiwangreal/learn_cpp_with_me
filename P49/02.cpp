#include <isotream>
using namespace std;


//jmp_buf��ʵ������һ����������
jmp_buf buf;

double Divide(double a, double b)
{
    if (b == 0.0)
    {
        //�׳��쳣
        throw 1;        //throw
    }
    else
    {
        return a / b;
    }
    
}

int main(void)
{
    try     //try  
    {             
        
        cout<<"division..."<<endl;
        //��ε���Divide��Ҳû��Ҫ��ζ�Divide�ķ���ֵ�����жϣ���Ϊ������ͨ��try������catch��
        //��ʽ�����쳣������÷���ֵ���жϴ���Ļ���ÿ�ε���Divide��Ҫ�ж����Ĵ�������д�����
        cout<<Divide(3.0, 0.0)<<endl;//ֻҪ����һ�������˴���ͻᱻ��׽��
        cout<<Divide(5.0, 0.0)<<endl;
    }
    //�쳣�����ĵص����쳣����ĵص���������Զ
    catch(int)//catch���������쳣
    {
        cout<<"divisiong by zero\n"<<endl;
    }

    return 0;
}




