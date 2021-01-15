#ifndef _SERIAL_H
#define _SERIAL_H

#include <fstream>
#include <string>

//向文件写入基本的数据类型
class Serializer
{
public:
    Serializer(const std::string& filename);
    //输出流对象既有put方法，也应该有<<插入运算符
    //输入流对象，既有get方法，也应该有>>提取运算符
    Serializer& Put(int x);
    Serializer& Put(unsigned int x);
    Serializer& Put(long x);
    Serializer& Put(unsigned long x);
    Serializer& Put(const std::string& x);
    Serializer& Put(bool x);
    //提供插入运算符的重载，目的是让对文件的操作看起来和对流的操作是一样的
    Serializer& operator<<(int x);
    Serializer& operator<<(unsigned int x);
    Serializer& operator<<(long x);
    Serializer& operator<<(unsigned long x);
    Serializer& operator<<(const std::string& x);
    Serializer& operator<<(bool x);
private:
    std::ofstream stream_:
};

//从文件读取到基本的数据类型
class DeSerializer
{
public:
    DeSerializer(const std::string& filename);
    //输出流对象既有put方法，也应该有<<插入运算符
    //输入流对象，既有get方法，也应该有>>提取运算符
    DeSerializer& Get(int& x);
    DeSerializer& Get(unsigned int& x);
    DeSerializer& Get(long& x);
    DeSerializer& Get(unsigned long& x);
    DeSerializer& Get(std::string& x);
    DeSerializer& Get(bool& x);
    //提供插入运算符的重载，目的是让对文件的操作看起来和对流的操作是一样的
    DeSerializer& operator>>(int& x);
    DeSerializer& operator>>(unsigned int& x);
    DeSerializer& operator>>(long& x);
    DeSerializer& operator>>(unsigned long& x);
    DeSerializer& operator>>(std::string& x);
    DeSerializer& operator>>(bool& x);
private:
    std::ifstream stream_:
};



#endif // _SERIAL_H