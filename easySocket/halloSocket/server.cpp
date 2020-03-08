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
//	//INADDR_ANY 可以用任何ip地址区访问
//	if (SOCKET_ERROR == bind(sock, (sockaddr *)&_sin, sizeof(_sin))) {
//		printf("ERROR,绑定失败..\n");
//	}
//	else {
//		printf("绑定成功...\n");
//	}
//
//	if (SOCKET_ERROR == listen(sock, 5)) {
//		printf("错误，监听网络端口失败...\n");
//	}
//	else {
//		printf("监听网络端口成功...\n");
//	}
//
//	sockaddr_in clientAddr = {};
//	int clientLen = sizeof(clientAddr);
//	SOCKET cliSock = INVALID_SOCKET;
//	
//	cliSock = accept(sock, (sockaddr*)&clientAddr, &clientLen);
//	if (INVALID_SOCKET == cliSock) {
//		printf("错误，接受到无效客户端SOCKET...\n");
//	}
//	printf("新客户端加入: IP = %s\n", inet_ntoa(clientAddr.sin_addr));
//	
//	
//	while (true) {
//		char recvbuf[1024] = {0};
//		int nLen = recv(cliSock, recvbuf, 1024, 0);
//		if (nLen <= 0) {
//			printf("客户端退出...\n");
//			break;
//		}
//		printf("收到命令: %s \n", recvbuf);
//		if (0 == strcmp(recvbuf, "getInfo")) {
//			DataPackage dp = { 80, "张若" };
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