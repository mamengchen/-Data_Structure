//#define WIN32_LEAN_AND_MEAN
//#define _WINSOCK_DEPRECATED_NO_WARNINGS
//#define _CRT_SECURE_NO_WARNINGS
//
//#include <Windows.h>
//#include <WinSock2.h>
//#include <stdio.h>
//#include <vector>
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
//struct UserInfor : public DataHeader
//{
//	UserInfor() {
//		datalength = sizeof(UserInfor);
//	}
//	char username[32];
//	char password[32];
//};
//
//struct Restion : public DataHeader
//{
//	Restion() {
//		datalength = sizeof(Restion);
//	}
//	char text[50];
//};
//
//std::vector<UserInfor> myUserList;
//std::vector<SOCKET> mysocker;
//
//int user_find_userlist(UserInfor * user) {
//	if (myUserList.empty()) { return 0; }
//	for (int i = 0; i < myUserList.size(); i++) {
//		if (strcmp(myUserList[i].username, user->username) == 0) {
//			return i + 1;
//		}
//	}
//	return 0;
//}
//
//
//int procss_function(SOCKET cliSock) {
//	DataHeader header = {};
//	UserInfor user = {};
//	Restion usertext = {};
//	int uselen = 0;
//	int nLen = recv(cliSock, (char*)&header, sizeof(DataHeader), 0);
//	if (nLen <= 0) {
//		printf("�ͻ����˳�...\n");
//		return -1;
//	}
//	switch (header.command)
//	{
//	case LOGIN:
//		printf("�յ�����: LOGIN || �����: %d \n", header.datalength);
//
//		recv(cliSock, (char*)&user + sizeof(DataHeader), sizeof(UserInfor) - sizeof(DataHeader), 0);
//		if (user_find_userlist(&user)) {
//			sprintf(usertext.text, "��ǰ�û� %s �Ѿ����û��б�֮��... \n", user.username);
//		}
//		else {
//			sprintf(usertext.text, "��¼�ɹ�������\n");
//			myUserList.push_back(user);
//		}
//		break;
//	case LOGOUT:
//		printf("�յ�����: LOGOUT || �����: %d \n", header.datalength);
//		uselen = 0;
//		recv(cliSock, (char*)&user + sizeof(DataHeader), sizeof(UserInfor) - sizeof(DataHeader), 0);
//		if ((uselen = user_find_userlist(&user))) {
//			sprintf(usertext.text, "��ǰ�û���%s; �Ѿ����Ƴ�... \n", user.username);
//			myUserList.erase(myUserList.begin() + uselen - 1);
//		}
//		else {
//			sprintf(usertext.text, "ʧ�ܣ��û���ͱ��Ƴ�... \n");
//		}
//		break;
//	default:
//		sprintf(usertext.text, "û�е�ǰ����....\n");
//		break;
//	}
//	send(cliSock, (char*)&usertext, sizeof(Restion), 0);
//	return 0;
//}
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
//
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
//
//	while (true) {
//		fd_set readfd;
//		fd_set writefd;
//		fd_set errfd;
//		
//		FD_ZERO(&readfd);
//		FD_ZERO(&writefd);
//		FD_ZERO(&errfd);
//
//		FD_SET(sock, &readfd);
//		FD_SET(sock, &writefd);
//		FD_SET(sock, &errfd);
//
//		for (int i = 0; i < mysocker.size(); i++) {
//			FD_SET(mysocker[i], &readfd);
//		}
//		timeval t = { 0,0 };
//		int ret = select(sock + 1, &readfd, &writefd, &errfd, &t);
//		if (ret <= 0) {
//			printf("select sock ע���¼�ʧ��\n");
//			break;
//		}
//		if (FD_ISSET(sock, &readfd)) {
//			FD_CLR(sock, &readfd);
//			sockaddr_in clientAddr = {};
//			int clientLen = sizeof(clientAddr);
//			SOCKET cliSock = INVALID_SOCKET;
//
//			cliSock = accept(sock, (sockaddr*)&clientAddr, &clientLen);
//			if (INVALID_SOCKET == cliSock) {
//				printf("���󣬽��ܵ���Ч�ͻ���SOCKET...\n");
//			}
//			mysocker.insert(mysocker.begin(), cliSock);
//			printf("�¿ͻ��˼���: IP = %s || �ṩ�����: socket = %d\n", inet_ntoa(clientAddr.sin_addr), (int)cliSock);
//		}
//
//		for (size_t i = 0; i < readfd.fd_count; i++) {
//			if (-1 == procss_function(readfd.fd_array[i])) {
//				auto iter = find(mysocker.begin(), mysocker.end(), readfd.fd_array[i]);
//				if (iter != mysocker.end()) {
//					printf("�Ѿ��Ƴ����˳���sock : %d...\n", *iter);
//					closesocket(*iter);
//					mysocker.erase(iter);
//				}
//			}
//		}
//		
//	}
//
//	for (int i = 0; i < mysocker.size(); i++) {
//		closesocket(mysocker[i]);
//	}
//	closesocket(sock);
//
//	WSACleanup();
//	getchar();
//	return 0;
//}