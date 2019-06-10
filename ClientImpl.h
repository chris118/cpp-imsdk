//
// Created by Chris on 2018/7/30.
//

#ifndef IMSDK_CLIENTIMPL_H
#define IMSDK_CLIENTIMPL_H

#include <queue>

#include "Client.h"
#include "Tcp.h"
#include "Packet.h"
#include "Tool.h"
#include "Timer.h"
#include "ObjectMapper.h"

namespace imsdk
{

    class ClientImpl : public Client
    {
    public:

        ClientImpl(ClientDelegate *delegate);

        ~ClientImpl();

    public:
        void getServer(std::string openId);

        void connect(std::string ip, int port);

        void authenticate(std::string openId, std::string accessToken, std::string appid);

        void updateContacts(long timestamp);

        void sendTextMessage(Message message);

        void openReceivedMessage(bool on);

        void applyFriend(std::string uid, std::string message);

        void searchFriend(std::string keyword);

        void agreeFriend(std::string uid);

        void deleteFriend(std::string uid);

        void ping();

    private:
        void updateStatus(Status status);

        void dispatchMessage(Packet message);

        void sendMessage(ChatPb::CMD cmd, std::string msgBuff);

        void sendMessageACK(Message message);

        void sendingMessageCheck();

        void removeMessageFromSendingQueue(Message message);

    private:
        ClientDelegate              *m_delegate;
        std::shared_ptr<Tcp>        m_connector;
        PacketSerizlizer            m_message_serizlizer;
        std::string                 m_me_id;
        Status                      m_status;
        int                         m_retry_count;
        std::queue<SendingMessage>  m_sending_message_queue;
        Timer                       m_check_timer;
    };
}

#endif //IMSDK_CLIENTIMPL_H
