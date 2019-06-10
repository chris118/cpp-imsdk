//
// Created by Chris on 2018/7/30.
//

#include "ClientImpl.h"

static imsdk::Client *clientApi = NULL;

imsdk::Client *ClientCreate(imsdk::ClientDelegate *delegate)
{
    clientApi = new imsdk::ClientImpl(delegate);
    return clientApi;
}

void PCClientApi_Destroy(imsdk::Client *client)
{
    if (client)
    {
        delete (imsdk::ClientImpl *) client;
    }
}