#ifndef _TRACER_H_
#define _TRACER_H_

#include <map>

//release代码与debug代码区别：release代码一般没有下面的跟踪
//如果没有定义NODEBUG，下面的代码就不跟踪了，当前的vs2008是有做跟踪的，这里仅做说明
#ifndef NODEBUG

//重载全局的new和delete运算符
//尺寸大小，文件名称，所在的行
void* operator new(size_t size, const char* file, long line);
//重载new，也要重载delete，delete后面的2个参数没用:const char*, long，就不用给出来了
void operator delete(void* p, const char*, long);

//重载operator delete(void*p);目的是减少误报现象
void operator delete(void*p);//与void* operator new(size_t size);的new运算符重载对应，为啥这么下，看下面的解释

//目的是减少误报，使用vs2008打断点发现进入的是cpp库中的这里，所以索性把相关的函数都重载了
void operator delete[](void*p, const char*, long);//与void* operator new[](size_t size, const char* file, long line);的new运算符对应，从
                                                //void* operator new(size_t size, const char* file, long line);改造而来
void operator delete[](void*p);//与void* operator new[](size_t size);对应，改造方法与上类似


//既然重载了delete运算符，则对应的new运算符也需要重载
void* operator new[](size_t size, const char* file, long line);
void* operator new[](size_t size);
void* operator new(size_t size);

class Tracer
{
private:
//Entry是嵌套类，只在Tracer类中使用，作用域是Tracer类中
    class Entry
    {
    public:
        Entry(const char* file=0, long line=0)
            : file_(file), line_(line) {}
    const char* File() const {return file_;}//返回文件
    long Line() const {return line_}//返回行
    private:
        const char* file_;
        long line_;
    };

    class Lock
    {
    pubic:
        Lock(Tracer tracer) : tracer_(tracer)
        {
            tracer_.lock();
        }
        ~Lock()
        {
            tracer_.unlock();
        }
    private:
        Tracer& tracer_;
    };
    /*
    只说友元类破坏了封装性是不对的。
    友元函数破坏了封装性，但是它提高了效率。
    友元类恰恰提高了类的封装性
    */
    friend class Lock;//因为嵌套类Lock访问了Tracer类的私有成员函数lock和unlock，所以需要将其声明为友元类

public:
    Tracer();
    ~Tracer();
    static bool Ready;//是否开始跟踪

    //增加Add方法，将文件和行添加到容器map中
    void Add(void* p, const char* file, long line);
    //移除的方法
    void Remove(void* p);
    //Dump到哪里，哪里发生了内存泄漏
    void Tracer::Dump();
private:
    //下面的作用域也是类作用域
    //map容器保存内存使用的信息,第一个参数是指针，这个内存是在哪个文件，哪一行分配的，登记在内部的Entry类中
    std::map<void*, Entry> mapEntry_;
    int lockCount_;
    void lock() {++lockCount_;}//锁定的函数
    void unLock() {--lockCount_;}//解锁的函数

}


extern Tracer NewTrace;

#endif //NODEBUG

#endif //_TRACER_H
