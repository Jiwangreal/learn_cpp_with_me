#include "Calc.h"

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
        //������
        string name = symbol_.GetSymbolName(i);
        //������ֵ
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