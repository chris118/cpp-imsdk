//
// Created by Chris on 2018/12/21.
//

#include "ObjectMapper.h"

using namespace imsdk;

imsdk::ErrorCode ObjectMapper::mapErrorCode(ChatPb::ErrorCode pbErrorCode)
{
    imsdk::ErrorCode errorCode;
    errorCode = (imsdk::ErrorCode)pbErrorCode;

    return errorCode;
}

imsdk::User ObjectMapper::mapUser(ChatPb::User pbUser)
{
    imsdk::User user;

    user.uid = pbUser.id();
    user.avatar = pbUser.avatar();
    user.birthday = pbUser.birthday();
    user.chatId = pbUser.chatid();
    user.gender = pbUser.gender();
    user.name = pbUser.name();
    user.remark = pbUser.remark();

    return user;
}

imsdk::AuthenticateRes ObjectMapper::mapAuthenticateRes(std::string dataString)
{
    imsdk::AuthenticateRes authenticateRES;
    ChatPb::AuthenticateRES pbAuthenticateRES;
    pbAuthenticateRES.ParseFromString(dataString);

    authenticateRES.message = pbAuthenticateRES.message();
    authenticateRES.authorized = pbAuthenticateRES.authorized();
    authenticateRES.code = mapErrorCode(pbAuthenticateRES.code());
    authenticateRES.user = mapUser(pbAuthenticateRES.user());

    return authenticateRES;
}

imsdk::ContactRes ObjectMapper::mapContactsRes(std::string dataString)
{
    imsdk::ContactRes contactRes;

    ChatPb::ContactRES pbContactRes;
    pbContactRes.ParseFromString(dataString);

    for(auto &pbUser : pbContactRes.users())
    {
        imsdk::User user = mapUser(pbUser);
        contactRes.users.push_back(user);
    }

    for(auto &pbDeleteUser : pbContactRes.deleteuserids())
    {
        contactRes.deleteUserIds.push_back(pbDeleteUser);
    }

    contactRes.timestamp = pbContactRes.timestamp();


    return contactRes;
}

imsdk::Message ObjectMapper::mapMessage(std::string dataString)
{
    imsdk::Message message;

    ChatPb::Message pbMessage;
    pbMessage.ParseFromString(dataString);

    message.chatId = pbMessage.chatid();
    message.fromUserId = pbMessage.fromuserid();
    message.messageId = pbMessage.messageid();
    message.message = pbMessage.message();

    return  message;
}

void ObjectMapper::mapUnReceivedMessage(ChatPb::UnreceivedMessage pbUnreceivedMessage, std::vector<imsdk::Message> &messages, int32_t &count)
{
    for(auto j = 0; j < pbUnreceivedMessage.msgs().size(); j++)
    {
        auto pbMessage = pbUnreceivedMessage.msgs()[j];
        Message message;
        message.chatId = pbMessage.chatid();
        message.fromUserId = pbMessage.fromuserid();
        message.messageId = pbMessage.messageid();
        message.message = pbMessage.message();
        messages.push_back(message);

        count++;
    }
}

imsdk::ApplyFriendREQ ObjectMapper::mapApplyFriendReq(std::string dataString)
{
    imsdk::ApplyFriendREQ req;
    ChatPb::ApplyFriendREQ pbApplyFriendReq;
    pbApplyFriendReq.ParseFromString(dataString);

    req.userId = pbApplyFriendReq.uid();
    req.message = pbApplyFriendReq.message();

    return req;
}

imsdk::ApplyFriendRES ObjectMapper::mapApplyFriendRes(std::string dataString)
{
    imsdk::ApplyFriendRES res;

    ChatPb::ApplyFriendRES pbApplyFriendRes;
    pbApplyFriendRes.ParseFromString(dataString);

    res.userId = pbApplyFriendRes.uid();
    res.bSuccess = pbApplyFriendRes.succeeded();

    return res;
}

imsdk::NotificationApplyFriend ObjectMapper::mapNotificationApplyFriend(std::string dataString)
{
    imsdk::NotificationApplyFriend res;

    ChatPb::NotificationApplyFriend pbNotificationApplyFriend;
    pbNotificationApplyFriend.ParseFromString(dataString);

    User user = mapUser(pbNotificationApplyFriend.user());
    res.user = user;
    res.message = pbNotificationApplyFriend.message();

    return res;
}

void ObjectMapper::mapSearchUserRes(std::string dataString, std::vector<imsdk::User> &users)
{
    ChatPb::SearchUserRES pbSearchUserRes;
    bool ret = pbSearchUserRes.ParseFromString(dataString);

    int count = pbSearchUserRes.users().size();

    std::cout << pbSearchUserRes.users().size() << std::endl;

    for(auto i = 0; i < count; i++)
    {
        auto pbUser = pbSearchUserRes.users()[i];
        User user = mapUser(pbUser);
        users.push_back(user);
    }
}
