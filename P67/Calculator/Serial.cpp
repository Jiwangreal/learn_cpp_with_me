#include "Serial.h"
#include "Exception.h"
using std::ios;//不需要将所有命名空间包括进来

//不必关心这俩具体值，仅仅表示True与False
const int TruePattern = 0xfab1fab2;
const int FalsePattern = 0xbad1bad2;

//============================================Serializer=========================================//

Serializer::Serializer(const std::string& filename) : stream_(filename.c_str()), ios::out | ios::binary)
{
    if (!stream_)
        throw FileStreamError("Couldn't open file.");
}

//以二进制方式进行写入
//eg：写入1234567，若是以ASCII码的话，就是写入1234567。这7个字符
//如果以二进制方式写入的话，写入机器是4个字节，这样的整数表示写入文件当中
Serializer& Serializer::Put(int x)
{
    stream_.write(reinterpret_cast<char*>(&x), sizeof(int));
    if (stream_.bad())
        throw FileStreamError("Write file failed");
    return *this;
}

Serializer& Serializer::Put(unsigned int x)
{
    stream_.write(reinterpret_cast<char*>(&x), sizeof(unsigned int));
    if (stream_.bad())
        throw FileStreamError("Write file failed");
    return *this;
}

Serializer& Serializer::Put(long x)
{
    stream_.write(reinterpret_cast<char*>(&x), sizeof(long));
    if (stream_.bad())
        throw FileStreamError("Write file failed");
    return *this;
}

Serializer& Serializer::Put(unsigned long x)
{
    stream_.write(reinterpret_cast<char*>(&x), sizeof(unsigned long ));
    if (stream_.bad())
        throw FileStreamError("Write file failed");
    return *this;
}

Serializer& Serializer::Put(double x)
{
    stream_.write(reinterpret_cast<char*>(&x), sizeof(double));
    if (stream_.bad())
        throw FileStreamError("Write file failed");
    return *this;
}

//如何写入字符串？
/*
不是将字符串本身写入进去，而是将字符串里面的内容写入进去，因为字符串对象总是4个字节
eg：写入"abcdefg" "hello"
7"abcdefg"5"hello"
先写入长度，再写入字符串，这样才能区分2个字符串之间的边界
*/
Serializer& Serializer::Put(const std::string& x)
{
    int len = x.length();
    Put(len);
    stream_.write(x.data(), x.length());
    if (stream_.bad())
        throw FileStreamError("Write file failed");
    return *this;
}


Serializer& Serializer::Put(bool x)
{
    //不同的平台，bool类型的大小不同，所以这样写入,统一bool类型写入都是4个字节
    int n = x? TruePattern: FalsePattern;
    Put(n);
    
    return *this;
}

Serializer& Serializer::operator<<(int x)
{
    return Put(x);
}

Serializer& Serializer::operator<<(unsigned int x)
{
    return Put(x);
}

Serializer& Serializer::operator<<(long x)
{
    return Put(x);
}

Serializer& Serializer::operator<<(unsigned long x)
{
    return Put(x);
}

Serializer& Serializer::operator<<(double x)
{
    return Put(x);
}

Serializer& Serializer::operator<<(const std::string& x)
{
    return Put(x);
}

Serializer& Serializer::operator<<(bool x)
{
    return Put(x);
}


//============================================DeSerializer=========================================//
DeSerializer::DeSerializer(const std::string& filename)
     : stream_(filename.c_str()), ios::in | ios::binary)
{
    if (!stream_)
        throw FileStreamError("Couldn't open file.");
}
}

DeSerializer& DeSerializer::Get(int& x)
{
    if (stream_.eof())
        throw FileStreamError("Unexpected end of file");
    stream_.read(reinterpret_cast<char*>(&x), sizeof(int));
    if (stream_.bad())
        throw FileStreamError("Read file failed");
    return *this;
}

DeSerializer& DeSerializer::Get(unsigned int& x)
{
    if (stream_.eof())
        throw FileStreamError("Unexpected end of file");
    stream_.read(reinterpret_cast<char*>(&x), sizeof(unsigned int));
    if (stream_.bad())
        throw FileStreamError("Read file failed");
    return *this;
}

DeSerializer& DeSerializer::Get(long& x)
{
    if (stream_.eof())
        throw FileStreamError("Unexpected end of file");
    stream_.read(reinterpret_cast<char*>(&x), sizeof(long));
    if (stream_.bad())
        throw FileStreamError("Read file failed");
    return *this;
}

DeSerializer& DeSerializer::Get(unsigned long& x)
{
    if (stream_.eof())
        throw FileStreamError("Unexpected end of file");
    stream_.read(reinterpret_cast<char*>(&x), sizeof(unsigned long));
    if (stream_.bad())
        throw FileStreamError("Read file failed");
    return *this;
}

DeSerializer& DeSerializer::Get(double& x)
{
    if (stream_.eof())
        throw FileStreamError("Unexpected end of file");
    stream_.read(reinterpret_cast<char*>(&x), sizeof(double));
    if (stream_.bad())
        throw FileStreamError("Read file failed");
    return *this;
}

DeSerializer& DeSerializer::Get(std::string& x)
{
    int len;
    Get(len);
    if (stream_.eof())
        throw FileStreamError("Unexpected end of file");  
    //先分配空间再读取
    x.resize(len);
    stream_.read(&x[0], len);//直接使用是不会分配空间的
    if (stream_.bad())
        throw FileStreamError("Read file failed");

    return *this;
}

DeSerializer& DeSerializer::Get(bool& x)
{
    int n;
    Get(n);
    if (n == TruePattern)
        x= true;
    else if (n == FalsePattern)
        x= false;
    else
        throw FileStreamError("Data Error");
    return *this;
}

DeSerializer& DeSerializer::operator>>(int& x)
{
    return Get(x);
}

DeSerializer& DeSerializer::operator>>(unsigned int& x)
{
     return Get(x);
}

DeSerializer& DeSerializer::operator>>(long& x)
{
     return Get(x);
}

DeSerializer& DeSerializer::operator>>(unsigned long& x)
{
     return Get(x);
}

DeSerializer& DeSerializer::operator>>(double& x)
{
     return Get(x);
}

DeSerializer& DeSerializer::operator>>(std::string& x)
{
     return Get(x);
}

DeSerializer& DeSerializer::operator>>(bool& x)
{
     return Get(x);
}

