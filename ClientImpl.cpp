//
// Created by Chris on 2018/7/30.
//

#include "ClientImpl.h"
#include <vector>
#include "proto/chat.contacts.pb.h"
#include "proto/chat.message.pb.h"


using namespace imsdk;

ClientImpl::ClientImpl(ClientDelegate *delegate)
{
    assert(delegate);

    m_delegate = delegate;
    m_connector = std::make_shared<Tcp>();
    m_retry_count = 0;

    m_connector->onConnect = [&](bool bSuccess)
    {
        m_delegate->onConnect(bSuccess);

        if(!bSuccess)
        {
            // 每隔3秒重试连接一次，15秒还没连接CONNECTING状态, 30秒还未连接DISCONNECT状态
            m_retry_count++;
            if(m_retry_count == 5)
            {
                updateStatus(CONNECTING);
            }
            if(m_retry_count == 10)
            {
                updateStatus(DISCONNECT);
            }
        }
        else
        {
            updateStatus(CONNECTED);
            m_retry_count = 0;
        }
    };

    m_connector->onMessage = [&](unsigned char *msg, int32_t length)
    {
        std::vector<Packet> packages;
        bool ret = m_message_serizlizer.DeSerialize((char*)msg, length, packages);
        if(!ret)
        {
            std::cout << "failed to deSerialize net buffer";
        }

        for(int i =0; i < packages.size(); i++)
        {
            dispatchMessage(packages[i]);
        }
    };

    sendingMessageCheck();
}

ClientImpl::~ClientImpl()
{
}

void ClientImpl::dispatchMessage(Packet package)
{
    std::string data = std::string(package.message_data, package.message_data_length);
    switch(package.message_id)
    {
        case ChatPb::CMD::CMD_PONG:
        {
            std::cout << "pong" << std::endl;
        }
            break;
        case ChatPb::CMD::CMD_AUTHORIZE_RES:
        {
            AuthenticateRes mapAuthenticateRes = ObjectMapper::mapAuthenticateRes(data);

            m_delegate->onAuthenticate(mapAuthenticateRes.authorized,
                                       mapAuthenticateRes.user,
                                       mapAuthenticateRes.message,
                                       mapAuthenticateRes.code);

            m_me_id = mapAuthenticateRes.user.uid;
        }
            break;
        case ChatPb::CMD::CMD_CONTACTS_RES:
        {
            ContactRes contactRes = ObjectMapper::mapContactsRes(data);
            m_delegate->onContacts(contactRes.users, contactRes.deleteUserIds, contactRes.timestamp);
        }
            break;
        case ChatPb::CMD::CMD_MESSAGE_TRANSFER:
        {
            Message message = ObjectMapper::mapMessage(data);
            m_delegate->onMessage(message, true);

            //从sending_message_queue中移除
            removeMessageFromSendingQueue(message);

            //回复ACK给服务端
            sendMessageACK(message);
        }
            break;
        case ChatPb::CMD::CMD_UNRECEIVE_RES:
        {
            //获取未读消息后， 取消息最后一条，回复ACK给服务端
            ChatPb::UnreceivedMessageRES unreceivedMessageRes;
            unreceivedMessageRes.ParseFromString(data);
            auto pbUnreceivedMessages = unreceivedMessageRes.unreceivedmessages();
            for(auto i = 0; i < pbUnreceivedMessages.size(); i++)
            {
                std::vector<Message> messages;
                int32_t count = 0;
                ObjectMapper::mapUnReceivedMessage(pbUnreceivedMessages[i], messages, count);
                m_delegate->onUnrecievedMessage(messages, count);

                if(i == pbUnreceivedMessages.size() - 1)
                {
                    //回复未读消息收取完的ACK
                    auto lastMessage = messages[i];
                    sendMessageACK(lastMessage);
                }
            }
        }
            break;
        case ChatPb::CMD::CMD_APPLY_FRIEND_RES:
        {
            imsdk::ApplyFriendRES applyFriendRES = ObjectMapper::mapApplyFriendRes(data);
            m_delegate->onApplyFriend(applyFriendRES.userId, applyFriendRES.bSuccess);
        }
            break;
        case ChatPb::CMD::CMD_SEARCH_USER_RES:
        {
            std::vector<User> users;
            ObjectMapper::mapSearchUserRes(data, users);
            m_delegate->onSearchFriend(users);
        }
            break;
        case ChatPb::CMD::CMD_NOTIFY_TRANSFER:
        {
            ChatPb::NotificationTransfer notificationTransfer;
            notificationTransfer.ParseFromString(data);
            auto pbNotifications = notificationTransfer.notifications();

            //获取通知， 取通知最后一条，回复ACK给服务端
            for(auto i = 0; i < pbNotifications.size(); i++)
            {
                ChatPb::Notification pbNotification = pbNotifications[i];
                switch(pbNotification.type()){
                    case ChatPb::NotificationType::APPLY_FRIEND :

                        imsdk::NotificationApplyFriend applyFriend = ObjectMapper::mapNotificationApplyFriend(pbNotification.data());
                        m_delegate->onApplyFriendNotification(applyFriend.user, applyFriend.message);
                        break;
                }

                if(i == pbNotifications.size() - 1)
                {
                    //回复通知收取完的ACK
                    ChatPb::NotificationAck notificationAck;
                    notificationAck.set_msgid(pbNotification.msgid());
                    std::string msgBuff;
                    notificationAck.SerializeToString(&msgBuff);
                    sendMessage(ChatPb::CMD::CMD_NOTIFY_ACK, msgBuff);
                }
            }
        }
            break;
        case ChatPb::CMD::CMD_AGREE_FRIEND_RES:
        {
            ChatPb::AgreeFriendRES pbAgreeFriendRES;
            pbAgreeFriendRES.ParseFromString(data);
            m_delegate->onAgreeFriend(pbAgreeFriendRES.chatid(), pbAgreeFriendRES.message());
        }
            break;
        case ChatPb::CMD::CMD_DELETE_FRIEND_RES:
        {
            ChatPb::DeleteFriendRES pbDeleteFriendRES;
            pbDeleteFriendRES.ParseFromString(data);
            m_delegate->onDeleteFriend(pbDeleteFriendRES.uid(), pbDeleteFriendRES.succeeded(), pbDeleteFriendRES.message());
        }
            break;
        default:
            break;
    }
}

