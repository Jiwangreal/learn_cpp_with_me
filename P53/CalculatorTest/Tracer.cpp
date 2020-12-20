//注意要将自己工程库的头文件放在CPP库头文件的后面，否则会有一些隐含的依赖
#include <iostream>
#include "Tracer.h"
#ifndef NODEBUG

//初始化
bool Tracer::Ready = false;

Tracer::Tracer()
{
    Ready = true;
}

//当整个程序执行结束的时候，全局对象要被销毁，会调用析构函数：Tracer NewTrace;全局对象
Tracer::~Tracer()
{
    Ready = false;
    Dump();
}


//增加Add方法，将文件和行添加到容器map中
void Tracer::Add(void* p, const char* file, long line)
{
    //使用下标的方式
    mapEntry_[p] = Entry(file, line);
}
//移除的方法
void Tracer::Remove(void* p)
{
    std::vector<void*, Entry>::iterator it;
    it = mapEntry_.find(p);
    if (it != mapEntry_.end())
    {
        mapEntry_.erase(it);
    }
}
//Dump到哪里，哪里发生了内存泄漏
void Tracer::Dump()
{
    //将mapEntry_中没有移除的条目打印出来，这些地方发生了内存泄漏
    if (mapEntry_.size() > 0)
    {
        std::cout << "*** Memory leak(s):"<<std::endl;  
        std::vector<void*, Entry>::iterator it;

        for (it=mapEntry_.begin(); it!=mapEntry_.end();++it)
        {
            //second就是Entry
            const char* file = it->second.File();
            long line = it->sencond.Line();
            //发生泄漏的内存的地址就是void*，这里强转为int:reinterpret_cast<int>，指针强制转化为int
            int addr = reinterpret_cast<int>(if->first);
            //std::hex表示以16进制的方式来打印
            //std::dec表示以十进制的方式来输出
            std::cout<<"0x"<<std::hex<<addr<<": "
                <<file<<", line "<<std::dec<<line<<etd::end;
        }
        std::cout<<endl;
    }
    

    
}


Tracer NewTrace;
//重载operator运算符
//内存分配
void* operator new(size_t size, const char* file, long line)
{
    //分配这么大空间
    void* p = malloc(size);
    //将文件和行信息添加到某个容器中，在程序结束时，可以从容器中取出这些信息，就可以跟踪内存泄漏在哪里了
    if (Tracer::Ready)
    {
        NewTrace.Add(p, file, line);//添加一个条目
    }

    return p;
}

void operator delete(void* p, const char*, long)
{
    if (Tracer::Ready)
    {
        NewTrace.Remove(p);
    }
    free(p);
}

//如果打开下面的函数，正常情况下应该要调用void* operator new(size_t size, const char* file, long line)而这里却会调用这里
//这是因为std::map<void*, Entry> mapEntry_;map对象内部也要通过allocator分配内存，对内存操作的时候调用了operator new，他里面调用的operator new
//根本即没有#define new new(__FILE__, __LINE__)，所以他调用的是调用的是这里的operator new。
//如果继续，下面代码中Add方法中的mapEntry_[p] = Entry(file, line);内部也会调用operator new，而operator new又调用了Add方法，导致无限递归
// void* operator new(size_t size)
// {
//     //分配这么大空间
//     void* p = malloc(size);
//     //将文件和行信息添加到某个容器中，在程序结束时，可以从容器中取出这些信息，就可以跟踪内存泄漏在哪里了
//     if (Tracer::Ready)
//     {
//         NewTrace.Add(p, "?", 0);//添加一个条目
//     }

//     return p;
// }

void operator delete(void*p)
{
    if (Tracer::Ready)
    {
        NewTrace.Remove(p);
    }
    free(p);
}

void* operator new[](size_t size, const char* file, long line)
{
    //分配这么大空间
    void* p = malloc(size);
    //将文件和行信息添加到某个容器中，在程序结束时，可以从容器中取出这些信息，就可以跟踪内存泄漏在哪里了
    if (Tracer::Ready)
    {
        NewTrace.Add(p, file, line);//添加一个条目
    }

    return p;
}

void operator delete[](void*p, const char*, long)
{
    if (Tracer::Ready)
    {
        NewTrace.Remove(p);
    }
    free(p);
}
void* operator new[](size_t size)
{
    //分配这么大空间
    void* p = malloc(size);
    //将文件和行信息添加到某个容器中，在程序结束时，可以从容器中取出这些信息，就可以跟踪内存泄漏在哪里了
    if (Tracer::Ready)
    {
        NewTrace.Add(p, "?", 0);//添加一个条目
    }

    return p;
}


void operator delete[](void*p)
{
    if (Tracer::Ready)
    {
        NewTrace.Remove(p);
    }
    free(p);
}

#endif //NODEBUG