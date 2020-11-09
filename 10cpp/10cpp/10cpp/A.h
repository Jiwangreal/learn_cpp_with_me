#ifndef _A_H_
#define _A_H_

#include "B.h"
class A
{
public:
	A(void);
	~A(void);

	B b_;//定义B类对象，要：include B的头文件
};

#endif // _A_H_