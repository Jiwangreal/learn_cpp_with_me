#ifndef _SCANNER_H_
#define _SCANNER_H_
#include <string>

//Scanner类：只负责扫描，并且登记当前的状态
class Scanner
{
public:
    Scanner(const std::string& buf);
private:
    const std:string buf_;
};






#endif/*_SCANNER_H_*/