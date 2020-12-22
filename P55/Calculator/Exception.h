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

    virtual ~SyntaxError() throw()
    {
        
    }

    //���ﲻ�ٸ���what����
};

#endif //_EXCEPTION_H_