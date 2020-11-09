#ifndef _TELEVISION_H_
#define _TELEVISION_H_

//有的编译器对TeleController不可见，则加上下面的前向声明即可
class TeleController;

class Television
{
	//将TeleController遥控器类声明为Television电视机类的友元类
	friend class TeleController;
public:
	Television(int volume, int chanel);
private:
	int volume_;//声音
	int chanel_;//频道
};

#endif // _TELEVISION_H_
