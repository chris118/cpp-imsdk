//
// Created by Chris on 2018/12/21.
//

#ifndef PRIVCHAT_OBJECTMAPPER_H
#define PRIVCHAT_OBJECTMAPPER_H

#include <vector>
#include "Defines.h"
#include "Defines-Private.h"
#include "proto/chat.user.pb.h"
#include "proto/chat.authenticate.pb.h"
#include "proto/chat.contacts.pb.h"
#include "proto/chat.message.pb.h"
#include "proto/chat.notification.pb.h"

class ObjectMapper
{
public:
    static imsdk::ErrorCode mapErrorCode(ChatPb::ErrorCode pbErrorCode);
    static imsdk::User mapUser(ChatPb::User pbUser);
    static imsdk::AuthenticateRes mapAuthenticateRes(std::string dataString);
    static imsdk::ContactRes mapContactsRes(std::string dataString);
    static imsdk::Message mapMessage(std::string dataString);
    static void mapUnReceivedMessage(ChatPb::UnreceivedMessage pbUnreceivedMessage, std::vector<imsdk::Message> &messages, int32_t &count);
    static imsdk::ApplyFriendREQ mapApplyFriendReq(std::string dataString);
    static imsdk::ApplyFriendRES mapApplyFriendRes(std::string dataString);
    static imsdk::NotificationApplyFriend mapNotificationApplyFriend(std::string dataString);
    static void mapSearchUserRes(std::string dataString, std::vector<imsdk::User> &users);
};


#endif //PRIVCHAT_OBJECTMAPPER_H
