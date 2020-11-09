#ifndef _PARSER_H
#define _PARSER_H

//使用前向声明而不是包含Scanner的头文件的原因是，如果在cpp文件中多次包含了这样的头文件，使得生成的可执行文件增大
class Scanner;
class Node;//解决在 Node* Expr();中没有定义Node

enum STATUS
{
    STATUS_OK;
    STATUS_ERROR;
    STATUS_QUIT;
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
    Parser(Scanner& scanner);
    void Parse();
    Node* Expr();
    Node* Term();
    Node* Factor();
    double Calculate() const;
private:
    Scanner& scanner_;//这里是引用，即使Parser类销毁了，Scanner类也不不一定销毁，Parser类不负责Scanner类的生命周期
                    //若这里不是引用，Parser对象销毁，Scanner对象也跟着销毁，这就是组合关系了
                    //这里也可以用引用，但是会拷贝一个Scanner类对象拷贝到Parser类内部，组合的方式效率低一些，没必要用了
    Node* tree_;
    STATUS status_;
};



#endif /* _PARSER_H */