//
// Created by Chris on 2018/11/27.
//

#ifndef IMSDK_DEFINES_PRIVATE_H
#define IMSDK_DEFINES_PRIVATE_H

#include <string>
#include <vector>

namespace imsdk
{
    struct AuthenticateRes
    {
        bool authorized;
        User user;
        std::string message;
        ErrorCode code;
    };

    struct ContactRes
    {
        std::vector<imsdk::User> users;
        std::vector<std::string> deleteUserIds;
        long timestamp;
    };

    struct UnreceivedMessage
    {
        int32_t count; // 未读消息总数
        std::vector<Message> messages; //当前返回的未读消息
    };

    struct UnreceivedMessageReq
    {
        bool on;
    };

    struct UnreceivedMessageRes
    {
        std::vector<UnreceivedMessage> unreceivedMessages;
    };

    struct ApplyFriendREQ
    {
        std::string userId;
        std::string message;
    };

    struct ApplyFriendRES
    {
        std::string userId;
        bool bSuccess;
    };

    struct NotificationApplyFriend
    {
        User user;
        std::string message;
    };

    struct SendingMessage
    {
        long        sendTime;
        std::string chatId;
        std::string fromUserId;
        std::string messageId;
        std::string message;
        std::string localId;
    };
}

#endif //IMSDK_DEFINES_PRIVATE_H
