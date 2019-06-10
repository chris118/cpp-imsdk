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
        SUCCESS = 0
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

    enum Status
    {
        DISCONNECT = 0,
        CONNECTING = 1,
        CONNECTED = 2
    };

    struct Message
    {
        std::string chatId;
        std::string fromUserId;
        std::string messageId;
        std::string message;
        std::string localId;
    };
}

#endif //IMSDK_PACKET_H
