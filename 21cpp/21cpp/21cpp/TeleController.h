#ifndef  _TELE_CONTROLLER_H_
#define _TELE_CONTROLLER_H_

//有的编译器对Television中不可见，则加上下面的前向声明即可，因为这里只是一个引用，并没有定义对象
//还要在TeleController.cpp文件中增加#include "Television.h"
class Television;

class TeleController
{
public:
	void VolumeUp(Television& tv);

	void VolumeDown(Television& tv);

	void ChanelUp(Television& tv);

	void ChanelDown(Television& tv);
};

#endif // _TELE_CONTROLLER_H_