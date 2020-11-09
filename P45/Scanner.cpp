#include "Scanner.h"
#include <cctype>

Scanner::Scanner(const std::string& buf) : buf_(buf), curPos_(0)
{
    Accept();//一个字符一个字符的扫描
}

double Scanner::Number() const
{
    return number_;
}

EToken Scanner::Token() const
{
    return token_;
}

//忽略空白字符
void Scanner::SkipWhite()
{
    while (isspace(buf_[curPos_]))
        ++curPos_;
}

void Scanner::Accept()
{
    SkipWhite();//首先忽略空白字符
    switch (buf_[curPos_])
    {
    case '+':
        token_ = TOKEN_ADD;
        ++curPos_;
        break;
    case '-':
        token_ = TOKEN_MINUS;
        ++curPos_;
        break;
    case '*':
        token_ = TOKEN_MULTIPLY;
        ++curPos_;
        break;
    case '/':
        token_ = TOKEN_DIVIDE;
        ++curPos_;
        break;
    case '(':
        token_ = TOKEN_LPARENTHESIS;
        ++curPos_;
        break;
    case ')':
        token_ = TOKEN_RPARENTHESIS;
        ++curPos_;
        break;
    case '0': case '1': case '2' : case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
    case '.':
        token_ = TOKEN_NUMBER;
        char* p;//实际上这里的指针并没有指向
        //buf_是一个字符串，buf_[curPos_]是一个字符，相当于得到了内部字符串的字符
        //这里的指针p，指针变量p本身发送改变，也就是说它指向了其他地方，改变了指针的指向
        number_ = strtod(&buf_[curPos_], &p);//返回第一个不是数字的位置
        //将地址p转换为数字curPos_，用以更新curPos_
        curPos_ = p - &buf[0];// &buf[0]是字符串的首地址
        break;
    case '\0' : case '\n' : case '\r' : case EOF://认为表达式结束了
        token_ = TOKEN_END;
        break;
    default:
        token_ = TOKEN_ERROR;
        break;
    }
}