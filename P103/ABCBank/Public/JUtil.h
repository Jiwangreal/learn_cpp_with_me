#ifndef _JUTIL_H_
#define _JUTIL_H_

#include <string>
using namespace std;

namespace PUBLIC
{
typedef char int8;
typedef short int16;
typedef int int32;
typedef __int64 int64;

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef unsigned __int64 uint64;

//网络字节序和主机字节序的转换，大小端的判断
class Endian
{
public:
	//主机字节序转网络字节序
	static uint16 HostToNetwork16(uint16 host16)
	{
		//若是大端的，网络字节序就是主机字节序
		if (IsBigEndian())//大小端的判断
			return host16;

		return Swap16(host16);
	}

	static uint32 HostToNetwork32(uint32 host32)
	{
		if (IsBigEndian())
			return host32;

		return Swap32(host32);
	}

	static uint64 HostToNetwork64(uint64 host64)
	{
		if (IsBigEndian())
			return host64;

		return Swap64(host64);
	}

	static uint16 NetworkToHost16(uint16 net16)
	{
		if (IsBigEndian())
			return net16;

		return Swap16(net16);
	}

	static uint32 NetworkToHost32(uint32 net32)
	{
		if (IsBigEndian())
			return net32;

		return Swap32(net32);
	}

	static uint64 NetworkToHost64(uint64 net64)
	{
		if (IsBigEndian())
			return net64;

		return Swap64(net64);
	}


private:
	static bool IsBigEndian()
	{
		//2个字节，高位数据：1个字节00，低位数据：一个字节01
		const uint16 n = 0x0001;
		//*(char*)&n表示强转为char*，然后取出第一个字节的内容
		if (*(char*)&n)//模拟内存地址，地址都是先取低地址
			return false;//如果是00，则是大端字节序，如果是01则是小端字节序

		return true;
	}

	static uint16 Swap16(uint16 s)
	{
		return (s & 0xff) << 8 | (s >> 8) & 0xff;
	}
/*
32bit整数是4个字节
0x12345678——>0x78563412
0x12 34 56 78——>0x78 56 34 12

分别对应以下4行
0x00 00 00 12
0x00 00 34 00
0x00 56 00 00
0x78 00 00 00
最后逻辑或
*/
	static uint32 Swap32(uint32 l)
	{
		return l >> 24 |
			   (l & 0x00ff0000) >> 8 |
			   (l & 0x0000ff00) << 8 |
			   l << 24;
	}

	static uint64 Swap64(uint64 ll)
	{
		return ll >> 56|
			(ll & 0x00ff000000000000) >> 40 |
			(ll & 0x0000ff0000000000) >> 24 |
			(ll & 0x000000ff00000000) >> 8  | 
			(ll & 0x00000000ff000000) << 8  | 
			(ll & 0x0000000000ff0000) << 24 |
			(ll & 0x000000000000ff00) << 40 |
			ll << 56;
	}
};

//用来进行类型转换
class Convert
{
public:
	static int StringToInt(const string& str);//字符串转整型
	static string IntToString(int x);//整型转字符串
	static double StringToDouble(const string& str);//字符串转double
	static string DoubleToString(double x);//double转字符串
};

}

#endif /* _JUTIL_H_ */
