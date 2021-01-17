#include "Calc.h"

// SymbolTable symTbl_;//���ű��䣬������Ҫ����
// FunctionTable funTbl_;//���������
// Storage storage_;//�������䣬ѧҽ��Ҫ���л�
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