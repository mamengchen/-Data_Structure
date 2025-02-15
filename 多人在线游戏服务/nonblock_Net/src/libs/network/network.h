#pragma once

#include <iostream>

#ifndef WIN32
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

#define SOCKET int
#define INVALID_SOCKET -1
#define _sock_init( )
#define _sock_nonblock( sockfd ) { int flags = fcntl(sockfd, F_GETFL, 0); fcntl(sockfd, F_SETFL, flags | O_NONBLOCK); }
#define _sock_exit( )
#define _sock_err( )	errno
#define _sock_close( sockfd ) ::close( sockfd )
#define _sock_is_blocked()	(errno == EAGAIN || errno == 0)

#else
#include <Ws2tcpip.h>
#include <windows.h>

#define _sock_init( )	{ WSADATA wsaData; WSAStartup( MAKEWORD(2, 2), &wsaData ); }
#define _sock_nonblock( sockfd )	{ unsigned long param = 1; ioctlsocket(sockfd, FIONBIO, (unsigned long *)&param); }
#define _sock_exit( )	{ WSACleanup(); }
#define _sock_err( )	WSAGetLastError()
#define _sock_close( sockfd ) ::closesocket( sockfd )
#define _sock_is_blocked()	(WSAGetLastError() == WSAEWOULDBLOCK)

#endif

inline int GetListenBacklog( ) {

	int backlog = 10;
#ifndef WIN32
	char *ptr;
	if ( ( ptr = getenv( "LISTENQ" ) ) != nullptr )
		backlog = atoi( ptr );
#endif
	return backlog;
}