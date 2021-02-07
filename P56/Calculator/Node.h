#ifndef _NODE_H
#define _NODE_H

#include <cassert>
#include <memory>
#include <vector>
#include "FunctionTable.h"

class Storage;

//��1�������á���ֹ���󿽱���eg��ʾ
//Noncopyable���ܹ��������Ϊ�������û���壬���������̳�
class Noncopyable
{
protected:
    Noncopyable() {};
    ~Noncopyable() {};
private:
    Noncopyable(const Noncopyable&);
    const Noncopyable& operator=(const Noncopyable&);
};

//��private�̳е�ԭ���ǣ���û�м̳�Noncopyable��Ľӿڣ������ⲻ�ǽӿڼ̳У�����ʵ�ּ̳�
//ʵ�ּ̳У��������û�����ڲ�����������������������ڲ�ʹ�ã������ܳ�Ϊ�������ӿ�
//Node����˶������壬��Ϊ��Ҫ����Node��Ҫ�ȹ���Noncopyable����Noncopyable�Ȳ��ܿ������죬Ҳ���ܸ�ֵ��
class Node : private Noncopyable
{
public:
    //ÿ���ڵ㶼��һ������Ĵ��麯��
    //��Node���ڶ�̬�������඼Ҫʵ��Calc
    //Calc����Ϊconst�ģ���ΪCalc����ı���ĳ�Ա
    virtual double Calc() const = 0;
    //��Node�Ƕ�̬�࣬��������ҲҪ����Ϊ�������������������ָ��ָ�����������
    //ͨ������ָ���ͷŶ����ʱ���ǲ���������������������

    //Ĭ�Ͻڵ㶼������ֵ,ֻ�б����ڵ�����ֵ
    virtual bool IsLvalue() const
    {
        return false;
    }
    
    //ֻ�б����ڵ��и�ֵ�ķ����������ڵ㶼û��
    virtual void Assign(double)
    {
        assert(!"Assign called incorrectlly");//��XX���ַ�������ģ�ȡһ����Ϊ�ٵģ�Ĭ������¶���Ϊ�ٵ�
    }
    
    virtual ~Node() {};
};

//NumerNodeҪʵ��������麯��Calc��Ϊ�����ࣻ��ûʵ�֣����ǳ�����
class NumberNode : public Node
{
public:
    NumberNode(double number) : number_(number) {}
    double Calc() const;
private:
    const double number_;//��const��ԭ����Ϊnumber_��ʼ����Ͳ���ı�
};

//BinaryNode�ڵ���2���ӽڵ�
//BinaryNode��û��ʵ��Calc������BinaryNode����Ȼ�ǳ����ֻ࣬�����������࣬�ӡ������ˡ����ڵ��֪������μ���
//��ǰ�ڴ�й©�ı���ԭ����û��~BinaryNode��������������BinaryNode����û�취�ͷţ�������������û�취�ͷţ������������е�ָ��û���ͷ�
class BinaryNode : public Node
{
public:
    BinaryNode(std::auto_ptr<Node>& left, std::auto_ptr<Node> right)//����������������ã���������һ������ָ�뱾��Ŀ�������
        : left_(left), right_(right) {}
    ~BinaryNode();//�ǵ�Ҫ�ͷ�left_��right_�ڵ�
protected:
    // Node* const left_;//const�����ã�ָ�벻�ܸı䣨��ָ�벻��ָ�������Ľڵ㣩��������ָ����ָ������ݲ��ܸı�
    // Node* const right_;
    //ԭ��ָ��֧�ֵ������﷨������ָ�붼֧�֣�ʲô->,*�������=�������
    std::auto_ptr<Node> left_;//����Ȩת�Ƶ�������ָ�룬���Բ���Ҫ��������ȥdelete
    std::auto_ptr<Node> right_;
    
};

//��BinaryNode��ȣ���ֻ��1������
//UnaryNodҲ�ǳ����࣬��Ϊ��û��ʵ��Calc����
class UnaryNode : public Node
{
public:
    UnaryNode(std::auto_ptr<Node>& child)
        : child_(child) {}
    ~UnaryNode();
protected:
    // Node* const child_;
    std::auto_ptr<Node> child_;
}


