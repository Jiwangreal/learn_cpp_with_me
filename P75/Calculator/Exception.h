#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_

#include <exception>
#include <string>

//�̳�����׼���exception��
class Exception : public std:exception 
{
public:
    //Ϊ�˷�ֹת������
    explicit expException(const char* message) : message_(message)
    {
        FillStackTrace();
    }

    
    explicit expException(const std::string& message) : message_(message)
    {
        FillStackTrace();
    }

    //�����������׳��쳣��throw()��ʾ���׳��쳣
    virtual ~Exception() throw() 
    {

    }

    //what�ǻ�����麯�������︲��waht������Ҳ���׳��쳣
    virtual const char* what() const throw();

    const char* StackTrace() const throw();

private:
    void FillStackTrace();
    std:string message_;
    std::string stackTrace_;//�ڷ����쳣�ĵط���������ջ��Ϣ���浽�ַ���stackTrace_��
                            //�ڹ���throw SyntaxError("Not a valid expression");�����ʱ��Ͱѵ�ǰ�ĵ���ջ��Ϣ��ջ����д�뵽stackTrace_������
};

//�﷨����
class SyntaxError : public Exception
{
public:
    explicit SyntaxError(const char* message) : Exception(message)
    {

    }

    //���������ӹ��캯��������Ҳ��Ҫ����
    explicit SyntaxError(const std::string& message) : Exception(message)
    {

    }

    virtual ~SyntaxError() throw()
    {
        
    }

    //���ﲻ�ٸ���what����
};

//�����Ǳ�־���ã�û���������õĴ���
class FileStreamError : public Exception
{
public:
    explicit FileStreamError(const char* message) : Exception(message)
    {

    }

    //���������ӹ��캯��������Ҳ��Ҫ����
    explicit FileStreamError(const std::string& message) : Exception(message)
    {

    }

    virtual ~FileStreamError() throw()
    {
        
    }

    //���ﲻ�ٸ���what����
};

// class CheckNumberError : public Exception
// {
// public:
//     explicit CheckNumberError(const char* message) : Exception(message)
//     {

//     }

//     //���������ӹ��캯��������Ҳ��Ҫ����
//     explicit CheckNumberError(const std::string& message) : Exception(message)
//     {

//     }

//     virtual ~CheckNumberError() throw()
//     {
        
//     }

//     //���ﲻ�ٸ���what����
// };


#endif //_EXCEPTION_H_