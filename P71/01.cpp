#include <iotream>
using namespace std;
#include "Singleton.h"


//希望ApplicationImpl类变成单例模式，可以使用模式方式来实现单例模式
class ApplicationImpl
{
public:
    ApplicationImpl() {cout<<"ApplicationImpl ..."<<endl;}
    ~ApplicationImpl() {cout<<"~ApplicationImpl" ...<<endl;}
    void Run() {cout<<"Run ..."<<endl;}
};

//将Singleton类模板看成是单例模式类的包装器，用它可以产生单例模式类
//Application是一个单例模式类，不能构造对象
typedef Singleton<ApplicationImpl> Application;

int main(void)
{
    // Application a;//Application是一个单例模式类，不能构造对象

    Application::GetInstance().Run();
    Application::GetInstance().Run();

	return 0;
}