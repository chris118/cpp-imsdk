//
// Created by Chris on 2018/10/30.
//

#ifndef IMSDK_CONNECTOR_H
#define IMSDK_CONNECTOR_H

#include <functional>
#include "handy/handy.h"
#include "Client.h"

namespace imsdk
{
    class Tcp
    {
    public:
        Tcp();

        void connect(std::string ip, int port);
        void sendMessage(std::string msg);
        void sendMessage(const void* d, size_t dlen);

        std::function<void(bool)> onConnect;
        std::function<void(unsigned char* data, int32_t length)> onMessage;

    private:
        handy::TcpConnPtr m_connection;
    };

}


#endif //IMSDK_CONNECTOR_H
