#ifndef _FUNCTION_TABLE_H_
#define _FUNCTION_TABLE_H_

class SymbolTable;

//typedefһ������ָ��
typedef double (*PtrFun)(double);

class FunctionTable
{
public:
    FunctionTable(SymbolTable& tbl);
    ~FunctionTable();

    void Init(SymbolTable& tbl);//��ʼ��

    unsigned int Size() const
    {
        return size_;
    }

    PtrFun GetFunction(unsigned int id) const
    {
        return pFuns_[id];
    }

private:
    PtrFun* pFuns_;//��ѧ��������ڵ�ַ��һ������
    unsigned int size_;
};



#endif//_FUNCTION_TABLE_H_

