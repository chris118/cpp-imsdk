#include <string>
#include <iostream>


#ifndef TOOL_H
#define TOOL_H

namespace imsdk
{
    void printBuffer(unsigned char* buff, int size, std::string tag = "");

    int randomInt(int scope);

    void intToByte(int i,char *bytes,int size = 4);

    int32_t bytesToInt32(char* bytes);

    int64_t bytesToInt64(char* bytes);
}



#endif //TOOL_H
