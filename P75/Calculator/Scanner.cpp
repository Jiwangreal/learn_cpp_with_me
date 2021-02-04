#include <cctype>
#include <iostream>
#include "Scanner.h"

// Scanner::Scanner(const std::string& buf) : buf_(buf), curPos_(0)
// {
//     Accept();//一个字符一个字符的扫描
//     isEmpty = (token_ == TOKEN_END);//一开始就是空，解决：直接按回车会出错的bug
// }

//从输入流获取缓冲区，不是从buf缓冲区获取
Scanner::Scanner(std::istream& in) : in_(in)
{
    Accept();//一个字符一个字符的扫描
    isEmpty = (token_ == TOKEN_END);//一开始就是空，解决：直接按回车会出错的bug
}

bool Scanner::IsCommand() const
{
    return token_ == TOKEN_COMMAND;
}


bool Scanner::IsEmpty() const
{
    return isEmpty;//解决：直接按回车会出错的bug
}

bool Scanner::IsDone() const
{
    //说明已经扫描完毕了
    return token_ == TOKEN_END;//解决1+1=2的bug
}

double Scanner::Number() const
{
    return number_;
}

string Scanner::GetSymbol() const
{
    return symbol_;
}

EToken Scanner::Token() const
{
    return token_;
}

//忽略空白字符
// void Scanner::SkipWhite()
// {
//     while (isspace(buf_[curPos_]))
//         ++curPos_;
// }

void Scanner::ReadChar()
{
    //一个字符一个字符从流当中获取数据
    look_ = in.get();
    //获取一个字符可能是空白字符，这里将空白字符去掉
    //\t是制表符
    while ( look_ == ' ' || look_ == '\t')
        look_ = in_.get();//重新获取一个字符
}

void Scanner::Accept()
{
    // SkipWhite();//首先忽略空白字符
    ReadChar();
    switch (look_)
    {
    case '!'://如果遇到感叹号
        token_ = TOKEN_COMMAND;
        break;
    case '+':
        token_ = TOKEN_ADD;
        // ++curPos_;//因为现在传递进来的是一个标准输入，一个字符一个字符解析，所以不需要登记当前解析到的位置
        break;
    case '-':
        token_ = TOKEN_MINUS;
        // ++curPos_;
        break;
    case '*':
        token_ = TOKEN_MULTIPLY;
        // ++curPos_;
        break;
    case '/':
        token_ = TOKEN_DIVIDE;
        // ++curPos_;
        break;
    case '=':
        token_ = TOKEN_ASSIGN;
        // ++curPos_;
        break;
    case '(':
        token_ = TOKEN_LPARENTHESIS;
        // ++curPos_;
        break;
    case ')':
        token_ = TOKEN_RPARENTHESIS;
        // ++curPos_;
        break;
    case '0': case '1': case '2' : case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
    case '.':
        token_ = TOKEN_NUMBER;
        //当遇到数字的时候，先把数字归还回去，然后提取到number_变量中
        //这种方法自然就将一个字符串转换成了double类型
        in_.putback(look_);
        in_>>number_;//遇到数字，需要转换成数字

        // char* p;//实际上这里的指针并没有指向
        // //buf_是一个字符串，buf_[curPos_]是一个字符，相当于得到了内部字符串的字符
        // //这里的指针p，指针变量p本身发送改变，也就是说它指向了其他地方，改变了指针的指向
        // number_ = strtod(&buf_[curPos_], &p);//返回第一个不是数字的位置
        // //将地址p转换为数字curPos_，用以更新curPos_
        // curPos_ = p - &buf[0];// &buf[0]是字符串的首地址
        break;
    case '\0' : case '\n' : case '\r' : case EOF://认为表达式结束了
        token_ = TOKEN_END;
        break;
    default:
        //字母或者下划线打头的才是标识符(变量或者函数)
        if (isalpha(look_) || look_ == '_')
        {
            token_ = TOKEN_IDENTIFIER;
            symbol_.erase();
            // char ch = buf_[curPos_];
            do
            {
                symbol_ += look_;
                look_ = in.get();
                // ++curPos_;
                // ch = buf_[curPos_];
            } while (isalnum(ch) || ch == '_');
            //直到遇到它不是字母，下划线，数字为止，比如遇到一个空格或者+号(不是标识符)
            //多获取到的字符需要归还到流当中，以便下次解析
            in_.putback(look_);
            
        }
        else
        {
            token_ = TOKEN_ERROR;
        }
        
        break;
    }
}



void Scanner::AcceptCommand()
{
    ReadChar();//抹除掉!s filename中间的空格
    symbol_.erase();//将当前symbol_erase
    while (!isspace(look_))
    {
        symbol_ + = look_;//filename保存在symbol_中了
        look_ = in.get();
    }

}