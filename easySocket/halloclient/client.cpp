//#define WIN32_LEAN_AND_MEAN
//#define _WINSOCK_DEPRECATED_NO_WARNINGS
//#define _CRT_SECURE_NO_WARNINGS
//
//#include <Windows.h>
//#include <WinSock2.h>
//#include <stdio.h>
//
//
//struct DataPackage {
//	int age;
//	char name[32];
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
//		char sendbuf[1024] = {};
//		char recvbuf[1024] = {};
//		scanf("%s", sendbuf);
//		if (0 == strcmp(sendbuf, "exit")) {
//			printf("�յ�exit�����˳�\n");
//			break;
//		}
//		else {
//			send(sock, sendbuf, strlen(sendbuf) + 1, 0);
//		}
//		int nlen = recv(sock, recvbuf, 1024, 0);
//		if (nlen > 0) {
//			DataPackage * dp = (DataPackage *)recvbuf;
//			printf("���ܵ�����: ���� = %d|| ���� = %s \n", dp->age,dp->name);
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