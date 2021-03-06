#include <cctype>
#include "Scanner.h"

Scanner::Scanner(const std::string& buf) : buf_(buf), curPos_(0)
{
    Accept();//一个字符一个字符的扫描
    isEmpty = (token_ == TOKEN_END);//一开始就是空，解决：直接按回车会出错的bug
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
    case '=':
        token_ = TOKEN_ASSIGN;
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
        //字母或者下划线打头的才是标识符
        if (isalpha(buf_[curPos_]) || buf_[curPos_] == '_')
        {
            token_ = TOKEN_IDENTIFIER;
            symbol_.erase();
            char ch = buf_[curPos_];
            do
            {
                symbol_ += ch;
                ++curPos_;
                ch = buf_[curPos_];
            } while (isalnum(ch) || ch == '_');
            
        }
        else
        {
            token_ = TOKEN_ERROR;
        }
        
        break;
    }
}