void ClientImpl::getServer(std::string openId)
{
//    m_delegate->onGetServer("10.1.11.34", 3003);
    m_delegate->onGetServer("chat.putao.com", 3003);
}

void ClientImpl::connect(std::string ip, int port)
{
    m_connector->connect(ip, port);
}

void ClientImpl::updateStatus(Status status)
{
    m_status = status;
    m_delegate->onStatus(status);
}

void ClientImpl::ping()
{
    sendMessage(ChatPb::CMD::CMD_PING, "");
}

void ClientImpl::authenticate(std::string openId, std::string accessToken, std::string appId)
{
    ChatPb::AuthenticateREQ quthenticateREQ;
    quthenticateREQ.set_appid(appId);
    quthenticateREQ.set_accesstoken(accessToken);
    quthenticateREQ.set_openid(openId);
    std::string msgBuff;
    quthenticateREQ.SerializeToString(&msgBuff);

    sendMessage(ChatPb::CMD::CMD_AUTHORIZE_REQ, msgBuff);
}

void ClientImpl::updateContacts(long timestamp)
{
    ChatPb::ContactREQ contactREQ;
    contactREQ.set_timestamp(timestamp);
    std::string msgBuff;
    contactREQ.SerializeToString(&msgBuff);

    sendMessage(ChatPb::CMD::CMD_CONTACTS_REQ, msgBuff);
}

void ClientImpl::sendTextMessage(Message message)
{
    SendingMessage sendingMessage;
    sendingMessage.sendTime = time(0);
    sendingMessage.chatId = message.chatId;
    sendingMessage.fromUserId = message.fromUserId;
    sendingMessage.messageId = message.messageId;
    sendingMessage.message = message.message;
    sendingMessage.localId = message.localId;
    m_sending_message_queue.push(sendingMessage);

    ChatPb::Message pbMessage;
    pbMessage.set_chatid(message.chatId);
    pbMessage.set_message(message.message);
    pbMessage.set_fromuserid(m_me_id);
    pbMessage.set_localid(message.localId);

    std::string msgBuff;
    pbMessage.SerializeToString(&msgBuff);
//    sendMessage(ChatPb::CMD::CMD_MESSAGE_TRANSFER, msgBuff);
}

