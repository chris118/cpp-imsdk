//
// Created by Chris on 2018/11/28.
//

#ifndef IMSDK_MESSAGE_H
#define IMSDK_MESSAGE_H

#include <string>
#include <memory>

#define MAX_NETPACK_SIZE	10000
#define HEADER_LENGTH		20

namespace imsdk
{
    struct Packet
    {
        int64_t auth_key_id;
        int64_t message_id;
        int32_t message_data_length;
        char    *message_data;
    };

    class PacketSerizlizer
    {
    public:
        PacketSerizlizer();
        /**
          * @brief 序列化message为有效的发送格式buffer
          * @param message   报文数据
          * @param length    序列化后buffer
          *
          * @return
          *  序列化后buffer size
          */
        int64_t Serialize(Packet &message, std::shared_ptr<char> &serizelizeBuffer);

        /**
          * @brief 反序列化message
          * @param data         报文数据
          * @param data_size    数据长度
          * @param messages     反序列化后Message
          *
          * @return 成功 or 失败
          */
        bool DeSerialize(const char* data, int data_size, std::vector<Packet> &messages);

    private:
        char m_last_save_data[MAX_NETPACK_SIZE];
        int  m_remain_size; // 当前数据的大小
    };
}
#endif //IMSDK_MESSAGE_H

