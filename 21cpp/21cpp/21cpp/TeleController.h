#ifndef  _TELE_CONTROLLER_H_
#define _TELE_CONTROLLER_H_

//�еı�������Television�в��ɼ�������������ǰ���������ɣ���Ϊ����ֻ��һ�����ã���û�ж������
//��Ҫ��TeleController.cpp�ļ�������#include "Television.h"
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