#include <stdio.h>
#include <setjmp.h>

//jmp_buf��ʵ������һ����������
jmp_buf buf;

double Divide(double a, double b)
{
    if (b == 0.0)
    {
        //�׳��쳣
        longjmp(buf, 1);//���������һ�γ���ת����������ת������ĺ�������go toֻ���ں����ڲ���ת��
                        //���ﳤ��ת����ת��buf������λ�ã� ret = setjmp(buf);��Ȼ�����ִ��
                        //Ȼ����εķ���ֵ��1������ֵ����longjmp�ĵڶ��������������������Ի������divisiong by zero
                        //�൱��C++�е��쳣���׳���throw
    }
    else
    {
        return a / b;
    }
    
}

int main(void)
{
    int ret;
    //ջstack����������buf��
    //����һ�������buf������ɹ�����0
    ret = setjmp(buf);//���ȱ����������л�����buf��������
    if (ret == 0)//��һ�α������ǳɹ��ģ����Խ��뵽=0�������division...    
    {             //�൱��C++��try
        printf("division...\n");
        printf("%f\n", Divide(5.0, 0.0));//����ִ��Divide����
    }
    else if(ret == 1)//�൱��C++�е�catch�����׳����쳣���д���
    {
        printf("divisiong by zero\n");
    }

    return 0;
}




