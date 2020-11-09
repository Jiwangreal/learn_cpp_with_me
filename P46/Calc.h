#ifndef _CALC_H_
#define _CALC_H_

#include "SymbolTable.h"
#include "Storage.h"
#include <string>

class Parser;

class Calc
{
    //��Parser������Ϊ��Ԫ�����Է���Parser�෽�����Calc���е�˽�г�Ա
    friend class Parser;
public:
    Calc() : storage_(symTbl_) {}
private:
    //��Ϊ���ﲻ�����ã���Ҫ����ͷ�ļ�include������������ʹ��ǰ��������
    //SymbolTable�࣬Storage����Calc��Ĺ�ϵ����Ϲ�ϵ��������������Calc��������
    //���⣬SymbolTable����Ҫ��Storage����֮ǰ����,SymbolTable��������Ϻ󴫵ݸ�Storage����
    SymbolTable symTbl_;
    Storage storage_;

    unsigned int FindSymbol(const std::string& str) const;
    unsigned int AddSymbol(const std::string& str);
    Storage GetStorage()//��д��const Storage GetStorage() const��ԭ���ǣ��ܹ�ȥ����storage_
    { 
        return storage_; 
    }
};

#endif /* _CALC_H_ */

