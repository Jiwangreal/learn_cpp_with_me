#ifndef _SYMBOL_TABLE_H_
#define _SYMBOL_TABLE_H_
#include <map>
#include <string>

class SymbolTable
{
    //Ã¶¾ÙÁ¿
    enum { INNOTFOUND = 0xffffffff }
public:
    SymbolTable() : curId_(0) {}
    unsigned int Add(const std::string& str);
    unsigned int Find(const std::string& str) const;
    void Clear();
    std::string GetSymbolName(unsigned int id) const;

private:
    std::map<std::string, unsigned int> dictionary_;
    unsigned int curId_;
};

#endif /* _SYMBOL_TABLE_H_ */