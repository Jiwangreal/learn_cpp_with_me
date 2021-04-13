#include "JInStream.h"
#include <assert.h>
#include <string.h>

using namespace PUBLIC;

JInStream::JInStream()
	: currIndex_(0)
{
}

JInStream::JInStream(const char* data, size_t len)
	: currIndex_(0)
{
	SetData(data, len);//为buffer_开辟空间
}

void JInStream::SetData(const char* data, size_t len)
{
	currIndex_ = 0;
	buffer_.resize(len);
	std::copy(data, data+len, buffer_.begin());
}

void JInStream::ReadBytes(void* data, size_t len)
{
	assert(ReadableBytes() >= len);
	std::copy(buffer_.begin()+currIndex_,
		buffer_.begin()+currIndex_+len,
		stdext::checked_array_iterator<char*>(static_cast<char*>(data),len));
	//std::copy(buffer_.begin()+currIndex_, buffer_.begin()+currIndex_+len, static_cast<char*>(data));
	currIndex_ += len;
}


JInStream& JInStream::operator>>(uint8& x)
{
	assert(ReadableBytes() >= sizeof(uint8));
	x = *Peek();
	currIndex_ += sizeof x;

	return *this;
}

JInStream& JInStream::operator>>(uint16& x)
{
	assert(ReadableBytes() >= sizeof(uint16));
	uint16 be16 = 0;
	::memcpy(&be16, Peek(), sizeof be16);//Peek()返回currIndex_所在位置
	currIndex_ += sizeof be16;//读走currIndex_

	x = Endian::NetworkToHost16(be16);//转换成主机字节序
	//返回x回来
	return *this;
}

JInStream& JInStream::operator>>(uint32& x)
{
	assert(ReadableBytes() >= sizeof(uint32));
	uint32 be32 = 0;
	::memcpy(&be32, Peek(), sizeof be32);
	currIndex_ += sizeof be32;

	x = Endian::NetworkToHost32(be32);

	return *this;
}

JInStream& JInStream::operator>>(int8& x)
{
	assert(ReadableBytes() >= sizeof(int8));
	x = *Peek();
	currIndex_ += sizeof x;

	return *this;
}

JInStream& JInStream::operator>>(int16& x)
{
	assert(ReadableBytes() >= sizeof(int16));
	int16 be16 = 0;
	::memcpy(&be16, Peek(), sizeof be16);
	currIndex_ += sizeof be16;

	x = Endian::NetworkToHost16(be16);

	return *this;
}

JInStream& JInStream::operator>>(int32& x)
{
	assert(ReadableBytes() >= sizeof(int32));
	int32 be32 = 0;
	::memcpy(&be32, Peek(), sizeof be32);
	currIndex_ += sizeof be32;

	x = Endian::NetworkToHost32(be32);

	return *this;
}

JInStream& JInStream::operator>>(std::string& str)
{
	uint16 len;
	*this>>len;//先读取2个字节，调用JInStream& JInStream::operator>>(uint16& x)
	assert(ReadableBytes() >= len);
	str.clear();//字符串先清除掉
	str.append(Peek(), len);
	currIndex_ += len;

	return *this;
}
