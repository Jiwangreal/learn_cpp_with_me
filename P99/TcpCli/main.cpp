#pragma comment(lib, "ws2_32.lib")
#include <WinSock2.h>
#include <iostream>
using namespace std;

int main(void)
{
	//来自F1的eg start
	WORD wVersionRequested;//表示要请求的版本
	WSADATA wsaData;
	int err;

	wVersionRequested = MAKEWORD( 2, 2 );

	err = WSAStartup( wVersionRequested, &wsaData );//启动它
	if ( err != 0 ) {
		return 1;
	}

	//判断请求的是不是2.2版本
	if ( LOBYTE( wsaData.wVersion ) != 2 ||
		HIBYTE( wsaData.wVersion ) != 2 ) {
			WSACleanup( );
			return 1; 
	}
	//来自F1的eg end

	//创建socket
	SOCKET sock;
	//协议族：TCP/IP
	//socket类型：流失套接字
	//指定TCP协议，或者写0，让内核自动选择
	sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	//~0表示，0取反就是全1，INVALID_SOCKET就是~0
	if (sock == INVALID_SOCKET)
	{
		//WSAGetLastError()类似于Linux的errno
		cout<<"1error with code = "<<WSAGetLastError()<<endl;
		exit(1);
	}

	//准备一个服务器地址
	sockaddr_in servaddr;
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	//servaddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");//Windows写法
	//Linux写法如下
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");//S_un.S_addr等于s_addr，用宏做的
	servaddr.sin_port = htons(8888);

	int ret;
	ret = connect(sock, (sockaddr*)&servaddr, sizeof(servaddr));
	if (ret == -1)
	{
		cout<<"2error with code = "<<WSAGetLastError()<<endl;
		exit(1);
	}

	char buf[1024] = {0};
	char recvbuf[1024] = {0};
	while (1)
	{
		cin>>buf;
		if (strcmp(buf, "quit") == 0)
			break;
		ret = send(sock, buf, strlen(buf), 0);
		if (ret == -1)
		{
			cout<<"3error with code = "<<WSAGetLastError()<<endl;
			exit(1);
		}

		ret = recv(sock, recvbuf, sizeof(buf), 0);
		if (ret == -1)
		{
			cout<<"4error with code = "<<WSAGetLastError()<<endl;
			exit(1);
		}
		if (ret == 0)//说明服务器关闭
		{
			cout<<"server close"<<endl;
			break;
		}
		if (ret > 0)
		{
			cout<<recvbuf<<endl;
		}
		memset(buf, 0, sizeof buf);//C++的sizeof没有括号也行
		memset(recvbuf, 0, sizeof recvbuf);
	}

	closesocket(sock);

	return 0;
}