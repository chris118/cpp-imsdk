//
// Created by Chris on 2018/11/27.
//

#ifndef IMSDK_DEFINES_H
#define IMSDK_DEFINES_H

#include <string>
#include <vector>

namespace imsdk
{
    enum ErrorCode
    {
        SUCCESS    =	0
    };

    enum Command
    {
        CMD_ZERO					=	0,
        CMD_AUTHORIZE_REQ			=	101,
        CMD_AUTHORIZE_RES			=	102,
        CMD_CONTACTS_REQ			=	103,
        CMD_CONTACTS_RES			=	104,
        CMD_UNRECEIVE_REQ			=	105,
        CMD_UNRECEIVE_RES			=	106,
        CMD_MESSAGE_TRANSFER		=	118,
        CMD_MESSAGE_ACK             =	110
    };

    struct User
    {
        std::string uid;         //用户唯一id
        std::string chatId;     //添加好友时产生chatId
        std::string name;       //用户昵称
        std::string remark;     // 设置的备注
        std::string avatar;     // url
        std::string gender;     // 1: male 2: female 3: unknow
        std::string birthday;   // formate: 20010101
    };

    struct Message
    {
        std::string chatId;
        std::string fromUserId;
        std::string messageId;
        std::string message;
    };
}

#endif //IMSDK_PACKET_H
