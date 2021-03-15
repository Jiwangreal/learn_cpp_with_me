#ifndef _NODE_H
#define _NODE_H

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

// //BinaryNode�ڵ���2���ӽڵ�
// //BinaryNode��û��ʵ��Calc������BinaryNode����Ȼ�ǳ����ֻ࣬�����������࣬�ӡ������ˡ����ڵ��֪������μ���
// class BinaryNode : public Node
// {
// public:
//     BinaryNode(Node* left, Node* right)
//         : left_(left), right_(right) {}
//     ~BinaryNode();//�ǵ�Ҫ�ͷ�left_��right_�ڵ�
// protected:
//     Node* const left_;//const�����ã�ָ�벻�ܸı䣨��ָ�벻��ָ�������Ľڵ㣩��������ָ����ָ������ݲ��ܸı�
//     Node* const right_;
// };

//����һ���������󡣱�ʾ+-*/
template <typename T>
class BinaryNode : public Node
{
public:
    BinaryNode(Node* left, Node* right)
        : left_(left), right_(right) {}
    ~BinaryNode();//�ǵ�Ҫ�ͷ�left_��right_�ڵ�
    {
        delete left_;
        delete right_;
    }

    //ʵ����һ��ģ�����ʱ����һ�������࣬Ҫ����Calc����
    double Calc() const
    {
        T op;
        return op(left_->Calc(), right_->Calc());
    }
protected:
    Node* const left_;//const�����ã�ָ�벻�ܸı䣨��ָ�벻��ָ�������Ľڵ㣩��������ָ����ָ������ݲ��ܸı�
    Node* const right_;
};


//��BinaryNode��ȣ���ֻ��1������
//UnaryNodҲ�ǳ����࣬��Ϊ��û��ʵ��Calc����
class UnaryNode : public Node
{
public:
    UnaryNode(Node* child)
        : child_(child) {}
    ~UnaryNode();
protected:
    Node* child_;
}
/*
//�ӷ�����ڵ�AddNode
class AddNode : public BinaryNode
{
public:
//���캯����ʼ����Ҫ���û��ಿ�ֵĹ��캯��
    AddNode(Node* left, Node* right)
        : BinaryNode(left, right) {}
    //Ҫʵ��Calc������AddNode���Ǿ�����
    double Calc() const;
};

class SubNode : public BinaryNode
{
public:
    SubNode(Node* left, Node* right)
        : BinaryNode(left, right) {}
    double Calc() const;
};

class MultiplyNode : public BinaryNode
{
public:
    MultiplyNode(Node* left, Node* right)
        : BinaryNode(left, right) {}
    double Calc() const;
};

class DivideNode : public BinaryNode
{
public:
    DivideNode(Node* left, Node* right)
        : BinaryNode(left, right) {}
    double Calc() const;
};
*/

class UminusNode : public UnaryNode
{
public:
    UminusNode(Node* child)
        : UnaryNode(child) {}
    double Calc() const;
};



#endif/* _NODE_H */