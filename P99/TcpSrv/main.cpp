#pragma comment(lib, "ws2_32.lib")
#include <WinSock2.h>
#include <process.h>
#include "JThread.h"
#include <iostream>
using namespace std;

// class ServiceThread : public JThread
// {
// public:
// 	ServiceThread(SOCKET conn) : conn_(conn)
// 	{
// 		cout<<"ServiceThread ..."<<endl;
// 	}
// 	~ServiceThread()
// 	{
// 		cout<<"~ServiceThread ..."<<endl;
// 	}
// 	void Run()
// 	{
// 		char buf[1024] = {0};
// 		while (1)
// 		{
// 			int ret = recv(conn_, buf, sizeof(buf), 0);
// 			if (ret == SOCKET_ERROR)
// 			{
// 				cout<<"error with code = "<<WSAGetLastError()<<endl;
// 				exit(1);
// 			}
// 			if (ret == 0)
// 			{
// 				cout<<"client close"<<endl;
// 				break;
// 			}
// 			if (ret > 0)
// 			{
// 				cout<<buf<<endl;
// 				send(conn_, buf, strlen(buf), 0);
// 			}
// 			memset(buf, 0, sizeof buf);
// 		}
// 		closesocket(conn_);
// 	}

// private:
// 	SOCKET conn_;
// };
//
void do_service(SOCKET conn)
{
	char buf[1024] = {0};
	while (1)
	{
		int ret = recv(conn, buf, sizeof(buf), 0);
		if (ret == SOCKET_ERROR)
		{
			cout<<"error with code = "<<WSAGetLastError()<<endl;
			exit(1);
		}
		if (ret == 0)//˵���Եȷ��ر���
		{
			cout<<"client close"<<endl;
			break;
		}
		if (ret > 0)
		{
			cout<<buf<<endl;
			send(conn, buf, strlen(buf), 0);
		}
		memset(buf, 0, sizeof buf);
	}
	closesocket(conn);
}

int main(void)
{
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;

	wVersionRequested = MAKEWORD( 2, 2 );//��ʾҪ����İ汾

	//����F1��eg start
	err = WSAStartup( wVersionRequested, &wsaData );//������
	if ( err != 0 ) {
		return 1;
	}

	//�ж�������ǲ���2.2�汾
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
	//����F1��eg end

	//׼��һ����������ַ
	sockaddr_in servaddr;
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	//servaddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);//Windowsд��
	//Linuxд������
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);//S_un.S_addr����s_addr���ú�����
	servaddr.sin_port = htons(8888);

	int ret;
	int opt = 1;
	ret = setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, (char*)&opt, sizeof(opt));
	if (ret == SOCKET_ERROR)
	{
		cout<<"error with code = "<<WSAGetLastError()<<endl;
		exit(1);
	}


	//����
	//C���Բ���ʡ��struct��C++����
	//C����д����ret = bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
	ret = bind(listenfd, (sockaddr*)&servaddr, sizeof(servaddr));
	//SOCKET_ERROR������-1
	if (ret == SOCKET_ERROR)
	{
		cout<<"error with code = "<<WSAGetLastError()<<endl;
		exit(1);
	}

	ret = listen(listenfd, SOMAXCONN);//SOMAXCONN�����������ֵ
	if (ret == SOCKET_ERROR)
	{
		cout<<"error with code = "<<WSAGetLastError()<<endl;
		exit(1);
	}


	//���ܿͻ��˵�����
	SOCKET conn;
	sockaddr_in peeraddr;//�Եȷ��ĵ�ַ
	int peerlen;//linux������socklen_t
	while (1)
	{
		peerlen = sizeof(peeraddr);//peerlen�������������
		conn = accept(listenfd, (sockaddr*)&peeraddr, &peerlen);
		if (conn == INVALID_SOCKET)
		{
			cout<<"error with code = "<<WSAGetLastError()<<endl;
			exit(1);
		}

		//�ɹ���ӡ�Եȷ��ĵ�ַ
		cout<<inet_ntoa(peeraddr.sin_addr)<<" "<<ntohs(peeraddr.sin_port)<<endl;

		do_service(conn);
	
		//unsigned threadId;
		//HANDLE hThread = (HANDLE)_beginthreadex(NULL, 0, do_service, (void*)conn, 0, &threadId);
		//if (hThread == NULL)
		//{
		//	cout<<"error with code = "<<GetLastError()<<endl;
		//	exit(1);
		//}
		//CloseHandle(hThread);

		// ServiceThread* t = new ServiceThread(conn);
		// t->SetAutoDel(true);
		// t->Start();
	}

	WSACleanup();


	return 0;
}