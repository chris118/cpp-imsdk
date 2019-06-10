//
// Created by Chris on 2018/10/30.
//

#include <thread>
#include <iostream>
#include "Tcp.h"

using namespace imsdk;

Tcp::Tcp()
{

}

void Tcp::sendMessage(std::string msg)
{
    m_connection->send(msg);
}

void Tcp::sendMessage(const void* buff, size_t length)
{
    m_connection->send((char*)buff, length);
}

void Tcp::connect(std::string ip, int port)
{
    std::thread t([ip, port, this]()
                  {
                      handy::EventBase base;
                      m_connection =handy::TcpConn::createConnection(&base, ip, port);
                      m_connection->setReconnectInterval(3000);
                      m_connection->onState([&](const handy::TcpConnPtr& conn) {
                            assert(conn);
                            assert(onConnect);
                            if (conn->getState() == handy::TcpConn::State::Connected)
                            {
                               onConnect(true);
                               std::cout << "已连接" << std::endl;
                            }
                            else
                            {
                               onConnect(false);
                               std::cout << "断开连接" << std::endl;
//
//                               //断开链接 销毁loop
//                               std::cout << "链接断开" << std::endl;
//                               base.exit();
                            }
                      });
                      m_connection->onRead([=](const handy::TcpConnPtr& conn){

                          onMessage((unsigned char*)conn->getInput().data(), conn->getInput().size());
                          conn->getInput().clear();
                      });

                      base.loop();
                  });
    t.detach();
}