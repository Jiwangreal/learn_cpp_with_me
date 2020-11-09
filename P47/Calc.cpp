#include "Calc.h"

unsigned int Calc::FindSymbol(const std::string& str) const
{
    return symbol_.Find(str);
}

unsigned int Calc::AddSymbol(const std::string& str)
{
    return symbol_.Add(str);
}