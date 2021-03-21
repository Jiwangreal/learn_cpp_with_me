#include "JFC/JApplication.h"

using namespace JFC;

int main()
{
	//通常意义上单例模式不允许直接构造对象，这是一个
	//特殊的单例模式，JApplication app;JApplication app2;
	//定义2个对象实际上是同一个对象
	JApplication app;
	return app.Exec();	//整个程序停留在消息循环里面
}