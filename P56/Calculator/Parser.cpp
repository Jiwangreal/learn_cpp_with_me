
#include <cstring>
#include <cassert>
#include <iostream>
#include "Parser.h"
#include "Scanner.h"//因为会使用到Scanner的一些接口进行扫描
#include "Node.h"
#include "Calc.h"
#include "Exception.h"
#include "DebugNew.h"

//引用的初始化只能才初始化列表中进行初始化
Parser::Parser(Scanner& scanner, Calc& calc)
    : scanner_(scanner), tree_(0), calc_(calc), status_(STATUS_OK)
{

}

/*
为什么将析构函数写在这里？
因为编译的时候有一个警告：删除指向不完整Node类型的指针，没有调用析构函数
因为tree_是Node类型，delete会调用Node的析构函数，但是Node在这里是前向声明，即看不到它的析构函数，所以编译的过程中有警告
解决办法：
（1）在Parser.h中包含Node.h
（2）将析构函数的实现放到cpp文件中
*/
Parser::~Parser()
{
    // delete tree_;//如果tree_是空指针，则不会调用void operator delete(void*p)
}

STATUS Parser::Parse()
{
    tree_ = Expr();//解析完后，将整个表达式赋值给tree_

    //解决1+1=2的bug，增加一个IsDone方法判断是否完全解析
    if (!scanner_.IsDone())
    {
        status_ = STATUS_ERROR;
    }

    return status_;
}

//解析表达式:
std::auto_ptr<Node> Parser::Expr()
{
    //Term()返回一个智能指针，赋值给node，所有权就转移到了node，Term()返回一个智能指针所持有的资源就交给node变量来管理
    //所有权转移到node
    std::auto_ptr<Node> node = Term();//解决1+1=2的bug，首先遇到1
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
        //内存泄漏：multipleNode是一个局部变量，SumNode本身是不被释放的，即存在内存泄漏
        //此时的表达式，Expr ：= Term{ ( '+'| '-' ) Term}
        //使用智能指针的哲学就是：一旦遇到原生指针，就用智能指针管理起来，尽量不要使用原生指针，原生指针的释放不是自动的
        //再栈展开的过程中，在堆山分配的内存multipleNode是不会自动释放的，用智能指针对象来管理
        //智能指针本身是一个类对象，在栈展开的过程中会调用析构函数，析构函数会释放其持有的资源
        // MultipleNode* multipleNode = New SumNode(node);//解决1+1=2的bug，接着把1添加到multipleNode里面
        std::auto_ptr<multipleNode> multipleNode(new SumNode(node));
        //子节点有多个，所以用循环
        do
        {
            scanner_.Accept();
            std::auto_ptr<Node> nextNode = Term();//解决1+1=2的bug，接着解析下一个1
            multipleNode->AppendChild(nextNode, (token == TOKEN_PLUS));//解决1+1=2的bug，又把它添加进来
            token = scanner_.Token();//更新当前扫描的状态，即：看下一个字符是加法还是减法，直到遇到其他负号，就不是SumNode的子代了
                                    //解决1+1=2的bug，然后遇到等号，跳出循环了，导致2没有完全解析

        }while(token == TOKEN_PLUS || token == TOKEN_MINUS)
        node = multipleNode;
    }
  

    return node;//Expression is Term
}

//解析项
std::auto_ptr<Node> Parser::Term()
{
    std::auto_ptr<Node> node = Factor();
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
        // MultipleNode* multipleNode = New ProductNode(node);
        std::auto_ptr<multipleNode> multipleNode(new ProductNode(node));
        //子节点有多个，所以用循环
        do
        {
            scanner_.Accept();
            std::auto_ptr<multipleNode> nextNode = Factor();
            multipleNode->AppendChild(nextNode, (token == TOKEN_MULTIPLY));
            token = scanner_.Token();//更新当前扫描的状态，即：看下一个字符是加法还是减法，直到遇到其他负号，就不是SumNode的子代了

        }while(token == TOKEN_MULTIPLY || token == TOKEN_DIVIDE)
        node = multipleNode;
    }
    else if (token == TOKEN_ASSIGN) //项还能够解析等号，比如x=5,x是项，5是表达式；x=y=5，x是项，y=5是表达式
    {
        //Expr:=Term=Expr, :=这是一种BNF式的表达法
        scanner_.Accept();
        std::auto_ptr<Node> nodeRight = Expr();
        if (node->IsLvalue())
        {
            //new AssignNode(node, nodeRight)是原生指针，所有权转移到了std::auto_ptr<Node>智能指针对象
            //智能指针在赋值的时候，控制权又转移给了node
            node = std::auto_ptr<Node>(new AssignNode(node, nodeRight));//这里是对创建的变量节点，进行的赋值操作
        }
        else
        {
            status_ = STATUS_ERROR;
            // std::cout<<"The left-hand side of an assignment must be a variable"<<std::endl;//必须是左值节点
            //Todo 抛出异常
            throw SyntaxError("The left-hand side of an assignment must be a variable");
        }
        
    }
    return node;//Expression is Factory
}

