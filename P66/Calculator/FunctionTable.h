#ifndef _FUNCTION_TABLE_H_
#define _FUNCTION_TABLE_H_

class SymbolTable;

//typedef一个函数指针
typedef double (*PtrFun)(double);

class FunctionTable
{
public:
    FunctionTable(SymbolTable& tbl);
    ~FunctionTable();

    void Init(SymbolTable& tbl);//初始化

    unsigned int Size() const
    {
        return size_;
    }

    PtrFun GetFunction(unsigned int id) const
    {
        return pFuns_[id];
    }

    unsigned int GetSize() const
    {
        return size_;
    }

private:
    PtrFun* pFuns_;//数学函数的入口地址的一个数组
    unsigned int size_;
};



#endif//_FUNCTION_TABLE_H_

