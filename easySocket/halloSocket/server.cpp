//#define WIN32_LEAN_AND_MEAN
//#define _WINSOCK_DEPRECATED_NO_WARNINGS
//#define _CRT_SECURE_NO_WARNINGS
//
//#include <Windows.h>
//#include <WinSock2.h>
//#include <stdio.h>
//
////#pragma comment(lib,"ws2_32.lib")
//
//struct DataPackage {
//	int age;
//	char name[32];
//};
//
//int main() {
//	WORD ver = MAKEWORD(2, 2);
//	WSADATA dat;
//	WSAStartup(ver, &dat);
//	
//	SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
//	sockaddr_in _sin = {};
//	_sin.sin_family = AF_INET;
//	_sin.sin_port = htons(4567);
//	_sin.sin_addr.S_un.S_addr = INADDR_ANY;
//	//INADDR_ANY �������κ�ip��ַ������
//	if (SOCKET_ERROR == bind(sock, (sockaddr *)&_sin, sizeof(_sin))) {
//		printf("ERROR,��ʧ��..\n");
//	}
//	else {
//		printf("�󶨳ɹ�...\n");
//	}
//
//	if (SOCKET_ERROR == listen(sock, 5)) {
//		printf("���󣬼�������˿�ʧ��...\n");
//	}
//	else {
//		printf("��������˿ڳɹ�...\n");
//	}
//
//	sockaddr_in clientAddr = {};
//	int clientLen = sizeof(clientAddr);
//	SOCKET cliSock = INVALID_SOCKET;
//	
//	cliSock = accept(sock, (sockaddr*)&clientAddr, &clientLen);
//	if (INVALID_SOCKET == cliSock) {
//		printf("���󣬽��ܵ���Ч�ͻ���SOCKET...\n");
//	}
//	printf("�¿ͻ��˼���: IP = %s\n", inet_ntoa(clientAddr.sin_addr));
//	
//	
//	while (true) {
//		char recvbuf[1024] = {0};
//		int nLen = recv(cliSock, recvbuf, 1024, 0);
//		if (nLen <= 0) {
//			printf("�ͻ����˳�...\n");
//			break;
//		}
//		printf("�յ�����: %s \n", recvbuf);
//		if (0 == strcmp(recvbuf, "getInfo")) {
//			DataPackage dp = { 80, "����" };
//			send(cliSock, (const char*)&dp, sizeof(DataPackage), 0);
//		}
//		else {
//			char sentbuf[] = "????...";
//			send(cliSock, sentbuf, strlen(sentbuf) + 1, 0);
//		}
//	}
//	closesocket(sock);
//
//	WSACleanup();
//	getchar();
//	return 0;
//}