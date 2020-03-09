#define WIN32_LEAN_AND_MEAN
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include <WinSock2.h>
#include <stdio.h>
#include <iostream>


enum MyEnum
{
	LOGIN,
	LOGOUT,
	NEW_USER_JOIN,
	LOGERR
};

struct DataHeader {
	short datalength;
	short command;
};

struct UserInfor : public DataHeader
{
	UserInfor() {
		datalength = sizeof(UserInfor);
	}
	char username[32];
	char password[32];
};

struct Restion : public DataHeader
{
	Restion() {
		datalength = sizeof(Restion);
	}
	char text[50];
};

struct NewUserJoin : public DataHeader {
	NewUserJoin() {
		command = NEW_USER_JOIN;
		datalength = sizeof(NewUserJoin);
	}
	int restion;
};


int procss_function(SOCKET sock) {
	DataHeader header = {};
	Restion usertext = {};
	NewUserJoin newuser = {};
	int nLen = recv(sock, (char*)&header, sizeof(DataHeader), 0);
	if (nLen <= 0) {
		printf("服务器断开连接 ...\n");
		return -1;
	}
	switch (header.command)
	{
	case LOGIN:
		recv(sock, (char*)&usertext + sizeof(DataHeader), sizeof(Restion) - sizeof(DataHeader), 0);
		printf("%d #: %s", sock, usertext.text);
		break;
	case LOGOUT:
		recv(sock, (char*)&usertext + sizeof(DataHeader), sizeof(Restion) - sizeof(DataHeader), 0);
		printf("%d #: %s", sock, usertext.text);
		break;
	case NEW_USER_JOIN:
		recv(sock, (char*)&newuser + sizeof(DataHeader), sizeof(NewUserJoin) - sizeof(DataHeader), 0);
		printf("%d #: %d", sock, newuser.restion);
	default:
		printf("没有当前命令....\n");
		break;
	}
	return 0;
}


int main() {
	WORD ver = MAKEWORD(2, 2);
	WSADATA dat;
	WSAStartup(ver, &dat);

	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
	if (INVALID_SOCKET == sock) {
		printf("建立socket失败...\n");
	}
	else {
		printf("建立socket成功...\n");
	}
	sockaddr_in _sin = {};
	_sin.sin_family = AF_INET;
	_sin.sin_port = htons(4567);
	_sin.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	int ret = connect(sock, (sockaddr*)&_sin, sizeof(sockaddr_in));
	if (SOCKET_ERROR == ret) {
		printf("连接失败..\n");
	}
	else {
		printf("连接成功...\n");
	}


	while (true) {
		fd_set readfd;
		FD_ZERO(&readfd);
		FD_SET(sock, &readfd);
		timeval t = { 1,0 };
		int ret = select(sock + 1, &readfd, 0, 0, &t);
		if (ret < 0) {
			printf("select 加载失败\n");
			break;
		}
		if (FD_ISSET(sock, &readfd)) {
			FD_CLR(sock, &readfd);
			if (-1 == procss_function(sock)) {
				printf("任务结束\n");
				break;
			}
		}
		printf("处理其他 function ..... \n");
		UserInfor user = {};
		user.command = LOGIN;
		strcpy(user.username, "mmc");
		strcpy(user.password, "mmcps");
		send(sock, (char*)&user, sizeof(UserInfor), 0);
		Sleep(1000);
	}



	closesocket(sock);

	WSACleanup();
	getchar();
	return 0;
}