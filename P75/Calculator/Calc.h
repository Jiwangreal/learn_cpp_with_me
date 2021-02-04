#ifndef _CALC_H_
#define _CALC_H_


#include <string>

#include "SymbolTable.h"
#include "Storage.h"
#include "FunctionTable.h"
#include "Serial.h"

class Parser;

class Calc : public Serializable
{
    //��Parser������Ϊ��Ԫ�����Է���Parser�෽�����Calc���е�˽�г�Ա
    friend class Parser;
public:
    //���ű������֮�󣬴��ݽ�ȥ���캯�������캯�����ʱ��ͽ�FunctionEntry�еķ���ע���ȥ��
    Calc() : funTbl_(symTbl_) storage_(symTbl_)  {} 
    void Serialize(Serializer& out) const;
    void DeSerialize(DeSerializer& in);
    void ListFun() const;
    void ListVar() const;
private:
    bool GetVariableValue(unsigned int id, double& val) const;
    //��Ϊ���ﲻ�����ã���Ҫ����ͷ�ļ�include������������ʹ��ǰ��������
    //SymbolTable�࣬Storage����Calc��Ĺ�ϵ����Ϲ�ϵ��������������Calc��������
    //���⣬SymbolTable����Ҫ��Storage����֮ǰ����,SymbolTable��������Ϻ󴫵ݸ�Storage����
    // SymbolTable symTbl_;
    // Storage storage_;

    PtrFun GetFunction(unsigned int id) const 
    { 
        return funTbl_.GetFunction(id);//�Ӻ�����GetFunction�л�ȡ
    }

    //��һ��id���ж����Ƿ���һ���Ϸ��ĺ���
    bool IsFunction(unsigned int id) const
    {
        return id < funTbl_.Size();
    }

    unsigned int FindSymbol(const std::string& str) const;
    unsigned int AddSymbol(const std::string& str);
    Storage GetStorage()//��д��const Storage GetStorage() const��ԭ���ǣ��ܹ�ȥ����storage_
    { 
        return storage_; 
    }
    //����������ʼ���б��˳�����޹صģ�����߶���Ĵ����йأ����Թ���Ĵ����ǣ��ȹ���symTbl_,�ٹ���funTbl_�������storage_
    //��˳�����ʼ���б��˳��д��һ�����ÿ���
    //Ϊʲô�������죿��Ϊ�������еĺ����ǹ̶��ģ�Storage�еı������ǹ̶��ģ��������̶��ķ���ǰ�棬���̶��ķ��ں���
    //���Ժ������еķ��ţ��ڷ��ű��е�λ���Ǵ�0��ʼ�ģ�������void FunctionTable::Init(SymbolTable& tbl)�л��ж��ԣ�assert(i == j);
    //�����з��ű��⣬����Ҫ�к�����
    SymbolTable symTbl_;
    FunctionTable funTbl_;//FunctionTabl������Ҫ����SymbolTable���ű�֮����ΪFunctionTable������SymbolTable
    Storage storage_;//����������
};

#endif /* _CALC_H_ */

