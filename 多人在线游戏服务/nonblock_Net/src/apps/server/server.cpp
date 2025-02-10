#include <iostream>

#include "network/network.h"
#include <list>

int main(int argc, char *argv[]) {

    _sock_init();
    SOCKET socket = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (socket == INVALID_SOCKET) {
        std::cout << "socket error: " << _sock_err() << std::endl;
        return -1;
    }

    _sock_nonblock(socket);

    sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(2233);
    ::inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr.s_addr);

    if (::bind(socket, reinterpret_cast<sockaddr*>(&addr),sizeof(addr)) < 0)
    {
        std::cout << "bind failed error: " << _sock_err() << std::endl;
        return 1;
    }
    
    int backlog = GetListenBacklog();
    if (::listen(socket, backlog) < 0)
    {
        std::cout << "listen failed error: " << _sock_err() << std::endl;
        return 1;
    }

    char buf[1024];
    memset(buf, 0, sizeof(buf));

    std::list<SOCKET> clients;

    struct sockaddr socketClient;
    socklen_t len = sizeof(socketClient);

    while (true) {
        SOCKET clientSocket = ::accept(socket, &socketClient, &len);
        if (clientSocket != INVALID_SOCKET) {
            std::cout << "new connection.socket:" << clientSocket << std::endl;
            _sock_nonblock(clientSocket);
            clients.push_back(clientSocket);
        }

        auto iter = clients.begin();
        while (iter != clients.end()) {
            SOCKET one = *iter;
            auto size = ::recv(one, buf, sizeof(buf), 0);
            if (size > 0) {
                std::cout << "recv:" << buf << " from socket:" << one << std::endl;
                ::send(one, buf, size, 0);
                std::cout << "send:" << buf << " to socket:" << one << std::endl;

                _sock_close(one);
                iter = clients.erase(iter);
            } else {
                ++iter;
            }
        }
    }

    return 0;
}