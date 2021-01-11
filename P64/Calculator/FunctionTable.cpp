#include <cmath>
#include <cassert>
#include <iostream>

#include "FunctionTable.h"
#include "SymbolTable.h"
#include "DebugNew.h"

struct FunctionEntry
{
    PtrFun pFun_;
    char* funName_;
};

FunctionEntry Entrys[] =
{
    log, "log",
    log10, "log10",
    exp, "exp",
    sqrt, "sqrt",
    sin, "sin",
    cos, "cos",
    tan, "tan",
    sinh, "sinh",
    cosh, "cosh",
    tanh, "tanh",
    asin, "asin",
    acos, "acos",
    atan, "atan"
}
//数组中有多少个条目
FunctionTable::FunctionTable(SymbolTable& tbl) : size_(sizeof(Entrys) / sizeof(Entrys[0]))
{
    Init();
}

void FunctionTable::Init(SymbolTable& tbl)
{
    std::cout<<"function list:"<<std::endl;
    pFuns_ = new PtrFun[size_];//new了一个函数指针数组
    for (unsigned int i = 0; i < size_; ++i)
    {
        pFuns_[i] = Entrys[i].pFuns_;
        //变量，函数都是一个符号，返回其对应的id
        unsigned int j = tbl.Add(Entrys[i].funName_);
        assert(i == j);
        std::cout<<Entrys[i].funName_<<std::endl;//列出函数名
    }
}

FunctionTable::~FunctionTable()
{
    delete [] pFuns_;
}