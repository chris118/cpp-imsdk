//
// Created by Chris on 2018/7/30.
//

#ifndef IMSDK_CLIENT_H
#define IMSDK_CLIENT_H

#include <string>
#include <vector>
#include "Defines.h"

namespace imsdk
{
    class ClientDelegate
    {
    public:
        virtual void onGetServer(std::string address, int port) = 0;
        virtual void onConnect(bool bSuccess) = 0;
        virtual void onStatus(Status status) = 0;
        virtual void onAuthenticate(bool authorized, User user, std::string message, int code) = 0;
        virtual void onContacts(std::vector<User> users, std::vector<std::string> deletedUserIds, long timestamp ) = 0;
        virtual void onMessage(Message message, bool bSuccess) = 0;
        virtual void onUnrecievedMessage(std::vector<Message> unreceivedMessages, int32_t total) = 0;
        virtual void onSearchFriend(std::vector<User> users) = 0;
        virtual void onApplyFriend(std::string userId, bool bSuccess) = 0;
        virtual void onAgreeFriend(std::string chatId, std::string message) = 0;
        virtual void onApplyFriendNotification(User user, std::string message) = 0;
        virtual void onDeleteFriend(std::string uid, bool bSuccess, std::string message) = 0;

    };

    class Client
    {
    public:
        virtual void getServer(std::string openId) = 0;
        virtual void connect(std::string ip, int port) = 0;
        virtual void authenticate(std::string openId, std::string accessToken, std::string appid) = 0;
        virtual void updateContacts(long timestamp) = 0;
        virtual void openReceivedMessage(bool on) = 0;
        virtual void sendTextMessage(Message message) = 0;
        virtual void searchFriend(std::string keyword) = 0;
        virtual void applyFriend(std::string uid, std::string message) = 0;
        virtual void agreeFriend(std::string uid) = 0;
        virtual void deleteFriend(std::string uid) = 0;

        virtual void ping() = 0;

    };

}

imsdk::Client *ClientCreate(imsdk::ClientDelegate *delegate);

void PCClientApi_Destroy(imsdk::Client *client);


#endif //IMSDK_CLIENT_H
