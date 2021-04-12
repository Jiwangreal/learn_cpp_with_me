#pragma comment(lib, "ws2_32.lib")
#include <WinSock2.h>
#include <process.h>
#include "JThread.h"
#include <iostream>
using namespace std;

class ServiceThread : public JThread
{
public:
	ServiceThread(SOCKET conn) : conn_(conn)
	{
		cout<<"ServiceThread ..."<<endl;
	}
	~ServiceThread()
	{
		cout<<"~ServiceThread ..."<<endl;
	}
	void Run()
	{
		char buf[1024] = {0};
		while (1)
		{
			int ret = recv(conn_, buf, sizeof(buf), 0);
			if (ret == SOCKET_ERROR)
			{
				cout<<"error with code = "<<WSAGetLastError()<<endl;
				exit(1);
			}
			if (ret == 0)
			{
				cout<<"client close"<<endl;
				break;
			}
			if (ret > 0)
			{
				cout<<buf<<endl;
				send(conn_, buf, strlen(buf), 0);
			}
			memset(buf, 0, sizeof buf);
		}
		closesocket(conn_);
	}

private:
	SOCKET conn_;
};
//
//unsigned __stdcall do_service(void* p)
//{
//	int conn = (SOCKET)p;
//	char buf[1024] = {0};
//	while (1)
//	{
//		int ret = recv(conn, buf, sizeof(buf), 0);
//		if (ret == SOCKET_ERROR)
//		{
//			cout<<"error with code = "<<WSAGetLastError()<<endl;
//			exit(1);
//		}
//		if (ret == 0)//说明对等方关闭了
//		{
//			cout<<"client close"<<endl;
//			break;
//		}
//		if (ret > 0)
//		{
//			cout<<buf<<endl;
//			send(conn, buf, strlen(buf), 0);
//		}
//		memset(buf, 0, sizeof buf);
//	}
//	closesocket(conn);
//
//	return 0;
//}

int main(void)
{
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;

	wVersionRequested = MAKEWORD( 2, 2 );//表示要请求的版本

	//来自F1的eg start
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

	SOCKET listenfd;
	listenfd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (listenfd == INVALID_SOCKET)
	{
		cout<<"error with code = "<<WSAGetLastError()<<endl;
		exit(1);
	}
	//来自F1的eg end

	//准备一个服务器地址
	sockaddr_in servaddr;
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	//servaddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);//Windows写法
	//Linux写法如下
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);//S_un.S_addr等于s_addr，用宏做的
	servaddr.sin_port = htons(8888);

	int ret;
	int opt = 1;
	ret = setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, (char*)&opt, sizeof(opt));
	if (ret == SOCKET_ERROR)
	{
		cout<<"error with code = "<<WSAGetLastError()<<endl;
		exit(1);
	}


	//绑定他
	//C语言不能省略struct，C++可以
	//C语言写法：ret = bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
	ret = bind(listenfd, (sockaddr*)&servaddr, sizeof(servaddr));
	//SOCKET_ERROR定义是-1
	if (ret == SOCKET_ERROR)
	{
		cout<<"error with code = "<<WSAGetLastError()<<endl;
		exit(1);
	}

	ret = listen(listenfd, SOMAXCONN);//SOMAXCONN监听队列最大值
	if (ret == SOCKET_ERROR)
	{
		cout<<"error with code = "<<WSAGetLastError()<<endl;
		exit(1);
	}


	//接受客户端的连接
	SOCKET conn;
	sockaddr_in peeraddr;//对等方的地址
	int peerlen;//linux底下是socklen_t
	while (1)
	{
		peerlen = sizeof(peeraddr);//peerlen是输入输出参数
		conn = accept(listenfd, (sockaddr*)&peeraddr, &peerlen);
		if (conn == INVALID_SOCKET)
		{
			cout<<"error with code = "<<WSAGetLastError()<<endl;
			exit(1);
		}

		//成功打印对等方的地址
		cout<<inet_ntoa(peeraddr.sin_addr)<<" "<<ntohs(peeraddr.sin_port)<<endl;

		//使用没有封装的方式实现多线程
		//unsigned threadId;
		//HANDLE hThread = (HANDLE)_beginthreadex(NULL, 0, do_service, (void*)conn, 0, &threadId);
		//if (hThread == NULL)
		//{
		//	cout<<"error with code = "<<GetLastError()<<endl;
		//	exit(1);
		//}
		//CloseHandle(hThread);

		//使用类的方式实现多线程
		/*
		不要使用局部的栈上变量，创建完线程后，这边的线程对象t马上就结束了
		ServiceThread t(conn);
		t.Start();
		//应该用堆上变量
		*/
		ServiceThread* t = new ServiceThread(conn);//new的对象如何销毁？线程执行完毕后，就自动销毁该对象。增加bool autoDel_;
		t->SetAutoDel(true);//new出来的对象，当其执行完毕，让其自动销毁
		t->Start();
	}

	WSACleanup();


	return 0;
}