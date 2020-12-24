//ע��Ҫ���Լ����̿��ͷ�ļ�����CPP��ͷ�ļ��ĺ��棬�������һЩ����������
#include <iostream>
#include "Tracer.h"
#ifndef NODEBUG

//��ʼ��
bool Tracer::Ready = false;

//lockCount_=0��ʾ�������
Tracer::Tracer() : lockCount_(0)
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
    //��ֹvoid* operator new(size_t size)�����ĵݹ����
    if (lockCount_ > 0)
        return;
    Tracer::Lock lock(*this);
    // Lock();//���ڸ��ٵ�״̬���Ǵ��ڼ�����״̬
    //ʹ���±�ķ�ʽ
    mapEntry_[p] = Entry(file, line);//Entry(file, line)����������û�����ֵ���operator new��operator new�ֽ��뵽Add������Ȼ���return��
                                    //�Ͳ��ٸ����ˣ��Ͳ��ᵼ��operator new�����ĵݹ������
    // Unlock();
}
//�Ƴ��ķ���
void Tracer::Remove(void* p)
{
    if (lockCount_ > 0)
        return;

    //��ΪTracer���Ƕ���࣬���ҽ���ǰ�����*this���ݽ�ȥ
    //���ڲ�����Tracer���еĹ��캯���е��õ�lock�����������������е���unlock����
    //lock��������Ҫ���ͷŵģ�����������������Ҫ�����õ�
    Tracer::Lock lock(*this);

    // Lock();
    std::vector<void*, Entry>::iterator it;
    it = mapEntry_.find(p);
    if (it != mapEntry_.end())
    {
        mapEntry_.erase(it);
    }
    // Unlock();
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
//ͨ����Ӽ�����lockCount_�����������
void* operator new(size_t size)
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