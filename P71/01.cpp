#include <iotream>
using namespace std;
#include "Singleton.h"


//ϣ��ApplicationImpl���ɵ���ģʽ������ʹ��ģʽ��ʽ��ʵ�ֵ���ģʽ
class ApplicationImpl
{
public:
    ApplicationImpl() {cout<<"ApplicationImpl ..."<<endl;}
    ~ApplicationImpl() {cout<<"~ApplicationImpl" ...<<endl;}
    void Run() {cout<<"Run ..."<<endl;}
};

//��Singleton��ģ�忴���ǵ���ģʽ��İ�װ�����������Բ�������ģʽ��
//Application��һ������ģʽ�࣬���ܹ������
typedef Singleton<ApplicationImpl> Application;

int main(void)
{
    // Application a;//Application��һ������ģʽ�࣬���ܹ������

    Application::GetInstance().Run();
    Application::GetInstance().Run();

	return 0;
}