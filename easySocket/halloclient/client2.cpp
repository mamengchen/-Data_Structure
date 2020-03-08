//#define WIN32_LEAN_AND_MEAN
//#define _WINSOCK_DEPRECATED_NO_WARNINGS
//#define _CRT_SECURE_NO_WARNINGS
//
//#include <Windows.h>
//#include <WinSock2.h>
//#include <stdio.h>
//#include <iostream>
//
//
//enum MyEnum
//{
//	LOGIN,
//	LOGOUT,
//	LOGERR
//};
//
//struct DataHeader {
//	short datalength;
//	short command;
//};
//
//struct UserInfor
//{
//	char username[32];
//	char password[32];
//};
//
//struct Restion {
//	char text[100];
//};
//
//
//int main() {
//	WORD ver = MAKEWORD(2, 2);
//	WSADATA dat;
//	WSAStartup(ver, &dat);
//
//	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
//	if (INVALID_SOCKET == sock) {
//		printf("����socketʧ��...\n");
//	}
//	else {
//		printf("����socket�ɹ�...\n");
//	}
//	sockaddr_in _sin = {};
//	_sin.sin_family = AF_INET;
//	_sin.sin_port = htons(4567);
//	_sin.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
//	int ret = connect(sock, (sockaddr*)&_sin, sizeof(sockaddr_in));
//	if (SOCKET_ERROR == ret) {
//		printf("����ʧ��..\n");
//	}
//	else {
//		printf("���ӳɹ�...\n");
//	}
//
//
//	while (true) {
//		char sendbuf[100] = {};
//		scanf("%s", sendbuf);
//		DataHeader header = {};
//		Restion usertext = {};
//		if (0 == strcmp(sendbuf, "exit")) {
//			printf("�յ�exit�����˳�\n");
//			break;
//		}
//		else if (0 == strcmp(sendbuf, "login")) {
//			header.command = LOGIN;
//			header.datalength = 101;
//			UserInfor user = {};
//			printf("********    ����û�    ********\n");
//			std::cin >> user.username;
//			std::cin >> user.password;
//			printf("********************************\n");
//			send(sock, (char*)&header, sizeof(DataHeader), 0);
//			send(sock, (char*)&user, sizeof(UserInfor), 0);
//			recv(sock, (char*)&usertext, sizeof(Restion), 0);
//			printf("server returnDate:# %s", usertext.text);
//		}
//		else if (0 == strcmp(sendbuf, "logout")) {
//			header.command = LOGOUT;
//			header.datalength = 200;
//			UserInfor user = {};
//			printf("*******    ɾ���û�    *********\n");
//			std::cin >> user.username;
//			printf("********************************\n");
//			send(sock, (char*)&header, sizeof(DataHeader), 0);
//			send(sock, (char*)&user, sizeof(UserInfor), 0);
//			recv(sock, (char*)&usertext, sizeof(Restion), 0);
//			printf("delete user:# %s", usertext.text);
//		}
//		else {
//			header.command = LOGERR;
//			header.datalength = 404;
//			send(sock, (char*)&header, sizeof(DataHeader), 0);
//			recv(sock, (char*)&usertext, sizeof(Restion), 0);
//			printf("delete user:# %s", usertext.text);
//		}
//	}
//
//
//
//	closesocket(sock);
//
//	WSACleanup();
//	getchar();
//	return 0;
//}