void ClientImpl::openReceivedMessage(bool on)
{
    ChatPb::openReceivedMessageREQ openReceivedMessageREQ;
    openReceivedMessageREQ.set_on(on);
    std::string msgBuff;
    openReceivedMessageREQ.SerializeToString(&msgBuff);
    sendMessage(ChatPb::CMD::CMD_UNRECEIVE_REQ, msgBuff);
}

void ClientImpl::applyFriend(std::string uid, std::string message)
{
    ChatPb::ApplyFriendREQ pbApplyFriendReq;
    pbApplyFriendReq.set_uid(uid);
    pbApplyFriendReq.set_message(message);

    std::string msgBuff;
    pbApplyFriendReq.SerializeToString(&msgBuff);

    sendMessage(ChatPb::CMD::CMD_APPLY_FRIEND_REQ, msgBuff);
}

void ClientImpl::searchFriend(std::string keyword)
{
    ChatPb::SearchUserREQ pbSearchUserReq;
    pbSearchUserReq.set_key(keyword);

    std::string msgBuff;
    pbSearchUserReq.SerializeToString(&msgBuff);

    sendMessage(ChatPb::CMD::CMD_SEARCH_USER_REQ, msgBuff);
}

void ClientImpl::agreeFriend(std::string uid)
{
    ChatPb::AgreeFriendREQ pbAgreeFriendReq;
    pbAgreeFriendReq.set_uid(uid);

    std::string msgBuff;
    pbAgreeFriendReq.SerializeToString(&msgBuff);

    sendMessage(ChatPb::CMD::CMD_AGREE_FRIEND_REQ, msgBuff);
}

void ClientImpl::deleteFriend(std::string uid)
{
    ChatPb::DeleteFriendREQ pbDeleteFriendReq;
    pbDeleteFriendReq.set_uid(uid);

    std::string msgBuff;
    pbDeleteFriendReq.SerializeToString(&msgBuff);

    sendMessage(ChatPb::CMD::CMD_DELETE_FRIEND_REQ, msgBuff);
}

//---------------private---------------

void ClientImpl::sendMessage(ChatPb::CMD cmd, std::string msgBuff)
{
    Packet message;
    message.auth_key_id = 0;
    message.message_id = cmd;
    message.message_data_length = msgBuff.length();
    message.message_data = (char*)msgBuff.c_str();

    std::shared_ptr<char> packet_buff;
    int64_t packet_length = m_message_serizlizer.Serialize(message, packet_buff);
    m_connector->sendMessage(packet_buff.get(), packet_length);
}

void ClientImpl::sendMessageACK(Message message)
{
    //收到消息回 ACK
    ChatPb::MsgAck msgAck;
    msgAck.set_chatid(message.chatId);
    msgAck.set_fromuserid(m_me_id);
    std::string msgBuff;
    msgAck.SerializeToString(&msgBuff);
    sendMessage(ChatPb::CMD::CMD_MESSAGE_ACK, msgBuff);
}

void ClientImpl::sendingMessageCheck()
{
    m_check_timer.setInterval([&]() {
        std::cout << "sending message check " << time(0) << std::endl;

        std::queue<SendingMessage>  temp_queue;
        while(!m_sending_message_queue.empty()){
            long current = time(0);
            SendingMessage msg = m_sending_message_queue.front();
            if((current - msg.sendTime) >= 10 ) //10秒还未发送成功
            {
                //发送失败
                Message message;
                message.chatId = msg.chatId;
                message.message = msg.message;
                message.localId = msg.localId;
                m_delegate->onMessage(message, false);
            }
            else
            {
                temp_queue.push(msg); //还在等待中的
            }

            m_sending_message_queue.pop();
        }

        m_sending_message_queue = temp_queue;
    }, 5000);
}

void ClientImpl::removeMessageFromSendingQueue(Message message)
{
    std::queue<SendingMessage>  temp_queue;
    while(!m_sending_message_queue.empty()){
        long current = time(0);
        SendingMessage msg = m_sending_message_queue.front();
        if(message.localId != msg.localId)
        {
            temp_queue.push(msg);
        }

        m_sending_message_queue.pop();
    }

    m_sending_message_queue = temp_queue;
}