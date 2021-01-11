#include <cmath>
#include <cassert>
#include <iostream>
#include "Storage.h"
#include "SymbolTable.h"

Storage::Storage(SymbolTable& tbl)
{
    //先添加常量到符号表中
    AddConstant(tbl);
}

void Storage::Clear()
{
    cells_.clear();
    inits_.clear();
}

bool Storage::IsInit(unsigned int id) const
{
    //id不能超过cells_元素中的最大值
    //下标就是id，第0变量是否初始化了，那么就是inits_[0]
    return id < cells.size() && inits_[id];
}

//添加2个常量
void Storage::AddConstant(SymbolTable& tbl)
{
    
    std::cout<<"variable list:"<<std::endl;
    unsigned int id = tbl.Add("e");
    AddValue(id, exp(1.0));//exp(1.0):代表e的1一次方
    std::cout<<"e = "<<exp(1.0)<<std::endl;//列出变量表

    id = tbl.Add("pi");
    AddValue(id, 2.0*acos(0.0));//pi=2*acos(0),acos是反余弦函数
    std::cout<<"pi = "<<2.0*acos(0.0)<<std::endl;//列出变量表
}

double Storage::GetValue(unsigned int id) const
{
    assert(id < cells_.size());
    return cells_[id];
}

void Storage::SetValue(unsigned int id, double val)
{
    assert(id <= cells_.size());
    if (id < cells_.size())//id已经存在重新赋值
    {
        cells_[id] = val;
        inits_[id] = true;
    }
    else if (id == cells_.size())//id超过size，也就是说id所对应的变量不存在
    {
        AddValue(id, value);
    }
    
}

void Storage::AddValue(unsigned int id, double val)
{
    //为啥不使用push_back?
    /*
    比如cells_空间里面有6个元素了，此时cells_.push_back(val);此时向量里面的空间并不等于7，有可能是12，
    会导致size为12，实际上并没存放12个变量或常量，我们希望向量cells_存放多少变量或常量，其空间就为多少，即size就为
    多少，所以不用
    */
   //先扩充一个容量
   cells_.resize(id+1);
   inits_.resize(id+1);
   cells_[id] = value;
   inits_[id] = true;
}

