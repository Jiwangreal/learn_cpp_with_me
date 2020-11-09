#ifndef _COUNTED_OBJECT_H_
#define _COUNTED_OBJECT_H_

class CountedObject
{
public:
	CountedObject();
	~CountedObject();
public:
	static int GetCount();
private:
	//（不论静态还是非静态的）成员变量的初始化都不能在类声明的时候给出来
	//eg：static int count_ = 100；都是错的
	static int count_;		// 静态成员的引用性声明，还需要静态成员的定义性声明
};


#endif // _COUNTED_OBJECT_H_