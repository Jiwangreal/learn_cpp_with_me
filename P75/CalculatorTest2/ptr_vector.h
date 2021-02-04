#ifndef _PTR_VECTOR_H_
#define _PTR_VECTOR_H_

#include <vector>
#include <memory>

template<typename T>
class ptr_vector : public std::vector<T*>
{
public:
    ~ptr_vector()
    {
        clear();
    }
    //重定义vector中的clear方法
    void clear()
    {
        //负责指针所指向内存空间的释放
        std::vector<T*>::iterator it;
        for (it = std::begin(); it != std::end(); ++it)
            delete *it;//it就是T*的指针，取*就是T*
    }

    //基类的clear释放自指针变量本身
    std::vector<T*>::clear();

    //将指针插入向量中时，执行operator new可能分配内存失败，即指针没有插入到向量中，
    //std::vector<T*>::clear();可能不会释放内存，存在内存泄漏
    //处理方法：将所有权转移到智能指针ptr对象上，即使内部内存空间分配失败。智能指针是一个局部对象
    //捕捉异常时，在栈展开的时候会释放对象，将其持有的val指针释放掉
    void push_back(T* const &val) 
    {
        std::auto_ptr<T*> ptr(val);
        std::vector<T*>::push_back(val);
        ptr.release();//程序运行到这里，说明operator new分配内存成功，ptr释放所有权
    }

    //增加一个接口：将一个智能指针插入到向量中
    //原生的vector是不能将指针插入到向量中的，如果_Ty是智能指针类型，意味着智能指针在释放所有权的时候
    //会更改内部的指针，将指针置为0，而这里的修饰是const，指针内部的数据成员是不能更改的
    void push_back(std::auto_ptr<T>& val)
    {
        //这里不要使用std::vector<T*>::push_back(val.release());
        //push_back()的operator new过后，且因为release()会释放所有权，造成这个指针成为野指针，没人管，造成内存泄漏
        std::vector<T*>::push_back(val.get());
        //插入成功后，释放所有权
        val.release();//会更改智能指针内部的数据成员的，release()表示智能指针释放所有权
    }

    //boost也有ptr_vector，考虑的内容更多

};





#endif // _PTR_VECTOR_H_