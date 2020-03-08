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
		char sendbuf[100] = {};
		scanf("%s", sendbuf);
		DataHeader header = {};
		Restion usertext = {};
		if (0 == strcmp(sendbuf, "exit")) {
			printf("收到exit命令退出\n");
			break;
		}
		else if (0 == strcmp(sendbuf, "login")) {
			UserInfor user = {};
			user.command = LOGIN;
			printf("********    添加用户    ********\n");
			std::cin >> user.username;
			std::cin >> user.password;
			printf("********************************\n");
			send(sock, (char*)&user, sizeof(UserInfor), 0);
			recv(sock, (char*)&usertext, sizeof(Restion), 0);
			printf("server returnDate length : %d || content :# %s",(int)usertext.datalength, usertext.text);
		}
		else if (0 == strcmp(sendbuf, "logout")) {
			UserInfor user = {};
			user.command = LOGOUT;
			printf("*******    删除用户    *********\n");
			std::cin >> user.username;
			printf("********************************\n");
			send(sock, (char*)&user, sizeof(UserInfor), 0);
			recv(sock, (char*)&usertext, sizeof(Restion), 0);
			printf("delete length : %d || contentuser:# %s", usertext.datalength, usertext.text);
		}
		else {
			header.command = LOGERR;
			header.datalength = sizeof(DataHeader);
			send(sock, (char*)&header, sizeof(DataHeader), 0);
			recv(sock, (char*)&usertext, sizeof(Restion), 0);
			printf("err content:# %s", usertext.text);
		}
	}



	closesocket(sock);

	WSACleanup();
	getchar();
	return 0;
}