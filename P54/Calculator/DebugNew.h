#ifndef _DEBUG_NEW_H
#define _DEBUG_NEW_H

#ifndef NODEBUG
#include "Tracer.h"

//��ʹ��new intʱ������ʹ�ó�new(__FILE__, __LINE__) int
//__FILE__:��ǰ���������ڵ��ļ���__LINE__����ǰ�������
//���⣬������operator new��ʵ�ʵ��õ���operator new�����ҽ�2���������ݹ�ȥ��
//��ʱ��new�ȼ���new(__FILE__, __LINE__)
#define new new(__FILE__, __LINE__)

//delete��֧��������÷�����Ҫ��ôȥ��
// #define delete delete(__FILE__, __LINE__)

#endif //NODEBUG

#endif // _DEBUG_NEW_H