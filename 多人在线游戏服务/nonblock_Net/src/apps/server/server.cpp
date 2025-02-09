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
    return 0;
}