#include <iostream>

#include "network/network.h"

int main(int argc, char* argv[]) {

    _sock_init();
    SOCKET socket = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (socket == INVALID_SOCKET) {
        std::cout << "::socket failed. err:" << _sock_err() << std::endl;
        return 1;
    }

    sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(2233);
    ::inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr.s_addr);

    if (::connect(socket, (struct sockaddr *)&addr, sizeof(sockaddr)) < 0) {
        std::cout << "::connect failed. err:" << _sock_err() << std::endl;
        return 1;
    }

    std::string msg = "ping";
    ::send(socket, msg.c_str(),msg.length(), 0);

    std::cout << "send msg:" << msg.c_str() << std::endl;

    char buf[1024];
    memset(&buf, 0, sizeof(buf));
    int ret = ::recv(socket, buf, sizeof(buf), 0);
    if (ret > 0) {
        std::cout << "recv msg:" << buf << std::endl;
    }

    _sock_close(socket);
    _sock_exit();

    return 0;
}   