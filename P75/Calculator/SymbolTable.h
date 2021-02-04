#ifndef _SYMBOL_TABLE_H_
#define _SYMBOL_TABLE_H_
#include <map>
#include <string>
#include "Serial.h"

class SymbolTable : public Serializable
{
    //ֱ�ӷ���public������˽�е�
public:
    //ö����
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
    unsigned int curId_;//��ǰ���ֵ��id
};

#endif /* _SYMBOL_TABLE_H_ */