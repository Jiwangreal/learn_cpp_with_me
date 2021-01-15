#ifndef _SERIAL_H
#define _SERIAL_H

#include <fstream>
#include <string>

//���ļ�д���������������
class Serializer
{
public:
    Serializer(const std::string& filename);
    //������������put������ҲӦ����<<���������
    //���������󣬼���get������ҲӦ����>>��ȡ�����
    Serializer& Put(int x);
    Serializer& Put(unsigned int x);
    Serializer& Put(long x);
    Serializer& Put(unsigned long x);
    Serializer& Put(const std::string& x);
    Serializer& Put(bool x);
    //�ṩ��������������أ�Ŀ�����ö��ļ��Ĳ����������Ͷ����Ĳ�����һ����
    Serializer& operator<<(int x);
    Serializer& operator<<(unsigned int x);
    Serializer& operator<<(long x);
    Serializer& operator<<(unsigned long x);
    Serializer& operator<<(const std::string& x);
    Serializer& operator<<(bool x);
private:
    std::ofstream stream_:
};

//���ļ���ȡ����������������
class DeSerializer
{
public:
    DeSerializer(const std::string& filename);
    //������������put������ҲӦ����<<���������
    //���������󣬼���get������ҲӦ����>>��ȡ�����
    DeSerializer& Get(int& x);
    DeSerializer& Get(unsigned int& x);
    DeSerializer& Get(long& x);
    DeSerializer& Get(unsigned long& x);
    DeSerializer& Get(std::string& x);
    DeSerializer& Get(bool& x);
    //�ṩ��������������أ�Ŀ�����ö��ļ��Ĳ����������Ͷ����Ĳ�����һ����
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