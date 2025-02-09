#pragma once

#include <iostream>

#ifndef WIN32
#include <errno.h>
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
#define _sock_init()
#define _sock_exit()
#define _sock_err() errno
#define _sock_close(sockfd)::close(sockfd)

#else
#include <Ws2tcpip.h>
#include <windows.h>
#endif

inline int GetListenBacklog() {
    int backlog = 10;
#ifdef _WIN32
    char* ptr;
    if ((ptr = getenv("LISTENQUEUE")) != nullptr)  
    {
        backlog = atoi(ptr);
    }
    
#endif
    return backlog;
}