class FunctionNode : public UnaryNode
{
public://��һ���ӽڵ㣬����һ�������ڵ�
    FunctionNode(std::auto_ptr<Node>&  child, PtrFun pFun) : UnaryNode(child), pFun_(pFun) {}
    double Calc() const;
private:
    PtrFun pFun_;//����ָ��
};
//�����ڵ�ļ��㷽��

// //�ӷ�����ڵ�AddNode
// class AddNode : public BinaryNode
// {
// public:
// //���캯����ʼ����Ҫ���û��ಿ�ֵĹ��캯��
//     AddNode(Node* left, Node* right)
//         : BinaryNode(left, right) {}
//     //Ҫʵ��Calc������AddNode���Ǿ�����
//     double Calc() const;
// };

// class SubNode : public BinaryNode
// {
// public:
//     SubNode(Node* left, Node* right)
//         : BinaryNode(left, right) {}
//     double Calc() const;
// };

// class MultiplyNode : public BinaryNode
// {
// public:
//     MultiplyNode(Node* left, Node* right)
//         : BinaryNode(left, right) {}
//     double Calc() const;
// };

// class DivideNode : public BinaryNode
// {
// public:
//     DivideNode(Node* left, Node* right)
//         : BinaryNode(left, right) {}
//     double Calc() const;
// };

class UminusNode : public UnaryNode
{
public:
    UminusNode(std::auto_ptr<Node> & child)
        : UnaryNode(child) {}
    double Calc() const;
};

//MultiplyNodeû��ʵ��Calc����������һ��������
class MultipleNode : public Node
{
public:
    MultipleNode(std::auto_ptr<Node>& node)
    {
        //��ӵ�һ���ڵ㡣��һ���ڵ��������ģ�����-7-5+1����-7���ǵ�һ���ڵ㣬�ڽ�����ʱ�����Ѿ�����NumberNode
        //��Ӧ����UminusNode���������Ѿ��ܹ��������ˣ�Ӧ�ð������������ģ�+��-7
        AppendChild(node, true);
    }
    void AppendChild(std::auto_ptr<Node>& node, bool positive)
    {
        childs_.push_back(node.release());//Ԫ��������Node*,���ܷ�������ָ�룬��Ӧ�÷���ԭ��ָ��:�ͷ�����Ȩ�󴫽�������
        positive_.push_back(positive);
    }
    ~MultipleNode();
private:
    //�кܶ��Ӵ����������������
    std::vector<Node*> childs_;//vector�����ŵ���Node*
    std::vector<bool> positive_;//�ڵ��������
};

class SumNode : public : MultipleNode
{
public:
    SumNode(std::auto_ptr<Node>& node)
        : MultipleNode(node) {}
    double Calc() const;
};

//�˻��ڵ�
class ProductNode : public : MultipleNode
{
public:
    SumNode(std::auto_ptr<Node>& node)
        : MultipleNode(node) {}
    double Calc() const;
};


class VariableNode: public Node
{
public:
    VariableNode(unsigned int id, Storage& storage)
        : id_(id), storage_(storage) {}
    double Calc() const;
    bool IsLvalue() const;
    void Assign(double val);
private:
    const unsigned int id_;
    Storage& storage_;//�����ڵ��ֵ��Storage���л�ȡ��Storage���д洢��ĳ��������ֵ��������ҪStorage���һ������
};

class AssignNode : public BinaryNode
{
public:
//���캯����ʼ����Ҫ���û��ಿ�ֵĹ��캯��
    AssignNode(std::auto_ptr<Node>& left, std::auto_ptr<Node>& right)
        : BinaryNode(left, right) 
        {
           assert(left->IsLvalue());//������һ����ֵ�ڵ㣬�ܹ�����ֵ�� 
        }
    //Ҫʵ��Calc����
    double Calc() const;
};


#endif/* _NODE_H */