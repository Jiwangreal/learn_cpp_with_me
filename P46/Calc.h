#ifndef _CALC_H_
#define _CALC_H_

#include "SymbolTable.h"
#include "Storage.h"
#include <string>

class Parser;

class Calc
{
    //将Parser类声明为友元，可以方便Parser类方便访问Calc类中的私有成员
    friend class Parser;
public:
    Calc() : storage_(symTbl_) {}
private:
    //因为这里不是引用，需要将其头文件include进来，而不能使用前向声明了
    //SymbolTable类，Storage类与Calc类的关系是组合关系，其生命周期由Calc类来管理
    //此外，SymbolTable对象要在Storage对象之前构造,SymbolTable对象构造完毕后传递给Storage对象
    SymbolTable symTbl_;
    Storage storage_;

    unsigned int FindSymbol(const std::string& str) const;
    unsigned int AddSymbol(const std::string& str);
    Storage GetStorage()//不写成const Storage GetStorage() const的原因是：能够去更改storage_
    { 
        return storage_; 
    }
};

#endif /* _CALC_H_ */

