#include <list>
#include <memory>
#include "client_socket.h"


int main(int argc, char *argv[]) {
    std::list<std::shared_ptr<ClientSocket>> client_sockets;

    for (int index = 0; index < 3; index++) {
        client_sockets.push_back(std::make_shared<ClientSocket>(index));
    }

    while (!client_sockets.empty()) {
        auto iter = client_sockets.begin();
        while (iter != client_sockets.end()) {
            auto pClient = (*iter);
            if ((*pClient).IsRun())
            {
               ++iter;
               continue; 
            }
            
            pClient->Stop();
            iter = client_sockets.erase(iter);
        }
    }

    return 0;
}