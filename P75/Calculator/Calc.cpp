#include "Calc.h"

// SymbolTable symTbl_;//符号表会变，所以需要序列
// FunctionTable funTbl_;//函数表不会变
// Storage storage_;//变量表会变，学医需要序列化
void Calc::Serialize(Serializer& out) const
{
    symTbl_.Serialize();
    storage_.Serialize();
}

void Calc::DeSerialize(DeSerializer& in)
{
   symTbl_.DeSerialize();
    storage_.DeSerialize();
}


unsigned int Calc::FindSymbol(const std::string& str) const
{
    return symbol_.Find(str);
}

unsigned int Calc::AddSymbol(const std::string& str)
{
    return symbol_.Add(str);
}

void Calc::ListFun() const
{
    for (unsigned int i = 0; i < funTbl_.GetSize(); ++i)
    {
        std::cout<<symbol_.GetSymbolName(i)<<std::endl;
    }
}

void Calc::ListVar() const
{
    for (unsigned int i = funTbl_.GetSize(); i <symbol_.GetCurId(); ++i)
    {
        //变量名
        string name = symbol_.GetSymbolName(i);
        //变量的值
        double val;
        if (GetVariableValue(i, val))
            std::cout<<name<<" = "<<val<<std::endl
        else
            std::cout<<name<<" = ? "<<std::endl;
    }
}

bool GetVariableValue(unsigned int id, double& val) const
{
    if (storage_.IsInit(id))
    {
        val = storage_.GetValue(id);
        return true;
    }

    return false;
}