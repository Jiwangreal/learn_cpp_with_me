#include "Server.h"
#include "../Public/MD5.h"

#include <stdio.h>
using namespace PUBLIC;

int main(void)
{
	//MD5类的使用
	//MD5 md5;

	//unsigned char hash[16];输出的是16bytes的哈希字符串
	//加密的字符串：cppcourse
	//加密字符串的长度：9
	//输出的字符串：hash
	//md5.MD5Make(hash, (unsigned char const *)"cppcourse", 9);
	
	//将16bytes的字符串输出为32bytes的字符串
	//int i;
	//for (i=0; i<16; ++i)
	//{
	//	printf("%0X", hash[i]);
	//}

	//printf("\n");
	return Singleton<Server>::Instance().Start();
}