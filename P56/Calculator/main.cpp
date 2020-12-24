#include <iostream>
#include <string>
#include "Scanner.h"
#include "Parser.h"
#include "Calc.h"
#include "Exception.h"

int main(void)
{
    Calc calc;
    STATUS status = STATUS_OK;
    do
    {
        std::cout<<">";
        std::string buffer;
        std::getline(std::cin, buffer);//����һ�б��ʽ�ŵ�buf����
        // std::cout<<buffer<<std::endl;
        Scanner scanner(buffer);
        //�����ֱ�Ӱ��س�������bug����ɨ����scanner��������IsEmpty����
        if (!scanner.IsEmpty())
        {
            //Parser�Ǿֲ�����
            Parser parser(scanner, calc);  
            //try catchд�����Խ����������������������������̸��뿪��
            //������ʱ����ܻ��׳��쳣
            try
            {
                status = parser.Parse();//ʵ���ϼ�����ʽ��ֵ�����Ǽ���������ĸ��ڵ��ֵ
                //���1+1=2��bug
                if (status == STATUS_OK)//���ﲻ�жϷ���ֵҲ�ǿ��Եģ���Ϊ�ִ�����׳��쳣�ˡ�û�д���ͽ�����������
                {                       //���������̲���Ҫͨ������ֵ���ж����Ƿ���������C���Բ���ͨ������ֵ���ж��Ƿ���������
                    std::cout<<paese.Calculate()<<std::endl;
                }
            }
            catch (SyntaxError& se)//��������쳣
            {
                status = STATUS_QUIT;//Ϊ�˼���ڴ�й©
                std::cout<<se.what()<<std::endl;
                // std::cout<<se.StackTrace()<<std::endl;//�����쳣ʱ�����Խ�ջ�ĵ��ù�ϵ����ӡ������ֻ����ʾ˵�������Լ�����ע��
            }
            catch (Exception& se)//������쳣
            {
                status = STATUS_QUIT;//Ϊ�˼���ڴ�й©
                std::cout<<e.what()<<std::endl;
            }
            //�ڴ����ʧ�ܵ��쳣
            //�Ƚ��ټ�����Ϊ�����ڴ�Ĵ��ڣ���ʹ�����������ڴ棬���ǿ��Է����ڴ�ģ����ǲ�������Ϊ����һ���ɹ�
            catch(std::bad_alloc& e)
            {
                status = STATUS_QUIT;
                std::cout<<e.what()<<std::endl;
            }
            catch (...)//�����쳣��...��ʾ�������͵��쳣
            {
                status = STATUS_QUIT;//Ϊ�˼���ڴ�й©
                std::cout<<"Internal error."<<std::endl;
            }
        }
        else
        {
            status = STATUS_QUIT;//Ϊ�˼���ڴ�й©���ͻ��˳����򣬾ͻ��ӡ�ڴ�й©����Ϣ
            std::cout<<"Expression is empty."<<std::endl;
        }
        

    }while(status != STATUS_QUIT);//status=STATUS_QUIT�Ż�����ѭ��
    return 0;
}