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
//		DataHeader header = {};
//		UserInfor user = {};
//		Restion usertext = {};
//		int uselen = 0;
//		int nLen = recv(cliSock,(char*)&header, sizeof(DataHeader), 0);
//		if (nLen <= 0) {
//			printf("�ͻ����˳�...\n");
//			break;
//		}
//		switch (header.command)
//		{
//		case LOGIN:
//			printf("�յ�����: LOGIN .. �����: %d \n", header.datalength);
//			
//			recv(cliSock, (char*)&user, sizeof(UserInfor), 0);
//			if (user_find_userlist(&user)) {
//				sprintf(usertext.text,"��ǰ�û� %s �Ѿ����û��б�֮��... \n",user.username);
//			}
//			else {
//				sprintf(usertext.text, "��¼�ɹ�������\n");
//				myUserList.push_back(user);
//			}
//			break;
//		case LOGOUT:
//			printf("�յ�����: LOGOUT || �����: %d \n", header.datalength);
//			uselen = 0;
//			recv(cliSock, (char*)&user, sizeof(UserInfor), 0);
//			if ((uselen = user_find_userlist(&user))) {
//				sprintf(usertext.text, "��ǰ�û���%s; �Ѿ����Ƴ�... \n", user.username);
//				myUserList.erase(myUserList.begin() + uselen - 1);
//			}
//			else {
//				sprintf(usertext.text, "ʧ�ܣ��û���ͱ��Ƴ�... \n");
//			}
//			break;
//		default:
//			sprintf(usertext.text, "û�е�ǰ����....\n");
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