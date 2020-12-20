//ע��Ҫ���Լ����̿��ͷ�ļ�����CPP��ͷ�ļ��ĺ��棬�������һЩ����������
#include <iostream>
#include "Tracer.h"
#ifndef NODEBUG

//��ʼ��
bool Tracer::Ready = false;

Tracer::Tracer()
{
    Ready = true;
}

//����������ִ�н�����ʱ��ȫ�ֶ���Ҫ�����٣����������������Tracer NewTrace;ȫ�ֶ���
Tracer::~Tracer()
{
    Ready = false;
    Dump();
}


//����Add���������ļ�������ӵ�����map��
void Tracer::Add(void* p, const char* file, long line)
{
    //ʹ���±�ķ�ʽ
    mapEntry_[p] = Entry(file, line);
}
//�Ƴ��ķ���
void Tracer::Remove(void* p)
{
    std::vector<void*, Entry>::iterator it;
    it = mapEntry_.find(p);
    if (it != mapEntry_.end())
    {
        mapEntry_.erase(it);
    }
}
//Dump��������﷢�����ڴ�й©
void Tracer::Dump()
{
    //��mapEntry_��û���Ƴ�����Ŀ��ӡ��������Щ�ط��������ڴ�й©
    if (mapEntry_.size() > 0)
    {
        std::cout << "*** Memory leak(s):"<<std::endl;  
        std::vector<void*, Entry>::iterator it;

        for (it=mapEntry_.begin(); it!=mapEntry_.end();++it)
        {
            //second����Entry
            const char* file = it->second.File();
            long line = it->sencond.Line();
            //����й©���ڴ�ĵ�ַ����void*������ǿתΪint:reinterpret_cast<int>��ָ��ǿ��ת��Ϊint
            int addr = reinterpret_cast<int>(if->first);
            //std::hex��ʾ��16���Ƶķ�ʽ����ӡ
            //std::dec��ʾ��ʮ���Ƶķ�ʽ�����
            std::cout<<"0x"<<std::hex<<addr<<": "
                <<file<<", line "<<std::dec<<line<<etd::end;
        }
        std::cout<<endl;
    }
    

    
}


Tracer NewTrace;
//����operator�����
//�ڴ����
void* operator new(size_t size, const char* file, long line)
{
    //������ô��ռ�
    void* p = malloc(size);
    //���ļ�������Ϣ��ӵ�ĳ�������У��ڳ������ʱ�����Դ�������ȡ����Щ��Ϣ���Ϳ��Ը����ڴ�й©��������
    if (Tracer::Ready)
    {
        NewTrace.Add(p, file, line);//���һ����Ŀ
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

//���������ĺ��������������Ӧ��Ҫ����void* operator new(size_t size, const char* file, long line)������ȴ���������
//������Ϊstd::map<void*, Entry> mapEntry_;map�����ڲ�ҲҪͨ��allocator�����ڴ棬���ڴ������ʱ�������operator new����������õ�operator new
//������û��#define new new(__FILE__, __LINE__)�����������õ��ǵ��õ��������operator new��
//������������������Add�����е�mapEntry_[p] = Entry(file, line);�ڲ�Ҳ�����operator new����operator new�ֵ�����Add�������������޵ݹ�
// void* operator new(size_t size)
// {
//     //������ô��ռ�
//     void* p = malloc(size);
//     //���ļ�������Ϣ��ӵ�ĳ�������У��ڳ������ʱ�����Դ�������ȡ����Щ��Ϣ���Ϳ��Ը����ڴ�й©��������
//     if (Tracer::Ready)
//     {
//         NewTrace.Add(p, "?", 0);//���һ����Ŀ
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
    //������ô��ռ�
    void* p = malloc(size);
    //���ļ�������Ϣ��ӵ�ĳ�������У��ڳ������ʱ�����Դ�������ȡ����Щ��Ϣ���Ϳ��Ը����ڴ�й©��������
    if (Tracer::Ready)
    {
        NewTrace.Add(p, file, line);//���һ����Ŀ
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
    //������ô��ռ�
    void* p = malloc(size);
    //���ļ�������Ϣ��ӵ�ĳ�������У��ڳ������ʱ�����Դ�������ȡ����Щ��Ϣ���Ϳ��Ը����ڴ�й©��������
    if (Tracer::Ready)
    {
        NewTrace.Add(p, "?", 0);//���һ����Ŀ
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