//解析因式
std::auto_ptr<Node> Parser::Factor()
{
    //or (Expression)
    std::auto_ptr<Node> node;//智能指针不能写=0
    EToken token = scanner_.Token();
    if (token == TOKEN_LPARENTHESIS) //遇到左括号，说明是一个因式
    {
        scanner_.Accept(); //accept '('
        node = Expr();//先解析表达式，判定它是否是一个项，右边应该有个右括号
        if (scanner_ == TOKEN_RPARENTHESIS)
        {
            scanner_.Accept(); //accept ')'
        }
        else
        {
            status = STATUS_ERROR;
            //to do:抛出异常
            // std::cout<<"missing parenthesis"<<std::endl;
            throw SyntaxError("Missing parenthesis");
            // node = 0;//智能指针不能写=0
        }
    }
    else if (token == TOKEN_NUMBER)
    {
        //内存泄漏出现的位置：new了一个NumberNode，从来没有去delete这个node
        //因为node是局部变量的指针，当这个函数返回的时候，无法得到node指针，没有办法去delete它，没办法去释放它，因而这里存在内存泄漏
        node = std::auto_ptr<Node>(new NumberNode(scanner_.Number()));//新建一个数字节点
        scanner_.Accept();
    }
    else if(token == TOKEN_MINUS)
    {
        scanner_.Accept();//接受一个负号，目的是指针偏移到下一个字符，让下一次的解析做准备

        //内存泄漏：new的地方没有调用delete
        node = std::auto_ptr<Node>(new UminusNode(Factor()));//传递一个子节点进去，这个子节点就是因式
    }
    else if (token == TOKEN_IDENTIFIER)//解析到一个标识符
    {
        std::string symbol = scanner_.GetSymbol();
        unsigned int id = calc_.FindSymbol(symbol);
        scanner_.Accept();

        //标识符可能是变量，也可能是函数
        //log10(),先扫描一个log，是一个标识符，接着扫描到一个左括号，那么它就是一个函数了
        if (scanner_.Token() == TOKEN_LPARENTHESIS)
        {
            scanner_.Accept(); //accpet '(',//接受一个左括号
            node = Expr();//解析是否是一个表达式，eg：sqrt(4+5)
            if (scanner_.Token() == TOKEN_RPARENTHESIS)//accept ')'
            {
                scanner_.Accept(); //是否是一个右括号，若是则接受它
                //找到一个符号，判定它是否是一个合法的函数
                if (id != SymbolTable::IDNOTFOUND && calc_.isFunction(id))//解析到一个符号symbol，它是一个函数，并且函数在函数表中
                {
                    //将4+5作为他的孩子
                    //GetFunction获取函数指针，到底是哪一个函数
                    node = std::auto_ptr<Node>(new FunctionNode(node, calc_.GetFunction(id)));
                }
                else
                {
                    //输出不认识的函数
                    status_ = STATUS_ERROR;
                    // std::cout<<"Unknown function"<<"\""<<symbol<<"\""<<std::endl;
                    char buf[256] = {0};
                    sprintf(buf, "Unknow function \" %s \".", symbol.c_str());//symbol是string类型，
                    throw SyntaxError(buf);
                }
                
            }
            else
            {
                status_ = STATUS_ERROR;
                // std::cout<<"Missing paraenthesis in a function call."<<std::endl;
                throw SyntaxError("Missing paraenthesis in a function call.");
            }
            
        }
        else
        {
            if (id == SymbolTable::IDNOTFOUND)
            {
                id = calc_.AddSymbol(symbol);
            }
            node = std::auto_ptr<Node>(new VariableNode(id, calc_.GetStorage()));//创建一个变量节点
        }
    }
    else
    {   
        status = STATUS_ERROR;
        //to do:抛出异常
        // std::cout<<"Not a valid expression"<<std::endl;
        throw SyntaxError("Not a valid expression");
        // node = 0;
    }
        
    return node;
}


//注意：带const的成员函数与不带const的成员函数可以构成重载
double Parser::Calculate() const
{
    //智能指针不能与0比较，get方法获取其原生指针与0可以比较
    assert(tree_.get() != 0);//0,NULL都行
    //求表达式的值，实际上就是求其根节点的值
    return tree_->Calc();
}