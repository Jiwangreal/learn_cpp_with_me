#ifndef _SYMBOL_TABLE_H_
#define _SYMBOL_TABLE_H_
#include <map>
#include <string>
#include "Serial.h"

class SymbolTable : public Serializable
{
    //直接放在public上面是私有的
public:
    //枚举量
    enum { INNOTFOUND = 0xffffffff }
    SymbolTable() : curId_(0) {}
    void Serialize(Serializer& out) const;
    void DeSerialize(DeSerializer& in);
    unsigned int Add(const std::string& str);
    unsigned int Find(const std::string& str) const;
    void Clear();
    std::string GetSymbolName(unsigned int id) const;
    unsigned int GetCurId() const { return curId_; }

private:
    std::map<std::string, unsigned int> dictionary_;
    unsigned int curId_;//当前最大值的id
};

#endif /* _SYMBOL_TABLE_H_ */