#ifndef _TRACER_H_
#define _TRACER_H_

#include <map>

//release������debug��������release����һ��û������ĸ���
//���û�ж���NODEBUG������Ĵ���Ͳ������ˣ���ǰ��vs2008���������ٵģ��������˵��
#ifndef NODEBUG

//����ȫ�ֵ�new��delete�����
//�ߴ��С���ļ����ƣ����ڵ���
void* operator new(size_t size, const char* file, long line);
//����new��ҲҪ����delete��delete�����2������û��:const char*, long���Ͳ��ø�������
void operator delete(void* p, const char*, long);

//����operator delete(void*p);Ŀ���Ǽ���������
void operator delete(void*p);//��void* operator new(size_t size);��new��������ض�Ӧ��Ϊɶ��ô�£�������Ľ���

//Ŀ���Ǽ����󱨣�ʹ��vs2008��ϵ㷢�ֽ������cpp���е�����������԰���صĺ�����������
void operator delete[](void*p, const char*, long);//��void* operator new[](size_t size, const char* file, long line);��new�������Ӧ����
                                                //void* operator new(size_t size, const char* file, long line);�������
void operator delete[](void*p);//��void* operator new[](size_t size);��Ӧ�����췽����������


//��Ȼ������delete����������Ӧ��new�����Ҳ��Ҫ����
void* operator new[](size_t size, const char* file, long line);
void* operator new[](size_t size);
void* operator new(size_t size);

class Tracer
{
private:
    class Entry
    {
    public:
        Entry(const char* file=0, long line=0)
            : file_(file), line_(line) {}
    const char* File() const {return file_;}//�����ļ�
    long Line() const {return line_}//������
    private:
        const char* file_;
        long line_;
    };

public:
    Tracer();
    ~Tracer();
    static bool Ready;//�Ƿ�ʼ����

    //����Add���������ļ��������ӵ�����map��
    void Add(void* p, const char* file, long line);
    //�Ƴ��ķ���
    void Remove(void* p);
    //Dump��������﷢�����ڴ�й©
    void Tracer::Dump();
private:
    //map���������ڴ�ʹ�õ���Ϣ,��һ��������ָ�룬����ڴ������ĸ��ļ�����һ�з���ģ��Ǽ����ڲ���Entry����
    std::map<void*, Entry> mapEntry_;
    int lockCount_;
    void Lock() {++lockCount_;}//�����ĺ���
    void UnLock() {--lockCount_;}//�����ĺ���

}


extern Tracer NewTrace;

#endif //NODEBUG

#endif //_TRACER_H