#include <algorithm>
#include "SymbolTable.h"
#include "Exception.h"

unsigned int SymbolTable::Add(const std::string& str)
{
    dictionary_[str] = curId_;
    return curId_++;//����ֵ�ǵ�ǰ���ŵ�id��Ȼ����++
}
    
unsigned int SymbolTable::Find(const std::string& str) const
{
    map<const std::string, unsigned int>::const_iterator it;
    it = dictionary_.find(str);
    if (it != dictionary_.end() )
        return it->second;
    return INNOTFOUND; 
}
    //������end��˵���ҵ���
void SymbolTable::Clear()
{
    dictionary_.clear();
    curId_ = 0;
}

//��������function object��������functor
//Ŀ�ģ���һ�������ʹ��������һ�����������������������������
/*
IsEqualId ie;
is();��ʱieʹ��������һ������
*/
//����STL6�����
//������pair��2��Ҫ�أ�fist��string��second��unsigned int
class IsEqualId
{
public:
    IsEqualId(unsigned int id) : id_(id) {}
    bool operator(const std::pair<const std::string,unsigned int>& it) const
    {
        return it.second == id_;
    }
private:
    unsigned int id_;
};


std::string SymbolTable::GetSymbolName(unsigned int id) const
{
    //find_if(XX,XX,��)
    //���ഫ�ݽ�ȥ�����࿴����һ������
    map<const std::string, unsigned int>::const_iterator it;
    it = find_if(dictionary_begin(), dictionary_end(), IsEqualId(id));

    //û���ҵ���ʱ���׳�һ���쳣
    //����idû���ҵ��������ƣ��ڷ��ű���û���ҵ��������ƣ��������ڷ��ű����棬һ������Ҳ���ڷ��ű����棩
    if (it == dictionary_.end())
    {
        throw Exception("Internal error: missing entry in symbol table");//entry:���ĺ�������
    }


    return it->first;
}
