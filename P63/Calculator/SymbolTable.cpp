#include <algorithm>
#include "SymbolTable.h"
#include "Exception.h"

unsigned int SymbolTable::Add(const std::string& str)
{
    dictionary_[str] = curId_;
    return curId_++;//返回值是当前符号的id，然后再++
}
    
unsigned int SymbolTable::Find(const std::string& str) const
{
    map<const std::string, unsigned int>::const_iterator it;
    it = dictionary_.find(str);
    if (it != dictionary_.end() )
        return it->second;
    return INNOTFOUND; 
}
    //不等于end，说明找到了
void SymbolTable::Clear()
{
    dictionary_.clear();
    curId_ = 0;
}

//函数对象function object，反函数functor
//目的：让一个类对象使用起来像一个函数，本质上是重载括号运算符
/*
IsEqualId ie;
is();此时ie使用起来像一个函数
*/
//这是STL6大组件
//迭代器pair有2个要素：fist是string，second是unsigned int
class IsEqualId
{
public:
    IsEqualId(unsigned int id) : id_(id) {}
    bool operator(const std::pair<const std::string,unsigned int>& it) const
    {
        return it.second == id_;
    }
private:
    unsigned int id_;
};


std::string SymbolTable::GetSymbolName(unsigned int id) const
{
    //find_if(XX,XX,类)
    //将类传递进去，将类看成是一个函数
    map<const std::string, unsigned int>::const_iterator it;
    it = find_if(dictionary_begin(), dictionary_end(), IsEqualId(id));

    //没有找到的时候，抛出一个异常
    //根据id没有找到符号名称，在符号表中没有找到符号名称（变量不在符号表里面，一个函数也不在符号表里面）
    if (it == dictionary_.end())
    {
        throw Exception("Internal error: missing entry in symbol table");//entry:中文含义是项
    }


    return it->first;
}
