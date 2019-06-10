//
// Created by Chris on 2018/11/29.
//
#include <string>
#include <iostream>

namespace imsdk
{
    void printBuffer(unsigned char* buff, int size, std::string tag){
        std::cout << tag << std::endl;
        for(int i = 0; i < size; i++){
            printf("%02x", buff[i]);
        }
        std::cout << std::endl << std::endl;
    }

    int randomInt(int scope)
    {
        srand((unsigned)time(NULL)); //用于保证是随机数
        return rand()%scope;  //用rand产生随机数并设定范围
    }

    void intToByte(int i,char *bytes,int size)
    {
        //byte[] bytes = new byte[4];
        memset(bytes,0,sizeof(char) *  size);
        bytes[0] = (char) (0xff & i);
        bytes[1] = (char) ((0xff00 & i) >> 8);
        bytes[2] = (char) ((0xff0000 & i) >> 16);
        bytes[3] = (char) ((0xff000000 & i) >> 24);
    }

    int32_t bytesToInt32(char* bytes)
    {
        return ((0xff & (int64_t)*(bytes+0)) << 0)
               | ((0xff & (int64_t)*(bytes+1)) << 8)
               | ((0xff & (int64_t)*(bytes+2)) << 16)
               | ((0xff & (int64_t)*(bytes+3)) << 24);
    }

    int64_t bytesToInt64(char* bytes)
    {
        return ((0xff & (int64_t)*(bytes+0)) << 0)
               | ((0xff & (int64_t)*(bytes+1)) << 8)
               | ((0xff & (int64_t)*(bytes+2)) << 16)
               | ((0xff & (int64_t)*(bytes+3)) << 24)
               | ((0xff & (int64_t)*(bytes+4)) << 32)
               | ((0xff & (int64_t)*(bytes+5)) << 40)
               | ((0xff & (int64_t)*(bytes+6)) << 48)
               | ((0xff & (int64_t)*(bytes+7)) << 56);
    }
}


