#include "Parser.h"
#include "Scanner.h"//因为会使用到Scanner的一些接口进行扫描
#include "Node.h"
#include "Calc.h"

#include <cassert>
#include <iostream>

//引用的初始化只能才初始化列表中进行初始化
Parser::Parser(Scanner& scanner, Calc& calc) : scanner_(scanner), tree_(0), calc_(calc)
{

}

void Parser::Parse()
{
    tree_ = Expr();//解析完后，将整个表达式赋值给tree_
}

//解析表达式:
Node* Parser::Expr()
{
    Node* node = Term();
    EToken token = scanner_.Token();
    // if (token == TOKEN_PLUS)//扫描到+
    // {
    //     scanner_.Accept();//accept+号，扫描下一个字符，看看是不是一个Expression
    //     Node* nodeRight = Expr();
    //     node = new AddNode(node, nodeRight);//返回的是加法节点，（左节点，右节点），Expression is Term + Expression
    // }
    // else if (token == TOKEN_MINUS)
    // {
    //     scanner_.Accept();
    //     Node* nodeRight = Expr();
    //     node = new SubNode(node, nodeRight);//Expression is Term - Expression
    // }
    if (token == TOKEN_PLUS || token == TOKEN_MINUS)
    {
        //此时的表达式，Expr ：= Term{ ( '+'| '-' ) Term}
        MultipleNode* multipleNode = New SumNode(node);
        //子节点有多个，所以用循环
        do
        {
            scanner_.Accept();
            Node* nextNode = Term();
            multipleNode->AppendChild(nextNode, (token == TOKEN_PLUS));
            token = scanner_.Token();//更新当前扫描的状态，即：看下一个字符是加法还是减法，直到遇到其他负号，就不是SumNode的子代了

        }while(token == TOKEN_PLUS || token == TOKEN_MINUS)
        node = multipleNode;
    }
  

    return node;//Expression is Term
}

//解析项
Node* Parser::Term()
{
    Node* node = Factor();
    EToken token = scanner_.Token();
    // if (token == TOKEN_MULTIPLY)
    // {
    //     scanner_.Accept();
    //     Node* nodeRight = Term();
    //     node = new MultiplyNode(node, nodeRight);//Term is Factory * Term
    // }
    // else if (token == TOKEN_DIVIDE)
    // {
    //     scanner_.Accept();
    //     Node* nodeRight = Term();
    //     node = new DivideNode(node, nodeRight);//Term is Factory / Term
    // }

    if (token == TOKEN_MULTIPLY || token == TOKEN_DIVIDE)
    {
        //此时的表达式，Expr ：= Factor{ ( '*'| '/' ) Factor}
        MultipleNode* multipleNode = New ProductNode(node);
        //子节点有多个，所以用循环
        do
        {
            scanner_.Accept();
            Node* nextNode = Factor();
            multipleNode->AppendChild(nextNode, (token == TOKEN_MULTIPLY));
            token = scanner_.Token();//更新当前扫描的状态，即：看下一个字符是加法还是减法，直到遇到其他负号，就不是SumNode的子代了

        }while(token == TOKEN_MULTIPLY || token == TOKEN_DIVIDE)
        node = multipleNode;
    }
    else if (token == TOKEN_ASSIGN) //项还能够解析等号，比如x=5,x是项，5是表达式；x=y=5，x是项，y=5是表达式
    {
        //Expr:=Term=Expr, :=这是一种BNF式的表达法
        scanner_.Accept();
        Node* nodeRight = Expr();
        if (node->IsLvalue())
        {
            node = new AssignNode(node, nodeRight);//这里是对创建的变量节点，进行的赋值操作
        }
        else
        {
            status_ = STATUS_ERROR;
            std::cout<<"The left-hand side of an assignment must be a variable"<<std::endl;//必须是左值节点
            //Todo 抛出异常
        }
        
    }


    return node;//Expression is Factory
}

//解析因式
Node* Parser::Factor()
{
    //or (Expression)
    Node* node = 0;
    EToken token = scanner_.Token();
    if (token == TOKEN_LPARENTHESIS) 
    {
        scanner_.Accept(); //accept '('
        node = Expr();//先解析表达式，右边应该有个右括号
        if (scanner_ == TOKEN_RPARENTHESIS)
        {
            scanner_.Accept(); //accept ')'
        }
        else
        {
            status = STATUS_ERROR;
            //to do:抛出异常
            std::cout<<"missing parenthesis"<<std::endl;
            node = 0;
        }
    }
    else if (token == TOKEN_NUMBER)
    {
        node = new NumberNode(scanner_.Number());//新建一个数字节点
        scanner_.Accept();
    }
    else if(token == TOKEN_MINUS)
    {
        scanner_.Accept();//接受一个负号，目的是指针偏移到下一个字符，让下一次的解析做准备
        node = new UminusNode(Factor());//传递一个子节点进去，这个子节点就是因式
    }
    else if (token == TOKEN_IDENTIFIER)//解析到一个标识符
    {
        std::string symbol = scanner_.GetSymbol();
        unsigned int id = calc_.FindSymbol(symbol);
        scanner_.Accept();
        if (id == SymbolTable::IDNOTFOUND)
        {
            id = calc_.AddSymbol(symbol);
        }
        node = new VariableNode(id, calc_.GetStorage());//创建一个变量节点
    }
    else
    {   
        status = STATUS_ERROR;
        //to do:抛出异常
        std::cout<<"Not a valid expression"<<std::endl;
        node = 0;
    }
        
        return node;
}



//注意：带const的成员函数与不带const的成员函数可以构成重载
double Parser::Calculate() const
{
    assert(tree_ != 0);//0,NULL都行
    //求表达式的值，实际上就是求其根节点的值
    return tree_->Calc();
}