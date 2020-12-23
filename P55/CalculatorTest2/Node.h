#ifndef _NODE_H_
#define _NODE_H_

class Node
{
public:
    Node();
    ~Node();
    void Calc() const
};

class NodePtr
{
public:
    //�൱���ڹ��캯���л�ȡ��Դ���������pNodeָ�룬���ݵ���ptr_ָ��
    explicit NodePtr(Node* ptr = 0 )
        : ptr_(ptr) {}

    //�������캯������Ϊother������ͷ�����Ȩ���ᷢ���ı䣬�����β�û����const
    NodePtr(NodePtr& other) : ptr_(other.Release) {}

    //���صȺ������
    //�뿽�����캯����һ���ĵط����ڣ��Ⱥ��������ζ����߶����Ѿ��Ǵ��ڵģ�other��Ҫ�ͷţ�Ȼ�����ͷ���������Ȩ��Ȼ���ٸ�ֵ
    NodePtr& operator=(NodePtr& other)
    {
        Reset(other.Release());//���ͷ�other������Ȩ
        return *this;
    }

    //�������������ͷ���Դ
    ~NodePtr() {delete ptr_;}//C++ delete ��ָ��û���⣬������C�����в���freeһ����ָ��

    //����*�����
    //Get()��Node*,ȡһ��*����Node�����ص������ã���ʱ������ÿ������캯�����������������ÿ������캯��
    Node& operator*() const {return *Get();}

    //����->�����
    Node* operator->() const {return Get();}
    Node* Get() const {return ptr_;}
    //�ͷ�����Ȩ����ָ���ÿռ���
    Node* Release()
    {
        Node* tmp = ptr_;
        ptr_ = 0;//����Ȩ�ͷŵĹؼ�
        return tmp;
    }
    void Reset(Node* ptr = 0)//��ָ�����ó�other���ͷŵ����ָ��
    {
        if (ptr_ != ptr)
        {
            delete ptr_;
        }
        ptr_ = ptr;
    }

private:
    Node* ptr_;
};


#endif /* _NODE_H_ */