#ifndef _CALC_H_
#define _CALC_H_


#include <string>

#include "SymbolTable.h"
#include "Storage.h"
#include "FunctionTable.h"
#include "Serial.h"

class Parser;

class Calc : public Serializable
{
    //将Parser类声明为友元，可以方便Parser类方便访问Calc类中的私有成员
    friend class Parser;
public:
    //符号表构造完毕之后，传递进去构造函数表，构造函数表的时候就将FunctionEntry中的符号注册进去了
    Calc() : funTbl_(symTbl_) storage_(symTbl_)  {} 
    void Serialize(Serializer& out) const;
    void DeSerialize(DeSerializer& in);
    void ListFun() const;
    void ListVar() const;
private:
    bool GetVariableValue(unsigned int id, double& val) const;
    //因为这里不是引用，需要将其头文件include进来，而不能使用前向声明了
    //SymbolTable类，Storage类与Calc类的关系是组合关系，其生命周期由Calc类来管理
    //此外，SymbolTable对象要在Storage对象之前构造,SymbolTable对象构造完毕后传递给Storage对象
    // SymbolTable symTbl_;
    // Storage storage_;

    PtrFun GetFunction(unsigned int id) const 
    { 
        return funTbl_.GetFunction(id);//从函数表GetFunction中获取
    }

    //给一个id，判定它是否是一个合法的函数
    bool IsFunction(unsigned int id) const
    {
        return id < funTbl_.Size();
    }

    unsigned int FindSymbol(const std::string& str) const;
    unsigned int AddSymbol(const std::string& str);
    Storage GetStorage()//不写成const Storage GetStorage() const的原因是：能够去更改storage_
    { 
        return storage_; 
    }
    //构造次序与初始化列表的顺序是无关的，与这边定义的次序有关，所以构造的次序是，先构造symTbl_,再构造funTbl_，最后构造storage_
    //其顺序与初始化列表的顺序写成一样，好看点
    //为什么这样构造？因为函数表中的函数是固定的，Storage中的变量不是固定的，即：将固定的放在前面，不固定的放在后面
    //所以函数表中的符号，在符号表中的位置是从0开始的，所以在void FunctionTable::Init(SymbolTable& tbl)中会有断言：assert(i == j);
    //除了有符号表外，还需要有函数表
    SymbolTable symTbl_;
    FunctionTable funTbl_;//FunctionTabl函数表要放在SymbolTable符号表之后，因为FunctionTable依赖于SymbolTable
    Storage storage_;//最后构造变量表
};

#endif /* _CALC_H_ */

