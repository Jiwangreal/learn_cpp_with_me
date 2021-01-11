#ifndef _PARSER_H
#define _PARSER_H

#include <memory>
//使用前向声明而不是包含Scanner的头文件的原因是，如果在cpp文件中多次包含了这样的头文件，使得生成的可执行文件增大
class Scanner;
class Node;//解决在 Node* Expr();中没有定义Node
class Calc;

enum STATUS
{
    STATUS_OK,
    STATUS_ERROR,
    STATUS_QUIT
};


//Parser类：根据扫描结果，进行扫描，递归下降解析，直到生成一颗树
//Parser类与Scanner类之间的关系是什么？
//依赖关系：一个类作为另一个类成员函数的参数，或者内部的局部变量调用了某个类的静态成员函数
//而Scanner作为Parser类的成员，而且是引用： Scanner& scanner_;
//说明：Scanner类与Parser类具有一定的固定关系，在Parser类的生命周期内都要对scanner_的引用固定关系
//所以把他们看成关联关系
class Parser
{
public:
    Parser(Scanner& scanner, Calc& calc);

    //没有提供析构函数，则编译器提供析构函数，编译器提供的构造函数是内联的：即在头文件这里直接给出析构函数
    //而析构函数要负责std::auto_ptr<Node> tree_;auto_ptr对象的释放，当它释放时，会调用它所持有的对象Node*对象的释放
    //编译器发现class Node;的Node是不完全声明，前向声明，即在这里~Parser() {}，并不知道Node的析构函数，所以在这里出现了这种警告
    // ~Parser() {}//在头文件这边给出析构函数与编译器提供的空的析构函数是一样的，函数体在头文件中直接给出，是内联的
                //解决办法就是在cpp文件中给出这个析构函数，但是没有实现
    ~Parser();//告警的解决办法
    // ~Parser();
    STATUS Parse();
    std::auto_ptr<Node> Expr();//将Node*改为智能指针： std::auto_ptr<Node>
    std::auto_ptr<Node> Term();
    std::auto_ptr<Node> Factor();
    double Calculate() const;
private:
    Scanner& scanner_;//这里是引用，即使Parser类销毁了，Scanner类也不不一定销毁，Parser类不负责Scanner类的生命周期
                    //若这里不是引用，Parser对象销毁，Scanner对象也跟着销毁，这就是组合关系了
                    //这里也可以用引用，但是会拷贝一个Scanner类对象拷贝到Parser类内部，组合的方式效率低一些，没必要用了
    std::auto_ptr<Node> tree_;
    STATUS status_;
    Calc& calc_;
};


#endif /* _PARSER_H */