//
// Created by Chris on 2018/11/29.
//

#include <vector>
#include "Packet.h"
#include "Tool.h"

namespace imsdk
{
    PacketSerizlizer::PacketSerizlizer()
    {
        memset(m_last_save_data, 0, MAX_NETPACK_SIZE);
        m_remain_size = 0;
    }

    int64_t PacketSerizlizer::Serialize(Packet &message, std::shared_ptr<char> &serizelizeBuffer)
    {
        int64_t length = sizeof(message.auth_key_id)
                 + sizeof(message.message_id)
                 + sizeof(message.message_data_length)
                 + message.message_data_length;

        auto buffer = std::shared_ptr<char>(new char[length]);

        int offset = 0;
        memset(buffer.get(), 0, length);

        // 小端转大端
        int64_t auth_key_id_bigendian = __builtin_bswap64(message.auth_key_id);
        memcpy(buffer.get(), &auth_key_id_bigendian,  sizeof(auth_key_id_bigendian));
        offset +=  sizeof(auth_key_id_bigendian);

        int64_t message_id_bigendian = __builtin_bswap64(message.message_id);
        memcpy(buffer.get() + offset, &message_id_bigendian,  sizeof(message_id_bigendian));
        offset += sizeof(message_id_bigendian);

        int32_t message_data_length_bigendian = __builtin_bswap32(message.message_data_length);
        memcpy(buffer.get() + offset, &message_data_length_bigendian, sizeof(message_data_length_bigendian));
        offset += sizeof(message_data_length_bigendian);

        memcpy(buffer.get() + offset, message.message_data, message.message_data_length);

        serizelizeBuffer = buffer;

        return length;
    }

    bool PacketSerizlizer::DeSerialize(const char* data, int data_size, std::vector<Packet> &messages)
    {
//        std::cout << "data_size: " << data_size;
//        printBuffer((char *) data, data_size);


        /* 本次接收到的数据拼接到上次数据 */
        memcpy( (char*)(m_last_save_data) + m_remain_size, data, data_size );
        m_remain_size += data_size;

        while(true)
        {
            int offset = 0;
            if ( m_remain_size >= HEADER_LENGTH)
            {
                //取出包头
                char auth_key_id[8];
                memset(auth_key_id, 0, 8);
                memcpy(auth_key_id, m_last_save_data + offset, 8);
                int64_t n_auth_key_id = __builtin_bswap64(bytesToInt64(auth_key_id));
                offset += 8;

                char message_id[8];
                memset(message_id, 8, 0);
                memcpy(message_id, m_last_save_data + offset, 8);
                int64_t n_message_id = __builtin_bswap64(bytesToInt64(message_id));
                offset += 8;

                char message_data_length[4];
                memset(message_data_length, 0, 4);
                memcpy(message_data_length, m_last_save_data + offset, 4);
                int64_t n_message_data_length = __builtin_bswap32(bytesToInt32(message_data_length));
                offset += 4;

//                printBuffer(auth_key_id, 8);
//                printBuffer(message_id, 8);
//                printBuffer(message_data_length, 4);

//                std::cout << "n_auth_key_id: " << n_auth_key_id << std::endl;
                std::cout << "n_message_id: " << n_message_id << std::endl;
//                std::cout << "n_message_data_length: " << n_message_data_length << std::endl;

                /* 够一个数据包的长度 */
                if (m_remain_size >= n_message_data_length + HEADER_LENGTH )
                {
                    char message_data[n_message_data_length];
                    memset(message_data, 0, n_message_data_length);
                    memcpy(message_data, m_last_save_data + offset, n_message_data_length);
                    offset += n_message_data_length;

                    Packet msg;
                    msg.auth_key_id = n_auth_key_id;
                    msg.message_id = n_message_id;
                    msg.message_data_length = n_message_data_length;
                    msg.message_data = message_data;
                    messages.push_back(msg);

                    //取完一个完整的数据包后，整包数据从m_last_save_data移除
                    m_remain_size = m_remain_size -  n_message_data_length - HEADER_LENGTH;
                    if(m_remain_size > 0)
                    {
                        char left[m_remain_size];
                        memset(left, 0, m_remain_size);
                        memcpy(left, m_last_save_data + offset, m_remain_size);

                        memset(m_last_save_data, 0, MAX_NETPACK_SIZE);
                        memcpy(m_last_save_data, left, m_remain_size);
                    }
                    else
                    {
                        //正好是一个完整包
                        memset(m_last_save_data, 0, MAX_NETPACK_SIZE);
//                        break;
                    }
                }
                else
                {
                    /* 不够一个数据包的长度 等下一个包 */
                    break;

                }
            }
            else
            {
                /* 不够一个数据包头的长度 等下一个包 */
                break;
            }

        }
        return true;
    }
}
