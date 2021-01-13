#include <cctype>
#include <iostream>
#include "Scanner.h"

// Scanner::Scanner(const std::string& buf) : buf_(buf), curPos_(0)
// {
//     Accept();//һ���ַ�һ���ַ���ɨ��
//     isEmpty = (token_ == TOKEN_END);//һ��ʼ���ǿգ������ֱ�Ӱ��س�������bug
// }

//����������ȡ�����������Ǵ�buf��������ȡ
Scanner::Scanner(std::istream& in) : in_(in)
{
    Accept();//һ���ַ�һ���ַ���ɨ��
    isEmpty = (token_ == TOKEN_END);//һ��ʼ���ǿգ������ֱ�Ӱ��س�������bug
}

bool Scanner::IsCommand() const
{
    return token_ == TOKEN_COMMAND;
}


bool Scanner::IsEmpty() const
{
    return isEmpty;//�����ֱ�Ӱ��س�������bug
}

bool Scanner::IsDone() const
{
    //˵���Ѿ�ɨ�������
    return token_ == TOKEN_END;//���1+1=2��bug
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
// void Scanner::SkipWhite()
// {
//     while (isspace(buf_[curPos_]))
//         ++curPos_;
// }

void Scanner::ReadChar()
{
    //һ���ַ�һ���ַ��������л�ȡ����
    look_ = in.get();
    //��ȡһ���ַ������ǿհ��ַ������ｫ�հ��ַ�ȥ��
    //\t���Ʊ��
    while ( look_ == ' ' || look_ == '\t')
        look_ = in_.get();//���»�ȡһ���ַ�
}

void Scanner::Accept()
{
    // SkipWhite();//���Ⱥ��Կհ��ַ�
    ReadChar();
    switch (look_)
    {
    case '!'://���������̾��
        token_ = TOKEN_COMMAND;
        break;
    case '+':
        token_ = TOKEN_ADD;
        // ++curPos_;//��Ϊ���ڴ��ݽ�������һ����׼���룬һ���ַ�һ���ַ����������Բ���Ҫ�Ǽǵ�ǰ��������λ��
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
        //���������ֵ�ʱ���Ȱ����ֹ黹��ȥ��Ȼ����ȡ��number_������
        //���ַ�����Ȼ�ͽ�һ���ַ���ת������double����
        in_.putback(look_);
        in_>>number_;//�������֣���Ҫת��������

        // char* p;//ʵ���������ָ�벢û��ָ��
        // //buf_��һ���ַ�����buf_[curPos_]��һ���ַ����൱�ڵõ����ڲ��ַ������ַ�
        // //�����ָ��p��ָ�����p�����͸ı䣬Ҳ����˵��ָ���������ط����ı���ָ���ָ��
        // number_ = strtod(&buf_[curPos_], &p);//���ص�һ���������ֵ�λ��
        // //����ַpת��Ϊ����curPos_�����Ը���curPos_
        // curPos_ = p - &buf[0];// &buf[0]���ַ������׵�ַ
        break;
    case '\0' : case '\n' : case '\r' : case EOF://��Ϊ���ʽ������
        token_ = TOKEN_END;
        break;
    default:
        //��ĸ�����»��ߴ�ͷ�Ĳ��Ǳ�ʶ��(�������ߺ���)
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
            //ֱ��������������ĸ���»��ߣ�����Ϊֹ����������һ���ո����+��(���Ǳ�ʶ��)
            //���ȡ�����ַ���Ҫ�黹�������У��Ա��´ν���
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
    ReadChar();//Ĩ����!s filename�м�Ŀո�
    symbol_.erase();//����ǰsymbol_erase
    while (!isspace(look_))
    {
        symbol_ + = look_;//filename������symbol_����
        look_ = in.get();
    }

}