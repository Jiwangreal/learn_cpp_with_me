#ifndef _TELEVISION_H_
#define _TELEVISION_H_

//�еı�������TeleController���ɼ�������������ǰ����������
class TeleController;

class Television
{
	//��TeleControllerң����������ΪTelevision���ӻ������Ԫ��
	friend class TeleController;
public:
	Television(int volume, int chanel);
private:
	int volume_;//����
	int chanel_;//Ƶ��
};

#endif // _TELEVISION_H_
