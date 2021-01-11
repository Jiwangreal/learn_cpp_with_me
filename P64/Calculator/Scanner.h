#ifndef _SCANNER_H_
#define _SCANNER_H_
#include <string>


enum EToken
{
    TOKEN_COMMAND,
    TOKEN_END,
    TOKEN_ERROR,
    TOKEN_NUMBER,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_MULTIPLY,
    TOKEN_DIVIDE,
    TOKEN_LPARENTHESIS,
    TOKEN_RPARENTHESIS,
    TOKEN_IDENTIFIER,
    TOKEN_ASSIGN//eg:a=5
};

//Scanner�ֻࣺ����ɨ�裬���ҵǼǵ�ǰ��״̬
class Scanner
{
public:
    // explicit Scanner(const std::string& buf);
    explicit Scanner(std::istream& in);

    bool IsDone() const;
    bool IsCommand() const;
    void Accept();
    bool IsEmpty() const;
    double Number() const;
    string GetSymbol() const;
    EToken Token() const;
private:
    void ReadChar();//��Ϊ�����������л�ȡ������һ���ַ�һ���ַ�ȥ����
    int look_;//��ǰ���������ַ�

    // void SkipWhite();
    // const std:string buf_;
    std::istream& in_;

    // unsigned int curPos_;
    EToken token_;//����״̬
    double number_;//��������
    std::string symbol_;
    bool isEmpty_;
};
#endif/*_SCANNER_H_*/