#include "Exception.h"

virtual const char* Exception::what() const throw()
{
    return message_.c_str();
}

const char* Exception::StackTrace() const throw()
{
    return stackTrace_.c_str();
}


void Exception::FillStackTrace()
{
    //只适应于Linux进行栈回溯
    // const int len = 200;
    // void* buffer[len];
    // int nptrs = ::backtrace(buffer, len);
    // char** strings = ::backstrace_symbols(buffer, nptrs);
    // if (strings)
    // {
    //     fot (int i = 0; i < nptrs; ++i)
    //     {
    //         stackTrace_.append(strings[i]);
    //         stackTrace_.push_back('\n');
    //     }
    //     free(strings);
    // }
    //windows的比较复杂，需要自己去找代码
}