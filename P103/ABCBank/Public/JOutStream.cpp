#include "JOutStream.h"
#include <string.h>

using namespace PUBLIC;

//buffer_�ȷ���1024���ֽ�
const size_t JOutStream::kInitialSize = 1024;

JOutStream::JOutStream() : buffer_(kInitialSize), currIndex_(0)
{
}

JOutStream& JOutStream::operator<<(uint8 x)
{
	Append(&x, sizeof x);
	return *this;
}

JOutStream& JOutStream::operator<<(uint16 x)
{
	uint16 be16 = Endian::HostToNetwork16(x);
	Append(&be16, sizeof be16);
	return *this;
}

JOutStream& JOutStream::operator<<(uint32 x)
{
	uint32 be32 = Endian::HostToNetwork32(x);
	Append(&be32, sizeof be32);
	return *this;
}

JOutStream& JOutStream::operator<<(int8 x)
{
	Append(&x, sizeof x);
	return *this;
}

JOutStream& JOutStream::operator<<(int16 x)
{
	int16 be16 = Endian::HostToNetwork16(x);//�������磬��ת���������ֽ���
	Append(&be16, sizeof be16);
	return *this;
}

JOutStream& JOutStream::operator<<(int32 x)
{
	int32 be32 = Endian::HostToNetwork32(x);
	Append(&be32, sizeof be32);//����void JOutStream::Append(const void*  data, size_t len)
	return *this;
}

JOutStream& JOutStream::operator<<(const std::string& str)
{
	uint16 len = static_cast<uint16>(str.length());//str.length()���ַ����ĳ���
	*this<<len;//�ȴ��2���ֽ���
	Append(str.c_str(), len);//�ٴ���ַ���������void JOutStream::Append(const char* data, size_t len)
	return *this;
}


//void JOutStream::WriteStr(const std::string& str)
//{
//	uint16 len = static_cast<uint16>(str.length());
//	*this<<len;
//	Append(str.c_str(), len);
//}

void JOutStream::WriteBytes(const void* data, size_t len)
{
	Append(data, len);
}

void JOutStream::Append(const char* data, size_t len)
{
	//���ж���û���㹻�Ŀռ䣬�������Զ�����
	EnsureWritableBytes(len);
	//��data���ݿ�����buffer_
	std::copy(data, data+len, buffer_.begin()+currIndex_);//�����Ĵ��
	currIndex_ += len;
}

void JOutStream::Append(const void*  data, size_t len)
{
	Append(static_cast<const char*>(data), len);
}