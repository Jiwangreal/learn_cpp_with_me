#include "Scanner.h"
#include <cctype>

Scanner::Scanner(const std::string& buf) : buf_(buf), curPos_(0)
{
    Accept();//һ���ַ�һ���ַ���ɨ��
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

//���Կհ��ַ�
void Scanner::SkipWhite()
{
    while (isspace(buf_[curPos_]))
        ++curPos_;
}

void Scanner::Accept()
{
    SkipWhite();//���Ⱥ��Կհ��ַ�
    switch (buf[curPos_])
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
        char* p;//ʵ���������ָ�벢û��ָ��
        //buf_��һ���ַ�����buf_[curPos_]��һ���ַ����൱�ڵõ����ڲ��ַ������ַ�
        //�����ָ��p��ָ�����p�����͸ı䣬Ҳ����˵��ָ���������ط����ı���ָ���ָ��
        number_ = strtod(&buf_[curPos_], &p);//���ص�һ���������ֵ�λ��
        //����ַpת��Ϊ����curPos_�����Ը���curPos_
        curPos_ = p - &buf[0];// &buf[0]���ַ������׵�ַ
        break;
    case '\0' : case '\n' : case '\r' : case EOF://��Ϊ���ʽ������
        token_ = TOKEN_END;
        break;
    default:
        //��ĸ�����»��ߴ�ͷ�Ĳ��Ǳ�ʶ��
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