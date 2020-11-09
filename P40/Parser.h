#ifndef _PARSER_H
#define _PARSER_H

//使用前向声明而不是包含Scanner的头文件的原因是，如果在cpp文件中多次包含了这样的头文件，使得生成的可执行文件增大
class Scanner;

//Parser类：根据扫描结果，进行扫描，递归下降解析，直到生成一颗树
class Parser
{
public:
    Parser(Scanner& scanner);
    void Parse();
    double Calculate() const;
private:
    Scanner& scanner_;
};



#endif /* _PARSER_H */