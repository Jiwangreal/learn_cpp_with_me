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
    //相当于在构造函数中获取资源，将外面的pNode指针，传递到了ptr_指针
    explicit NodePtr(Node* ptr = 0 )
        : ptr_(ptr) {}

    //拷贝构造函数，因为other对象会释放所有权，会发生改变，所以形参没有用const
    NodePtr(NodePtr& other) : ptr_(other.Release) {}

    //重载等号运算符
    //与拷贝构造函数不一样的地方在于，等号运算符意味着左边对象已经是存在的，other先要释放，然后再释放它的所有权，然后再赋值
    NodePtr& operator=(NodePtr& other)
    {
        Reset(other.Release());//先释放other的所有权
        return *this;
    }

    //在析构函数中释放资源
    ~NodePtr() {delete ptr_;}//C++ delete 空指针没问题，但是在C语言中不能free一个空指针

    //重载*运算符
    //Get()是Node*,取一个*就是Node，返回的是引用，此时不会调用拷贝构造函数，不是引用则会调用拷贝构造函数
    Node& operator*() const {return *Get();}

    //重载->运算符
    Node* operator->() const {return Get();}
    Node* Get() const {return ptr_;}
    //释放所有权，将指针置空即可
    Node* Release()
    {
        Node* tmp = ptr_;
        ptr_ = 0;//所有权释放的关键
        return tmp;
    }
    void Reset(Node* ptr = 0)//将指针重置成other所释放的这个指针
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