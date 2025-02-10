#include "network.h"

#include "buffer/connect_obj.h"

#include <iostream>

void Network::Dispose() {
    auto iter = _connects.begin();
    while (iter != _connects.end()) {
        iter->second->Dispose();
        delete iter->second;
        ++iter;
    }

    _connects.clear();
    _sock_close(_masterSocket);
    _masterSocket = -1;
}

#define SetsockOptType void *

void Network::SetSocketOpt(SOCKET socket) {
    // 1. 端口关闭后马上重新启用
    bool isReuseaddr = true;
    setsockopt(socket, SOL_SOCKET, SO_REUSEADDR, (SetsockOptType)&isReuseaddr, sizeof(isReuseaddr));

    // 2.发送、接收timeout 3s
    int netTimeout = 3000;
    setsockopt(socket, SOL_SOCKET, SO_RCVTIMEO, (SetsockOptType)&netTimeout, sizeof(netTimeout));
    setsockopt(socket, SOL_SOCKET, SO_SNDTIMEO, (SetsockOptType)&netTimeout, sizeof(netTimeout));

    int keepAlive = 1;
    socklen_t optlen = sizeof(keepAlive);

    int keepIdle = 60 * 2;    // 在socket 没有交互后 多久 开始发送侦测包
    int keepInterval = 10;    // 发送侦测包的时间间隔
    int keepCount = 5;        // 侦测包个数

    setsockopt(socket, SOL_SOCKET, SO_KEEPALIVE, (SetsockOptType)&keepAlive, optlen);
    if (getsockopt(socket, SOL_SOCKET, SO_KEEPALIVE, &keepAlive, &optlen) < 0) {
        std::cout << "getsockopt SO_KEEPALIVE failed." << std::endl;
    }

    setsockopt(socket, SOL_TCP, TCP_KEEPIDLE, (void *)&keepIdle, optlen);
    if (getsockopt(socket, SOL_TCP, TCP_KEEPIDLE, &keepIdle, &optlen) < 0) {
        std::cout << "getsockopt TCP_KEEPIDLE failed." << std::endl;
    }

    setsockopt(socket, SOL_TCP, TCP_KEEPINTVL, (void *)&keepInterval, optlen);
	setsockopt(socket, SOL_TCP, TCP_KEEPCNT, (void *)&keepCount, optlen);

    _sock_nonblock(socket);
}

SOCKET Network::CreateSocket() {
    _sock_init();

    SOCKET socket = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (socket == INVALID_SOCKET) {
        std::cout << "::socket failed. err:" << _sock_err() << std::endl;
        return socket;
    }

    SetSocketOpt(socket);
    return socket;
}

bool Network::Select()
{
    FD_ZERO(&readfds);
    FD_ZERO(&writefds);
    FD_ZERO(&exceptfds);

    FD_SET(_masterSocket, &readfds);
    FD_SET(_masterSocket, &writefds);
    FD_SET(_masterSocket, &exceptfds);

    SOCKET fdmax = _masterSocket;
    for (auto iter = _connects.begin(); iter != _connects.end(); ++iter) {
        
    }
}