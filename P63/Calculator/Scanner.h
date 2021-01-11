#ifndef _SCANNER_H_
#define _SCANNER_H_
#include <string>


enum EToken
{
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

//Scanner类：只负责扫描，并且登记当前的状态
class Scanner
{
public:
    // explicit Scanner(const std::string& buf);
    explicit Scanner(std::istream& in);

    bool IsDone() const;
    void Accept();
    bool IsEmpty() const;
    double Number() const;
    string GetSymbol() const;
    EToken Token() const;
private:
    void ReadChar();//因为从输入流进行获取，所以一个字符一个字符去解析
    int look_;//当前解析到的字符

    // void SkipWhite();
    // const std:string buf_;
    std::istream& in_;

    // unsigned int curPos_;
    EToken token_;//返回状态
    double number_;//返回数字
    std::string symbol_;
    bool isEmpty_;
};
#endif/*_SCANNER_H_*/