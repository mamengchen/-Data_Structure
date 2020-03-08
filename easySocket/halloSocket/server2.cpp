//#define WIN32_LEAN_AND_MEAN
//#define _WINSOCK_DEPRECATED_NO_WARNINGS
//#define _CRT_SECURE_NO_WARNINGS
//
//#include <Windows.h>
//#include <WinSock2.h>
//#include <stdio.h>
//#include <vector>
//
//
////#pragma comment(lib,"ws2_32.lib")
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
//std::vector<UserInfor> myUserList;
//
//int user_find_userlist(UserInfor * user) {
//	if (myUserList.empty()) { return 0; }
//	for (int i = 0; i < myUserList.size();i++) {
//		if (strcmp(myUserList[i].username ,user->username) == 0) {
//			return i+1;
//		}
//	}
//	return 0;
//}
//
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
//		DataHeader header = {};
//		UserInfor user = {};
//		Restion usertext = {};
//		int uselen = 0;
//		int nLen = recv(cliSock,(char*)&header, sizeof(DataHeader), 0);
//		if (nLen <= 0) {
//			printf("客户端退出...\n");
//			break;
//		}
//		switch (header.command)
//		{
//		case LOGIN:
//			printf("收到命令: LOGIN .. 命令长度: %d \n", header.datalength);
//			
//			recv(cliSock, (char*)&user, sizeof(UserInfor), 0);
//			if (user_find_userlist(&user)) {
//				sprintf(usertext.text,"当前用户 %s 已经在用户列表之中... \n",user.username);
//			}
//			else {
//				sprintf(usertext.text, "登录成功！！！\n");
//				myUserList.push_back(user);
//			}
//			break;
//		case LOGOUT:
//			printf("收到命令: LOGOUT || 命令长度: %d \n", header.datalength);
//			uselen = 0;
//			recv(cliSock, (char*)&user, sizeof(UserInfor), 0);
//			if ((uselen = user_find_userlist(&user))) {
//				sprintf(usertext.text, "当前用户：%s; 已经被移除... \n", user.username);
//				myUserList.erase(myUserList.begin() + uselen - 1);
//			}
//			else {
//				sprintf(usertext.text, "失败，用户早就被移除... \n");
//			}
//			break;
//		default:
//			sprintf(usertext.text, "没有当前命令....\n");
//			break;
//		}
//		send(cliSock, (char*)&usertext, sizeof(Restion), 0);
//	}
//	closesocket(sock);
//
//	WSACleanup();
//	getchar();
//	return 0;
//}