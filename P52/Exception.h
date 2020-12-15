#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_

#include <exception>
#include <string>

//继承至标准库的exception类
class Exception : public std:exception 
{
public:
    //为了防止转换构造
    explicit expException(const char* message) : message_(message)
    {
        FillStackTrace();
    }

    //析构函数不抛出异常，throw()表示不抛出异常
    virtual ~Exception() throw() 
    {

    }

    //what是基类的虚函数，这里覆盖waht方法，也不抛出异常
    virtual const char* what() const throw();

    const char* StackTrace() const throw();

private:
    void FillStackTrace();
    std:string message_;
    std::string stackTrace_;//在发生异常的地方，将调用栈信息保存到字符串stackTrace_中
                            //在构造throw SyntaxError("Not a valid expression");对象的时候就把当前的调用栈信息，栈回溯写入到stackTrace_变量中
};

//语法错误
class SyntaxError : public Exception
{
public:
    explicit SyntaxError(const char* message) : Exception(message)
    {

    }

    virtual ~SyntaxError() throw()
    {
        
    }

    //这里不再覆盖what方法
};

#endif //_EXCEPTION_H_