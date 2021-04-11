#pragma comment(lib, "ws2_32.lib")
#include <WinSock2.h>
#include <iostream>
using namespace std;

int main(void)
{
	//����F1��eg start
	WORD wVersionRequested;//��ʾҪ����İ汾
	WSADATA wsaData;
	int err;

	wVersionRequested = MAKEWORD( 2, 2 );

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
	//����F1��eg end

	//����socket
	SOCKET sock;
	//Э���壺TCP/IP
	//socket���ͣ���ʧ�׽���
	//ָ��TCPЭ�飬����д0�����ں��Զ�ѡ��
	sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	//~0��ʾ��0ȡ������ȫ1��INVALID_SOCKET����~0
	if (sock == INVALID_SOCKET)
	{
		//WSAGetLastError()������Linux��errno
		cout<<"1error with code = "<<WSAGetLastError()<<endl;
		exit(1);
	}

	//׼��һ����������ַ
	sockaddr_in servaddr;
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	//servaddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");//Windowsд��
	//Linuxд������
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");//S_un.S_addr����s_addr���ú�����
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
		if (ret == 0)//˵���������ر�
		{
			cout<<"server close"<<endl;
			break;
		}
		if (ret > 0)
		{
			cout<<recvbuf<<endl;
		}
		memset(buf, 0, sizeof buf);//C++��sizeofû������Ҳ��
		memset(recvbuf, 0, sizeof recvbuf);
	}

	closesocket(sock);

	return 0;
}