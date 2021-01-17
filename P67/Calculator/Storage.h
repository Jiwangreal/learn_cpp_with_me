#ifndef _STORAGE_H
#define _STORAGE_H

#include <vector>
#include "Serial.h"
class SymbolTable;//这里是前向声明，需要在cpp文件中包含#include "SymbolTable.h"

class Storage : public Serializable
{
public:
    Storage(SymbolTable& tbl);
    void Serialize(Serializer& out) const;
    void DeSerialize(DeSerializer& in);
    void Clear();
    bool IsInit(unsigned int id) const;
    void AddConstant(SymbolTable& tbl);
    double GetValue(unsigned int id) const;
    void SetValue(unsigned int id, double val);
    void AddValue(unsigned int id, double val);
private:
    std::vector<double> cells_;
    std::vector<bool> inits_;
};




#endif /* _STORAGE_H */