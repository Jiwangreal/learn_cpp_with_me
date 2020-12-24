#include <cmath>
#include <cassert>
#include <iostream>
#include "Storage.h"
#include "SymbolTable.h"

Storage::Storage(SymbolTable& tbl)
{
    //����ӳ��������ű���
    AddConstant(tbl);
}

void Storage::Clear()
{
    cells_.clear();
    inits_.clear();
}

bool Storage::IsInit(unsigned int id) const
{
    //id���ܳ���cells_Ԫ���е����ֵ
    //�±����id����0�����Ƿ��ʼ���ˣ���ô����inits_[0]
    return id < cells.size() && inits_[id];
}

//���2������
void Storage::AddConstant(SymbolTable& tbl)
{
    
    std::cout<<"variable list:"<<std::endl;
    unsigned int id = tbl.Add("e");
    AddValue(id, exp(1.0));//exp(1.0):����e��1һ�η�
    std::cout<<"e = "<<exp(1.0)<<std::endl;//�г�������

    id = tbl.Add("pi");
    AddValue(id, 2.0*acos(0.0));//pi=2*acos(0),acos�Ƿ����Һ���
    std::cout<<"pi = "<<2.0*acos(0.0)<<std::endl;//�г�������
}

double Storage::GetValue(unsigned int id) const
{
    assert(id < cells_.size());
    return cells_[id];
}

void Storage::SetValue(unsigned int id, double val)
{
    assert(id <= cells_.size());
    if (id < cells_.size())//id�Ѿ��������¸�ֵ
    {
        cells_[id] = val;
        inits_[id] = true;
    }
    else if (id == cells_.size())//id����size��Ҳ����˵id����Ӧ�ı���������
    {
        AddValue(id, value);
    }
    
}

void Storage::AddValue(unsigned int id, double val)
{
    //Ϊɶ��ʹ��push_back?
    /*
    ����cells_�ռ�������6��Ԫ���ˣ���ʱcells_.push_back(val);��ʱ��������Ŀռ䲢������7���п�����12��
    �ᵼ��sizeΪ12��ʵ���ϲ�û���12����������������ϣ������cells_��Ŷ��ٱ�����������ռ��Ϊ���٣���size��Ϊ
    ���٣����Բ���
    */
   //������һ������
   cells_.resize(id+1);
   inits_.resize(id+1);
   cells_[id] = value;
   inits_[id] = true;
}

