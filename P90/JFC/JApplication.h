#ifndef _JAPPLICATION_H_
#define _JAPPLICATION_H_

//将JFC框架里面的所有类放到一个名称空间里面
namespace JFC
{

class JWindow;

//一个应用程序JApplication只有这样一个对象，所以要实现单例模式
// 一种特殊的单例模式，模仿QT
class JApplication
{
public:
	JApplication();
	~JApplication();

	static JApplication* Instance() { return self_; }

	JWindow* GetCurrent() const { return current_; }
	JWindow* SetCurrent(JWindow* win) { current_ = win; }//将win设置为当前窗口
	JWindow* Root() const { return root_; }

	int Exec();				// 消息循环

private:
	static JApplication* self_;//static声明
	JWindow* current_;		// 当前接收按键的窗口
	JWindow* root_;			// 根
};


//目的是让其他文件模块也访问到JApplication app;对象，模仿QT的qApp
#define jApp JApplication::Instance()
}
#endif // _JAPPLICATION_H_